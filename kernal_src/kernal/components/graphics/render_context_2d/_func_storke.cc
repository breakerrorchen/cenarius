
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::stroke(js_parameter& parameter) {
    assert(transmitter_ && related_);
    struct __task__ {
        puppet_container<canvas_render_2d>* context_ = nullptr;
		render_context_thread_related* related_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
			assert(canvas && related_);
            auto& render_context = related_->get_rt_context();
            render_context.prepare_for_stroke();
            auto& path = related_->rt_current_path_;
            auto& paint= render_context.stroke_paint_;
            if (render_context.is_have_shadow() && (
                render_context.shadow_offset_x_ != 0 || 
                render_context.shadow_offset_y_ != 0)) {
                SkAutoCanvasRestore autoRestore(canvas, true);
                canvas->translate(
                    render_context.shadow_offset_x_,
                    render_context.shadow_offset_y_);
                canvas->drawPath(path, paint);
            } else {
                canvas->drawPath(path, paint);
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->context_ = raw_context_.get();
        task->related_ = related_.get();
    }
    transmitter_->force_commit();
}