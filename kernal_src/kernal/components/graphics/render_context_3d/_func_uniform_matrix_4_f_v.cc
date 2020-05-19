
#include "_func_uniform.h"

/**
 * Syntax
 *      WebGLRenderingContext.uniformMatrix4fv(location, transpose, value);
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
void render_context_3d::uniform_matrix_4_f_v(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_uniform_intend_code(_parameter);
    if (DWL_FLOAT_MAT4 != local_uniform->type_) {
        return;
    }
    if (_parameter.get_argument_count() < 3) return;
    auto _0 = _parameter.get_argument_at(1);
    if (_0.to_bool()) return;
    auto _1 = _parameter.get_argument_at(2);
    float data[16];
    if (!buffer_extract<float>(data, 16, _1)) return;
    memcpy((void*)local_uniform->value_.f_16_, 
        (void*)data, 16 * sizeof(float));

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        int32_t location_; float v_[16];
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->uniform_matrix_4_f_v(
                location_, 16, false, v_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->location_ = location_index;
    task->context_  = raw_context_.get();
    memcpy((void*)task->v_, (void*)data, 16 * sizeof(float));
}