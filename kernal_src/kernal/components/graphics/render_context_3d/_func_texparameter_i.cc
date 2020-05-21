
#include "../render_context_3d_texture/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.texParameteri(GLenum target, GLenum pname, GLint param);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.TEXTURE_2D: A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP: A cube-mapped texture.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.TEXTURE_3D: A three-dimensional texture.
 *          gl.TEXTURE_2D_ARRAY: A two-dimensional array texture.
 */
void render_context_3d::texparameter_i(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 3) return;
    uint32_t target = (uint32_t)_parameter[0].to_int32();
    uint32_t pname  = (uint32_t)_parameter[1].to_int32();
    int      param  = _parameter[1].to_int32();
    render_context_3d_texture* raw_texture = nullptr;
    if (DWL_TEXTURE_2D == target) {
        raw_texture = context_cache_.raw_texture_2d_bind_;
    } else if (DWL_TEXTURE_CUBE_MAP == target) {
        raw_texture = context_cache_.raw_texture_cube_bind_;
    } else {
        return;
    }
    if (nullptr == raw_texture) return;

    if (DWL_TEXTURE_MAG_FILTER == pname) {
        if (DWL_LINEAR                 != param && 
            DWL_NEAREST                != param &&
            DWL_NEAREST_MIPMAP_NEAREST != param &&
            DWL_LINEAR_MIPMAP_NEAREST  != param &&
            DWL_NEAREST_MIPMAP_LINEAR  != param &&
            DWL_LINEAR_MIPMAP_LINEAR   != param) {
            return;
        }
        raw_texture->mag_filter_ = param;
    } else if (DWL_TEXTURE_MIN_FILTER == pname) {
        if (DWL_LINEAR                 != param && 
            DWL_NEAREST                != param &&
            DWL_NEAREST_MIPMAP_NEAREST != param &&
            DWL_LINEAR_MIPMAP_NEAREST  != param &&
            DWL_NEAREST_MIPMAP_LINEAR  != param &&
            DWL_LINEAR_MIPMAP_LINEAR   != param) {
            return;
        }
        raw_texture->min_filter_ = param;
    } else if (DWL_TEXTURE_WRAP_S == pname) {
        if (DWL_REPEAT                 != param && 
            DWL_CLAMP_TO_EDGE          != param &&
            DWL_MIRRORED_REPEAT        != param) {
            return;
        }
        raw_texture->wrap_s_ = param;
    } else if (DWL_TEXTURE_WRAP_T == pname) {
        if (DWL_REPEAT                 != param && 
            DWL_CLAMP_TO_EDGE          != param &&
            DWL_MIRRORED_REPEAT        != param) {
            return;
        }
        raw_texture->wrap_t_ = param;
    } else {
        return;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_, pname_; int param_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->tex_parameter_i(
                target_, pname_, param_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->target_  = target;
    task->pname_   = pname;
    task->param_   = param;
    task->context_ = raw_context_.get();
}