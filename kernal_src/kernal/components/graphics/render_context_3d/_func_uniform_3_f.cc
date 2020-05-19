
#include "_func_uniform.h"

/**
 * Syntax
 *      void gl.uniform3f(location, v0, v1, v2);
 *
 * location
 *      A WebGLUniformLocation object containing 
 *      the location of the uniform attribute to modify.
 *
 * value, v0, v1, v2, v3
 *      A new value to be used for the uniform variable. Possible types:
 *          A floating point Number for floating point values (methods with "f").
 *          A sequence of floating point numbers (for example a Float32Array or 
 *              an Array of numbers) for floating point vector methods (methods with "fv").
 *          An integer Number for integer values (methods with "i").
 *          An Int32Array for integer vector methods (methods with "iv").
 */
void render_context_3d::uniform_3_f(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_uniform_intend_code(_parameter);
    if (DWL_BOOL_VEC3  != local_uniform->type_ &&
        DWL_FLOAT_VEC3 != local_uniform->type_) {
        return;
    }
    if (_parameter.get_argument_count() < 4) return;
    auto _0 = _parameter.get_argument_at(1);
    auto _1 = _parameter.get_argument_at(2);
    auto _2 = _parameter.get_argument_at(3);
    if (!_0.is_number() || !_1.is_number() || !_2.is_number()) {
        return;
    }
    auto v0 = _0.to_float();
    auto v1 = _1.to_float();
    auto v2 = _2.to_float();
    if (DWL_FLOAT_VEC3 == local_uniform->type_) {
        local_uniform->value_.f_16_[0] = (float)v0;
        local_uniform->value_.f_16_[1] = (float)v1;
        local_uniform->value_.f_16_[2] = (float)v2;
    } else if (DWL_BOOL_VEC2 == local_uniform->type_) {
        local_uniform->value_.b_16_[0] = (bool) v0;
        local_uniform->value_.b_16_[1] = (bool) v1;
        local_uniform->value_.b_16_[2] = (bool) v2;
    }

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t location_; float v0_, v1_, v2_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->uniform_3_f(location_, v0_, v1_, v2_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->location_ = location_index;
    task->v0_       = v0;
    task->v1_       = v1;
    task->v2_       = v2;
    task->context_  = raw_context_.get();
}