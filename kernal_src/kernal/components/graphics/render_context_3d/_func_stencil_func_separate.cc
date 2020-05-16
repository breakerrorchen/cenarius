
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.stencilFuncSeparate(face, func, ref, mask);
 *
 * face
 *      A GLenum specifying whether the front and/or back stencil state is updated. 
 *      The possible values are:
 *          gl.FRONT
 *          gl.BACK
 *          gl.FRONT_AND_BACK
 *
 * func
 *      A GLenum specifying the test function. 
 *      The default function is gl.ALWAYS. The possible values are:
 *          gl.NEVER:    Never pass.
 *          gl.LESS:     Pass if (ref & mask) <  (stencil & mask).
 *          gl.EQUAL:    Pass if (ref & mask) =  (stencil & mask).
 *          gl.LEQUAL:   Pass if (ref & mask) <= (stencil & mask).
 *          gl.GREATER:  Pass if (ref & mask) >  (stencil & mask).
 *          gl.NOTEQUAL: Pass if (ref & mask) >  (stencil & mask).
 *          gl.GEQUAL:   Pass if (ref & mask) >= (stencil & mask).
 *          gl.ALWAYS:   Always pass.
 *
 * ref
 *      A GLint specifying the reference value for the stencil test. 
 *      This value is clamped to the range 0 to 2n -1 where n is the 
 *      number of bitplanes in the stencil buffer. The default value is 0.
 *
 * mask
 *      A GLuint specifying a bit-wise mask that is used to AND the 
 *      reference value and the stored stencil value when the test is done. 
 *      The default value is all 1.
 */
void render_context_3d::stencil_func_separate(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 4) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    auto _2 = _parameter.get_argument_at(2);
    auto _3 = _parameter.get_argument_at(3);
    if (!_0.is_number() || !_1.is_number() ||
        !_2.is_number() || !_3.is_number()) {
        return;
    }
    uint32_t face = (uint32_t)_0.to_int32();
    uint32_t func = (uint32_t)_1.to_int32();
    int      ref  = (int)     _2.to_int32();
    uint32_t mask = (uint32_t)_3.to_int32();

    if (DWL_NEVER   != func && DWL_LESS     != func &&
        DWL_EQUAL   != func && DWL_LEQUAL   != func &&
        DWL_GREATER != func && DWL_NOTEQUAL != func &&
        DWL_GEQUAL  != func && DWL_ALWAYS   != func) {
        return;
    }

    if (DWL_FRONT == face) {
        context_cache_.front_face_stencil_func_      = func;
        context_cache_.front_face_stencil_func_ref_  = ref;
        context_cache_.front_face_stencil_func_mask_ = mask;
    } else if (DWL_BACK == face) {
        context_cache_.back_face_stencil_func_       = func;
        context_cache_.back_face_stencil_func_ref_   = ref;
        context_cache_.back_face_stencil_func_mask_  = mask;
    } else if (DWL_FRONT_AND_BACK == face) {
        context_cache_.front_face_stencil_func_      = func;
        context_cache_.back_face_stencil_func_       = func;
        context_cache_.front_face_stencil_func_ref_  = ref;
        context_cache_.back_face_stencil_func_ref_   = ref;
        context_cache_.front_face_stencil_func_mask_ = mask;
        context_cache_.back_face_stencil_func_mask_  = mask;
    } else {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t mask_face_; uint32_t func_; int ref_; uint32_t mask_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->stencil_func_separate(
                mask_face_, func_, ref_, mask_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->mask_face_= face;
    task->func_     = func;
    task->ref_      = ref;
    task->mask_     = mask;
    task->context_  = raw_context_.get();
}