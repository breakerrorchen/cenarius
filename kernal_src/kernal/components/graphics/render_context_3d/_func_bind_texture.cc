
#include "../render_context_3d_texture/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.bindTexture(target, texture);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.TEXTURE_2D:          A two-dimensional texture.
 *          gl.TEXTURE_CUBE_MAP:    A cube-mapped texture.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.TEXTURE_3D:          A three-dimensional texture.
 *          gl.TEXTURE_2D_ARRAY:    A two-dimensional array texture.
 * 
 * texture
 *      A WebGLTexture object to bind.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      A gl.INVALID_ENUM error is thrown if target is not gl.TEXTURE_2D, 
 *      gl.TEXTURE_CUBE_MAP, gl.TEXTURE_3D, or gl.TEXTURE_2D_ARRAY.
 */
void render_context_3d::bind_texture(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_TEXTURE_2D != target && DWL_TEXTURE_CUBE_MAP != target) {
        return;
    }
    auto _1 = _parameter.get_argument_at(1);
    auto texture  = js_class_extract::extract<
        render_context_3d_texture>(_1);
    if (texture && !texture->is_useable()) {
        texture = nullptr;    
    }

    if (DWL_TEXTURE_2D == target) {
        if (texture) {
            context_cache_.raw_texture_2d_bind_ = nullptr;
            context_cache_.texture_2d_bind_.reset();
        } else {
            context_cache_.raw_texture_2d_bind_ = texture;
            context_cache_.texture_2d_bind_ = _1;
        }
    } else if (DWL_TEXTURE_CUBE_MAP == target) {
        if (texture) {
            context_cache_.raw_texture_cube_bind_ = nullptr;
            context_cache_.texture_cube_bind_.reset();
        } else {
            context_cache_.raw_texture_cube_bind_ = texture;
            context_cache_.texture_cube_bind_ = _1;
        }
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t target_; uint32_t* texture_ = nullptr;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            if (texture_) {
                raw_context->bind_texture(target_, *texture_);
            } else {
                raw_context->bind_texture(target_, 0);
            }
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (nullptr != texture) {
        task->texture_ = texture->related_value_;
    }
    task->context_ = raw_context_.get();
}