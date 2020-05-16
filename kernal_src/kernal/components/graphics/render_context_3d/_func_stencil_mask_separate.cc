
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.stencilMaskSeparate(face, mask);
 *
 * face
 *      A GLenum specifying whether the front and/or back stencil 
 *      writemask is updated. The possible values are:
 *          gl.FRONT
 *          gl.BACK
 *          gl.FRONT_AND_BACK
 *
 * mask
 *      A GLuint specifying a bit mask to enable or disable writing of 
 *      individual bits in the stencil planes. 
 *      By default, the mask is all 1.
 */
void render_context_3d::stencil_mask_separate(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) {
        return;
    }
    uint32_t face = (uint32_t)_0.to_int32();
    uint32_t mask = (uint32_t)_1.to_int32();
    if (DWL_FRONT == face) {
        if (context_cache_.stencil_write_mask_ == mask) {
            return;
        }
        context_cache_.stencil_write_mask_ = mask;
    } else if (DWL_BACK == face) {
        if (context_cache_.stencil_back_write_mask_ == mask) {
            return;
        }
        context_cache_.stencil_back_write_mask_ = mask;
    } else if (DWL_FRONT_AND_BACK == face) {
        if (context_cache_.stencil_write_mask_      == mask &&
            context_cache_.stencil_back_write_mask_ == mask) {
            return;
        }
        context_cache_.stencil_write_mask_      = mask;
        context_cache_.stencil_back_write_mask_ = mask;
    } else {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t face_ = 0, mask_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->stencil_mask_separate(face_, mask_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->face_    = face;
    task->mask_    = mask;
    task->context_ = raw_context_.get();
}