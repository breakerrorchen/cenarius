
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::quadratic_curve_to(js_parameter& parameter) {
    assert(transmitter_ && related_);
	if (parameter.get_argument_count() != 4) return;
    auto ax = parameter.get_argument_at(0).to_float();
    auto ay = parameter.get_argument_at(1).to_float();
    auto bx = parameter.get_argument_at(2).to_float();
    auto by = parameter.get_argument_at(3).to_float();
    auto& martix = related_->get_lt_context().current_matrix_;
    SkPoint pt_a, pt_b;
    martix.mapXY(ax, ay, &pt_a); martix.mapXY(bx, by, &pt_b);
    related_->lt_current_path_
        .quadTo(pt_a.x(), pt_a.y(), pt_b.x(), pt_b.y());
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPoint pt_a_, pt_b_;
        void run(barrel_buffer*) {
            assert(related_);
            related_->rt_current_path_.quadTo(
                pt_a_.x(), pt_a_.y(), pt_b_.x(), pt_b_.y());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->pt_a_ = pt_a; 
        task->pt_b_ = pt_b; 
        task->related_ = related_.get();
    }
}