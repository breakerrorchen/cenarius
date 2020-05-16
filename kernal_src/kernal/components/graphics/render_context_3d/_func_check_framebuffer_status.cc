
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      GLenum gl.checkFramebufferStatus(target);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.FRAMEBUFFER:     Collection buffer data storage of color, 
 *              alpha, depth and stencil buffers used to render an image.
 * 
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.DRAW_FRAMEBUFFER: Equivalent to gl.FRAMEBUFFER. 
 *              Used as a destination for drawing, 
 *              rendering, clearing, and writing operations.
 *          gl.READ_FRAMEBUFFER: Used as a source for reading operations.
 * 
 * Return value
 *      A GLenum indicating the completeness status of the framebuffer or 0 
 *      if an error occurs. Possible enum return values:
 *          gl.FRAMEBUFFER_COMPLETE:                The framebuffer is ready to display.
 *          gl.FRAMEBUFFER_INCOMPLETE_ATTACHMENT:   The attachment types are mismatched 
 *              or not all framebuffer attachment points are framebuffer attachment complete.
 *          gl.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: There is no attachment.
 *          gl.FRAMEBUFFER_INCOMPLETE_DIMENSIONS: 
 *              Height and width of the attachment are not the same.
 *          gl.FRAMEBUFFER_UNSUPPORTED:             The format of the attachment is not 
 *              supported or if depth and stencil attachments are not the same renderbuffer.
 *      When using a WebGL 2 context, the following values can be returned additionally:
 *          gl.FRAMEBUFFER_INCOMPLETE_MULTISAMPLE: The values of gl.RENDERBUFFER_SAMPLES are 
 *              different among attached renderbuffers, or are non-zero if the attached 
 *              images are a mix of renderbuffers and textures.
 * 
 * Exceptions
 *      None
 */
void render_context_3d::check_framebuffer_status(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_FRAMEBUFFER != target) {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_, *status_ = 0;
        void run(barrel_buffer*) {
            assert(status_ && context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->check_frame_buffer_status(target_, status_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    uint32_t framebuffer_status = DWL_FRAMEBUFFER_COMPLETE;
    task->target_ = target;
    task->status_ = &framebuffer_status;
    transmitter_->force_commit(true, false);

    // return js value
    auto js_context = _parameter.get_context();
    _parameter.set_return(
        js_value::create(js_context, (int32_t)framebuffer_status));
}