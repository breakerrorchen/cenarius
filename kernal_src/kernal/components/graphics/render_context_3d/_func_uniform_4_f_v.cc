
#include "_func_uniform.h"

/**
 * Syntax
 *      void gl.uniform4fv(location, value);
 *
 * location
 *      A WebGLUniformLocation object containing 
 *      the location of the uniform attribute to modify.
 *
 * value, v0, v1, v2, v3
 *      A new value to be used for the uniform variable. Possible types:
 *          A floating point Number for floating point values (methods with "f").
 *          A sequence of floating point numbers (for example a Float32Array 
 *              or an Array of numbers) 
 *              for floating point vector methods (methods with "fv").
 *          An integer Number for integer values (methods with "i").
 *          An Int32Array for integer vector methods (methods with "iv").
 */
void render_context_3d::uniform_4_f_v(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() < 2) return;
    render_context_3d_uniform_intend_code(_parameter);
    if (DWL_BOOL_VEC4  != local_uniform->type_ &&
        DWL_FLOAT_VEC4 != local_uniform->type_) {
        return;
    }
    auto v = _parameter.get_argument_at(1);
    float data[4];
    if (!buffer_extract<float>(data, 4, v)) return;
    if (DWL_FLOAT_VEC4 == local_uniform->type_) {
        local_uniform->value_.f_16_[0] = (float)data[0];
        local_uniform->value_.f_16_[1] = (float)data[1];
        local_uniform->value_.f_16_[2] = (float)data[2];
        local_uniform->value_.f_16_[3] = (float)data[3];
    } else if (DWL_BOOL_VEC3 == local_uniform->type_) {
        local_uniform->value_.b_16_[0] = (bool) data[0];
        local_uniform->value_.b_16_[1] = (bool) data[1];
        local_uniform->value_.b_16_[2] = (bool) data[2];
        local_uniform->value_.b_16_[3] = (bool) data[2];
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t location_; float v0_, v1_, v2_, v3_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->uniform_4_f(
                location_, v0_, v1_, v2_, v3_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->location_ = location_index;
    task->v0_       = data[0];
    task->v1_       = data[1];
    task->v2_       = data[2];
    task->v3_       = data[3];
    task->context_  = raw_context_.get();
}