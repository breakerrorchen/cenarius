
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::arc_to(js_parameter& parameter) {
	assert(transmitter_ && related_);
	if (parameter.get_argument_count() < 5) return;
	float ax, ay, bx, by, r;
	ax = parameter.get_argument_at(0).to_float();
	ay = parameter.get_argument_at(1).to_float();
	bx = parameter.get_argument_at(2).to_float();
	by = parameter.get_argument_at(3).to_float();
	 r = parameter.get_argument_at(4).to_float();
	auto& context = related_->lt_context_stack_.top();
	auto& _martix = context.current_matrix_;
	if ((ax == bx && ay == by) || 0 == r) {
		SkPoint pt; _martix.mapXY(ax, ay, &pt);
		auto& current_path = related_->lt_current_path_;
		if (current_path.isEmpty()) {
			current_path.moveTo(pt.x(), pt.y());
		} else {
			current_path.lineTo(pt.x(), pt.y());
		}

		struct __task__ {
			render_context_thread_related* related_ = nullptr;
        	SkPoint pt_;
        	void run(barrel_buffer*) {
				assert(related_);
				auto& path = related_->rt_current_path_;
				if (path.isEmpty()) {
					path.moveTo(pt_.x(), pt_.y());
				} else {
					path.lineTo(pt_.x(), pt_.y());
				}
			}
		};
		auto task = transmitter_->alloc<__task__>();
    	assert(nullptr != task);
		if (task) { 
        	task->pt_ = pt; task->related_ = related_.get();
    	}
	} else {
		SkPoint pt_a, pt_b;
		_martix.mapXY(ax, ay, &pt_a);
		_martix.mapXY(bx, by, &pt_b);
		auto& current_path = related_->lt_current_path_;
		current_path.arcTo(
			pt_a.x(), pt_a.y(), pt_b.x(), pt_b.y(), r);

		struct __task__ {
			render_context_thread_related* related_ = nullptr;
        	SkPoint pt_a_, pt_b_; float r_ = 0;
			void run(barrel_buffer*) {
				assert(related_);
				auto& path = related_->rt_current_path_;
				path.arcTo(pt_a_.x(), 
					pt_a_.y(), pt_b_.x(), pt_b_.y(), r_);
			}
		};
		auto task = transmitter_->alloc<__task__>();
    	assert(nullptr != task);
		if (task) { 
        	task->pt_a_ = pt_a; 
			task->pt_b_ = pt_b; 
			task->r_    = r; 
			task->related_ = related_.get();
    	}
	}
}