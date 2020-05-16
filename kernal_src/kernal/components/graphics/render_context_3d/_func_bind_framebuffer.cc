
#include "../render_context_3d_framebuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.bindFramebuffer(target, framebuffer);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.FRAMEBUFFER:         Collection buffer data storage of color, 
 *              alpha, depth and stencil buffers used to render an image.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.DRAW_FRAMEBUFFER:    Equivalent to gl.FRAMEBUFFER. Used as a 
 *              destination for drawing, rendering, clearing, and writing operations.
 *          gl.READ_FRAMEBUFFER:    Used as a source for reading operations.
 * 
 * framebuffer
 *      A WebGLFramebuffer object to bind.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      A gl.INVALID_ENUM error is thrown if target 
 *      is not gl.FRAMEBUFFER, gl.DRAW_FRAMEBUFFER, or gl.READ_FRAMEBUFFER.
 */
void render_context_3d::bind_framebuffer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_FRAMEBUFFER != target) { return; }
    auto _1 = _parameter.get_argument_at(1);
    auto framebuffer  = js_class_extract::extract<
        render_context_3d_framebuffer>(_1);
    if (framebuffer && !framebuffer->is_useable()) {
        framebuffer = nullptr;    
    }
    
    if (nullptr == framebuffer) {
        context_cache_.framebuffer_bind_.reset();
        context_cache_.raw_framebuffer_bind_ = nullptr;
    } else {
        context_cache_.framebuffer_bind_ = _1;
        context_cache_.raw_framebuffer_bind_ = framebuffer;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* framebuffer_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            if (framebuffer_) {
                raw_context->bind_frame_buffer(*framebuffer_);
            } else {
                raw_context->bind_frame_buffer(0);
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (nullptr != framebuffer) {
        task->framebuffer_ = framebuffer->related_value_;
    }
    task->context_ = raw_context_.get();
}