
#include "_func_uniform.h"

/**
 * Syntax
 *      WebGLRenderingContext.uniformMatrix2fv(location, transpose, value);
 *
 * location
 *      A WebGLUniformLocation object containing the location of the uniform 
 *      attribute to modify. The location is obtained using getUniformLocation().
 *
 * transpose
 *      A GLboolean specifying whether to transpose the matrix. Must be false.
 *
 * value
 *      A Float32Array or sequence of GLfloat values.
 */
void render_context_3d::uniform_matrix_2_f_v(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_uniform_intend_code(_parameter);
    if (DWL_FLOAT_MAT2 != local_uniform->type_) {
        return;
    }
    if (_parameter.get_argument_count() < 3) return;
    auto _0 = _parameter.get_argument_at(1);
    if (_0.to_bool()) return;
    auto _1 = _parameter.get_argument_at(2);
    float data[4];
    if (!buffer_extract<float>(data, 4, _1)) return;
    local_uniform->value_.f_16_[0] = data[0];
    local_uniform->value_.f_16_[1] = data[1];
    local_uniform->value_.f_16_[2] = data[2];
    local_uniform->value_.f_16_[3] = data[3];

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t location_; float v_[4];
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->uniform_matrix_2_f_v(
                location_, 4, false, v_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->location_ = location_index;
    task->v_[0]     = data[0];
    task->v_[1]     = data[1];
    task->v_[2]     = data[2];
    task->v_[3]     = data[3];
    task->context_  = raw_context_.get();
}