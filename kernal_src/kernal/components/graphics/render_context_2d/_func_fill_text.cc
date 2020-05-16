
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void render_context_2d::fill_text(js_parameter& parameter) {
    assert(transmitter_ && related_);
    if (parameter.get_argument_count() < 3) return;
    auto _0 = parameter.get_argument_at(0);
    if (!_0.is_str()) return;
    auto text = _0.to_string();
    auto x = parameter[1].to_int32();
    auto y = parameter[2].to_int32();
    auto max_width = INT_MAX;
    if (parameter.get_argument_count() == 4) {
        max_width = parameter[3].to_int32();
    }
    struct __task__ {
        puppet_container<canvas_render_2d>* context_ = nullptr;
		render_context_thread_related* related_ = nullptr;
        std::string text_; int x_ = 0, y_ = 0, max_width_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
			assert(canvas && related_);
            auto& render_context = related_->get_rt_context();
            render_context.prepare_for_fill();
            render_context.prepare_for_text();
            auto& matrix = render_context.current_matrix_;
            SkFont font(render_context.typeface_,
                render_context.typeface_size_);
            if (render_context.is_have_shadow()) {
                x_ += render_context.shadow_offset_x_;
                y_ += render_context.shadow_offset_y_;
            }
            y_ += render_context.text_baseline_v_;
            SkAutoCanvasRestore sk_restore(canvas, true);        
            canvas->concat(matrix);
            SkTextUtils::Draw(
                canvas, text_.c_str(), text_.length(),
                SkTextEncoding::kUTF8, x_, y_, font, 
                render_context.fill_paint_,
                render_context.sk_text_align_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->context_ = raw_context_.get();
        task->text_    = std::move(text);
        task->x_       = x;
        task->y_       = y;
        task->related_ = related_.get();
    }
    transmitter_->force_commit();
}