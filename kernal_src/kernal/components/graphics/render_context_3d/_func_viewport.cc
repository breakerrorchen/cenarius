
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.viewport(x, y, width, height);
 * 
 * x
 *      A GLint specifying the horizontal coordinate for the lower 
 *      left corner of the viewport origin. Default value: 0. 
 *  
 * y
 *      A GLint specifying the vertical coordinate for the lower 
 *      left corner of the viewport origin. Default value: 0.
 *
 * width
 *      A non-negative Glsizei specifying the width of the viewport. 
 *      Default value: width of the canvas.
 *
 * height
 *      A non-negative Glsizei specifying the height of the viewport. 
 *      Default value: height of the canvas.
 * 
 * Return value
 *      None.
 *
 * Errors thrown
 *      If either width or height is a negative value, 
 *      a gl.INVALID_VALUE error is thrown.
 */
void render_context_3d::viewport(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    auto x = _parameter[0].to_int32();
    auto y = _parameter[1].to_int32();
    auto w = _parameter[2].to_int32();
    auto h = _parameter[3].to_int32();
    if (w < 0 || h < 0) return;

    context_cache_.viewport_[0] = x;
    context_cache_.viewport_[1] = y;
    context_cache_.viewport_[2] = w;
    context_cache_.viewport_[3] = h;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t x_, y_, w_, h_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->viewport(x_, y_, w_, h_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->x_       = x;
    task->y_       = y;
    task->w_       = w;
    task->h_       = h;
    task->context_ = raw_context_.get();
}