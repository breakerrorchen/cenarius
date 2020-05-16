
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::clear_rect(js_parameter& parameter) {
	assert(transmitter_ && related_);
	if (parameter.get_argument_count() != 4) return;
	auto& context = related_->lt_context_stack_.top();
	auto& _martix = context.current_matrix_;
	float x, y, w, h;
	x = parameter.get_argument_at(0).to_float();
	y = parameter.get_argument_at(1).to_float();
	w = parameter.get_argument_at(2).to_float();
	h = parameter.get_argument_at(3).to_float();
	struct __task__ {
		puppet_container<canvas_render_2d>* context_ = nullptr;
        SkMatrix matrix_; SkRect rc_;
		void run(barrel_buffer*) {
			assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
			assert(canvas);
			SkPath path;
			path.addRect(rc_); path.transform(matrix_);
			SkPaint paint;
			paint.setColor(SK_ColorTRANSPARENT);
			paint.setBlendMode(SkBlendMode::kClear);
			canvas->drawPath(path, paint);
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	if (task) {
		task->context_ = raw_context_.get();
		task->matrix_  = _martix;
		task->rc_ 	   = SkRect::MakeXYWH(x, y, w, h);
	}
	transmitter_->force_commit();
}