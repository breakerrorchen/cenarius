
#include "_func_uniform.h"

/**
 * Syntax
 *      void gl.uniform2fv(location, value);
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
void render_context_3d::uniform_2_f_v(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_uniform_intend_code(_parameter);
    if (_parameter.get_argument_count() != 2) return;
    auto v = _parameter.get_argument_at(0);
    if (!v.is_typed_arr_float32()) return;
    auto typedarr_buffer = v.typedarr_buffer();
    if (typedarr_buffer.size<float>() < 2) return;
    float value[2] = {0, 0};
    value[0] = typedarr_buffer.at<float>(0);
    value[1] = typedarr_buffer.at<float>(1);
    if (DWL_FLOAT == local_uniform->type_) {
        local_uniform->value_.f_16_[0] = value[0];
        local_uniform->value_.f_16_[1] = value[1];
    } else if (DWL_BOOL == local_uniform->type_) {
        local_uniform->value_.b_16_[0] = (bool)value[0];
        local_uniform->value_.b_16_[1] = (bool)value[1];
    } else if (DWL_INT == local_uniform->type_) {
        local_uniform->value_.i_16_[0] = (int)value[0];
        local_uniform->value_.i_16_[1] = (int)value[1];
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t location_; float value_[2];
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->uniform_2_f_v(location_, 2, value_);
        }
    };
}