
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void render_context_2d::fill(js_parameter& _parameter) {
    const static char* _evenodd = "evenodd";
    assert(transmitter_ && related_);
    auto fill_type = SkPathFillType::kWinding;
    if (_parameter.get_argument_count() > 0) {
        auto str = _parameter.get_argument_at(0).to_string();
        if (str == _evenodd) {
            fill_type = SkPathFillType::kEvenOdd;
        }
    }
    struct __task__ {
        puppet_container<canvas_render_2d>* context_ = nullptr;
		render_context_thread_related* related_ = nullptr;
        SkPathFillType fill_type_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
			assert(canvas && related_);
            auto& render_context = related_->get_rt_context();
            render_context.prepare_for_fill();
            auto& path = related_->rt_current_path_;
            auto& paint= render_context.fill_paint_;
            auto old_fill = path.getFillType();
            path.setFillType(fill_type_);
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
            path.setFillType(old_fill);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->context_   = raw_context_.get();
        task->fill_type_ = fill_type;
        task->related_   = related_.get();
    }
    transmitter_->force_commit();
}