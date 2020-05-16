
#include "kernal/components/image/_.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

inline void draw_image(image* _image, js_parameter& _parameter, int count, 
    std::shared_ptr<command_transmitter>& transmitter,
    puppet<canvas_render_2d>& raw_context,
    std::shared_ptr<render_context_thread_related>& related) {
    if (nullptr == _image) return;
    auto raw_image = _image->get_raw_image();
    if (!raw_image) return;

    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/drawImage
    // void ctx.drawImage(image, dx, dy);
    if (3 == count) {
        auto dx = _parameter[1].to_float();
        auto dy = _parameter[2].to_float();
        struct __task__ {
            puppet_container<canvas_render_2d>* context_ = nullptr;
		    render_context_thread_related* related_ = nullptr;
            float x_ = 0, y_ = 0; sk_sp<SkImage> image_;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
			    auto canvas = context_->data_->get();
			    assert(canvas && related_);
                auto& render_context = related_->get_rt_context();
                render_context.prepare_for_fill();
                if (render_context.is_have_shadow()) {
                    x_ += render_context.shadow_offset_x_;
                    y_ += render_context.shadow_offset_y_;
                }
                auto& matrix = render_context.current_matrix_;
                SkAutoCanvasRestore sk_restore(canvas, true);
                canvas->concat(matrix);
                canvas->drawImage(image_, 
                    x_, y_, &render_context.fill_paint_);
            }
        };
        auto task = transmitter->alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->context_ = raw_context.get();
            task->image_   = std::move(raw_image);
            task->x_       = dx;
            task->y_       = dy;
            task->related_ = related.get();
        }
        transmitter->force_commit();
    } 
    
    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/drawImage
    // void ctx.drawImage(image, dx, dy, dWidth, dHeight);
    else if (5 == count) {
        auto dx = _parameter[1].to_float();
        auto dy = _parameter[2].to_float();
        auto  w = _parameter[3].to_float();
        auto  h = _parameter[4].to_float();
        struct __task__ {
            puppet_container<canvas_render_2d>* context_ = nullptr;
		    render_context_thread_related* related_ = nullptr;
            float x_, y_, w_, h_; sk_sp<SkImage> image_;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
			    auto canvas = context_->data_->get();
			    assert(canvas && related_);
                auto& render_context = related_->get_rt_context();
                render_context.prepare_for_fill();
                if (render_context.is_have_shadow()) {
                    x_ += render_context.shadow_offset_x_;
                    y_ += render_context.shadow_offset_y_;
                }
                auto& matrix = render_context.current_matrix_;
                SkAutoCanvasRestore sk_restore(canvas, true);
                canvas->concat(matrix);
                auto dst = SkRect::MakeXYWH(x_, y_, w_, h_);
                canvas->drawImageRect(
                    image_, dst, &render_context.fill_paint_);
            }
        };
        auto task = transmitter->alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->context_ = raw_context.get();
            task->image_   = std::move(raw_image);
            task->x_       = dx;
            task->y_       = dy;
            task->w_       = w ;
            task->h_       = h ;
            task->related_ = related.get();
        }
        transmitter->force_commit();
    } 
    
    // https://developer.mozilla.org/en-US/docs/Web/API/CanvasRenderingContext2D/drawImage
    // void ctx.drawImage(image, sx, sy, sWidth, sHeight, dx, dy, dWidth, dHeight);
    else if (9 == count) {
        auto sx = _parameter[1].to_float();
        auto sy = _parameter[2].to_float();
        auto sw = _parameter[3].to_float();
        auto sh = _parameter[4].to_float();
        auto dx = _parameter[5].to_float();
        auto dy = _parameter[6].to_float();
        auto dw = _parameter[7].to_float();
        auto dh = _parameter[8].to_float();
        struct __task__ {
            puppet_container<canvas_render_2d>* context_ = nullptr;
		    render_context_thread_related* related_ = nullptr;
            sk_sp<SkImage> image_;
            float sx_, sy_, sw_, sh_, dx_, dy_, dw_, dh_; 
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
			    auto canvas = context_->data_->get();
			    assert(canvas && related_);
                auto& render_context = related_->get_rt_context();
                render_context.prepare_for_fill();
                if (render_context.is_have_shadow()) {
                    dx_ += render_context.shadow_offset_x_;
                    dy_ += render_context.shadow_offset_y_;
                }
                auto& matrix = render_context.current_matrix_;
                SkAutoCanvasRestore sk_restore(canvas, true);
                canvas->concat(matrix);
                auto src = SkRect::MakeXYWH(sx_, sy_, sw_, sh_);
                auto dst = SkRect::MakeXYWH(dx_, dy_, dw_, dh_);
                canvas->drawImageRect(image_, 
                    src, dst, &render_context.fill_paint_);
            }
        };
        auto task = transmitter->alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->context_ = raw_context.get();
            task->image_   = std::move(raw_image);
            task->sx_      = sx;
            task->sy_      = sy;
            task->sw_      = sw;
            task->sh_      = sh;
            task->dx_      = dx;
            task->dy_      = dy;
            task->dw_      = dw;
            task->dh_      = dh;
            task->related_ = related.get();
        }
        transmitter->force_commit();
    }
}

void render_context_2d::draw_image(js_parameter& _parameter) {
    assert(related_ && !related_->lt_context_stack_.empty());
    auto argument_count = _parameter.get_argument_count();
    if (3 != argument_count &&
        5 != argument_count &&
        9 != argument_count) {
        return;
    }
    auto drawable = _parameter.get_argument_at(0);
    auto _image = js_class_extract::extract<image>(drawable);
    if (nullptr != _image) {
        ::draw_image(_image, _parameter, argument_count,
            transmitter_, raw_context_, related_);
        return;
    }
}