
#include "../render_context_3d_renderbuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.framebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
 *
 * target
 *      A GLenum specifying the binding point (target) for the framebuffer. 
 *      Possible values:
 *          gl.FRAMEBUFFER: Collection buffer data storage of color, 
 *              alpha, depth and stencil buffers used to render an image.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.DRAW_FRAMEBUFFER: Equivalent to gl.FRAMEBUFFER. 
 *              Used as a destination for drawing, rendering, 
 *              clearing, and writing operations.
 *          gl.READ_FRAMEBUFFER: Used as a source for reading operations.
 * 
 * attachment
 *      A GLenum specifying the attachment point for the render buffer. 
 *      Possible values:
 *          gl.COLOR_ATTACHMENT0: color buffer.
 *          gl.DEPTH_ATTACHMENT: depth buffer.
 *          gl.DEPTH_STENCIL_ATTACHMENT: depth and stencil buffer.
 *          gl.STENCIL_ATTACHMENT: stencil buffer.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.COLOR_ATTACHMENT1
 *          gl.COLOR_ATTACHMENT2
 *          gl.COLOR_ATTACHMENT3
 *          gl.COLOR_ATTACHMENT4
 *          gl.COLOR_ATTACHMENT5
 *          gl.COLOR_ATTACHMENT6
 *          gl.COLOR_ATTACHMENT7
 *          gl.COLOR_ATTACHMENT8
 *          gl.COLOR_ATTACHMENT9
 *          gl.COLOR_ATTACHMENT10
 *          gl.COLOR_ATTACHMENT11
 *          gl.COLOR_ATTACHMENT12
 *          gl.COLOR_ATTACHMENT13
 *          gl.COLOR_ATTACHMENT14
 *          gl.COLOR_ATTACHMENT15
 *      When using the WEBGL_draw_buffers extension:
 *          ext.COLOR_ATTACHMENT0_WEBGL (same as gl.COLOR_ATTACHMENT0)
 *          ext.COLOR_ATTACHMENT1_WEBGL
 *          ext.COLOR_ATTACHMENT2_WEBGL
 *          ext.COLOR_ATTACHMENT3_WEBGL
 *          ext.COLOR_ATTACHMENT4_WEBGL
 *          ext.COLOR_ATTACHMENT5_WEBGL
 *          ext.COLOR_ATTACHMENT6_WEBGL
 *          ext.COLOR_ATTACHMENT7_WEBGL
 *          ext.COLOR_ATTACHMENT8_WEBGL
 *          ext.COLOR_ATTACHMENT9_WEBGL
 *          ext.COLOR_ATTACHMENT10_WEBGL
 *          ext.COLOR_ATTACHMENT11_WEBGL
 *          ext.COLOR_ATTACHMENT12_WEBGL
 *          ext.COLOR_ATTACHMENT13_WEBGL
 *          ext.COLOR_ATTACHMENT14_WEBGL
 *          ext.COLOR_ATTACHMENT15_WEBGL
 * 
 * renderbuffertarget
 *      A GLenum specifying the binding point (target) for the render buffer. 
 *      Possible values:
 *          gl.RENDERBUFFER: Buffer data storage 
 *              for single images in a renderable internal format.
 * 
 * renderbuffer
 *      A WebGLRenderbuffer object to attach.  
 * 
 * Return value
 *      None.
 *
 * Exceptions
 *      A gl.INVALID_ENUM error is thrown if target is not gl.FRAMEBUFFER, 
 *          gl.DRAW_FRAMEBUFFER, or gl.READ_FRAMEBUFFER.
 *      A gl.INVALID_ENUM error is thrown if renderbuffertarget is not gl.RENDERBUFFER.
 *      A gl.INVALID_ENUM error is thrown if attachment is not one of the allowed enums.
 */
void render_context_3d::framebuffer_renderbuffer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    uint32_t target = (uint32_t)_parameter[0].to_int32();
    if (DWL_FRAMEBUFFER != target) {
        return;
    }

    uint32_t attachment = (uint32_t)_parameter[1].to_int32();
    if (DWL_COLOR_ATTACHMENT0        != attachment &&
        DWL_DEPTH_ATTACHMENT         != attachment &&
        DWL_DEPTH_STENCIL_ATTACHMENT != attachment &&
        DWL_STENCIL_ATTACHMENT       != attachment) {
        return;
    }

    uint32_t renderbuffer_target = (uint32_t)_parameter[2].to_int32();
    if (DWL_RENDERBUFFER != renderbuffer_target) {
        return;
    }

    auto v = _parameter.get_argument_at(0);
    auto renderbuffer = js_class_extract::extract<
        render_context_3d_renderbuffer>(v);
    if (renderbuffer && !renderbuffer->is_useable()) {
        renderbuffer = nullptr;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* renderbuffer_ = nullptr;
        uint32_t target_, attachment_, renderbuffer_target_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            if (renderbuffer_) {
                raw_context->frame_buffer_render_buffer(target_, 
                    attachment_, renderbuffer_target_, *renderbuffer_);
            } else {
                raw_context->frame_buffer_render_buffer(
                    target_, attachment_, renderbuffer_target_, 0);
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->renderbuffer_ = renderbuffer->related_value_;
    task->target_ = target;
    task->attachment_ = attachment;
    task->renderbuffer_target_ = renderbuffer_target;
    task->context_ = raw_context_.get();
}