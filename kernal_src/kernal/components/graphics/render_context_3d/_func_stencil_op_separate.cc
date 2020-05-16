
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.stencilOpSeparate(face, fail, zfail, zpass);
 *
 * face
 *      A GLenum specifying whether the front and/or back stencil state 
 *      is updated. 
 *      The possible values are:
 *          gl.FRONT
 *          gl.BACK
 *          gl.FRONT_AND_BACK
 *
 * fail
 *      A GLenum specifying the function to use when the stencil test fails. 
 *      The default value is gl.KEEP.
 *
 * zfail
 *      A GLenum specifying the function to use when the stencil test passes, 
 *      but the depth test fails. The default value is gl.KEEP.
 *
 * zpass
 *      A GLenum specifying the function to use when both the stencil test 
 *      and the depth test pass, or when the stencil test passes and there
 *      is no depth buffer or depth testing is disabled. The default value is gl.KEEP.
 */
void render_context_3d::stencil_op_separate(js_parameter& _parameter) {
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
    auto face   = (uint32_t)_0.to_int32();
    auto fail   = (uint32_t)_1.to_int32();
    auto z_fail = (uint32_t)_2.to_int32();
    auto z_pass = (uint32_t)_3.to_int32();

    if (DWL_KEEP        != fail &&
        DWL_ZERO        != fail &&
        DWL_REPLACE     != fail &&
        DWL_INCR        != fail &&
        DWL_INCR_WRAP   != fail &&
        DWL_DECR        != fail &&
        DWL_DECR_WRAP   != fail &&
        DWL_INVERT      != fail) {
        return;
    }

    if (DWL_KEEP        != z_fail &&
        DWL_ZERO        != z_fail &&
        DWL_REPLACE     != z_fail &&
        DWL_INCR        != z_fail &&
        DWL_INCR_WRAP   != z_fail &&
        DWL_DECR        != z_fail &&
        DWL_DECR_WRAP   != z_fail &&
        DWL_INVERT      != z_fail) {
        return;
    }

    if (DWL_KEEP        != z_pass &&
        DWL_ZERO        != z_pass &&
        DWL_REPLACE     != z_pass &&
        DWL_INCR        != z_pass &&
        DWL_INCR_WRAP   != z_pass &&
        DWL_DECR        != z_pass &&
        DWL_DECR_WRAP   != z_pass &&
        DWL_INVERT      != z_pass) {
        return;
    }

    if (DWL_FRONT == face) {
        context_cache_.front_stencil_op_fail_   = fail;
        context_cache_.front_stencil_op_z_fail_ = z_fail;
        context_cache_.front_stencil_op_z_pass_ = z_pass;
    } else if (DWL_BACK == face) {
        context_cache_.back_stencil_op_fail_    = fail;
        context_cache_.back_stencil_op_z_fail_  = z_fail;
        context_cache_.back_stencil_op_z_pass_  = z_pass;
    } else if (DWL_FRONT_AND_BACK == face) {
        context_cache_.front_stencil_op_fail_   = fail;
        context_cache_.back_stencil_op_fail_    = fail;
        context_cache_.front_stencil_op_z_fail_ = z_fail;
        context_cache_.back_stencil_op_z_fail_  = z_fail;
        context_cache_.front_stencil_op_z_pass_ = z_pass;
        context_cache_.back_stencil_op_z_pass_  = z_pass;
    } else {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t face_ = 0, fail_ = 0, z_fail_ = 0, z_pass_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->stencil_op_separate(
                face_, fail_, z_fail_, z_pass_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->face_    = face;
    task->fail_    = fail;
    task->z_fail_  = z_fail; 
    task->z_pass_  = z_pass; 
    task->context_ = raw_context_.get();
}