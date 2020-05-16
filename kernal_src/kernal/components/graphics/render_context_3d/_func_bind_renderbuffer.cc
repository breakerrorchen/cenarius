
#include "../render_context_3d_renderbuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.bindRenderbuffer(target, renderbuffer);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.RENDERBUFFER:    Buffer data storage 
 *              for single images in a renderable internal format
 * 
 * renderbuffer
 *      A WebGLRenderbuffer object to bind.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      A gl.INVALID_ENUM error is thrown if target is not gl.RENDERBUFFER.
 */
void render_context_3d::bind_renderbuffer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_RENDERBUFFER != target) { return; }
    auto _1 = _parameter.get_argument_at(1);
    auto renderbuffer  = js_class_extract::extract<
        render_context_3d_renderbuffer>(_1);
    if (renderbuffer && !renderbuffer->is_useable()) {
        renderbuffer = nullptr;    
    }

    if (nullptr == renderbuffer) {
        context_cache_.renderbuffer_bind_.reset();
        context_cache_.raw_renderbuffer_bind_ = nullptr;
    } else {
        context_cache_.renderbuffer_bind_ = _1;
        context_cache_.raw_renderbuffer_bind_ = renderbuffer;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* renderbuffer_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            if (renderbuffer_) {
                raw_context->bind_render_buffer(*renderbuffer_);
            } else {
                raw_context->bind_render_buffer(0);
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (nullptr != renderbuffer) {
        task->renderbuffer_ = renderbuffer->related_value_;
    }
    task->context_ = raw_context_.get();
}