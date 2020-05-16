
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_2d::fill_rect(js_parameter& parameter) {
    assert(transmitter_ && related_);
	if (parameter.get_argument_count() != 4) return;
    auto x = parameter[0].to_int32();
    auto y = parameter[1].to_int32();
    auto w = parameter[2].to_int32();
    auto h = parameter[3].to_int32();
    if (w == 0 || h == 0) return;
    if (w < 0) { x += w; w = -w; }
    if (h < 0) { y += h; h = -h; }
    struct __task__ {
        puppet_container<canvas_render_2d>* context_ = nullptr;
        render_context_thread_related* related_ = nullptr;
        int x_, y_, w_, h_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
			auto canvas = context_->data_->get();
            assert(canvas && related_);
            auto& render_context = related_->get_rt_context();
            render_context.prepare_for_fill();
            auto& matrix = render_context.current_matrix_;
            SkPath path;
            path.addRect(SkRect::MakeXYWH(x_, y_, w_, h_));
            path.transform(matrix);
            auto& paint = render_context.fill_paint_;
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
        task->x_       = x;
        task->y_       = y;
        task->w_       = w;
        task->h_       = h;
        task->related_ = related_.get();
    }
    transmitter_->force_commit();
}