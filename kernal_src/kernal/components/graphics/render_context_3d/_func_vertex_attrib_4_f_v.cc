
#include "_func_vertex_attrib.h"

/**
 * Syntax
 *      void gl.vertexAttrib4fv(index, value);
 *
 * index
 *      A GLuint specifying the position of the vertex attribute to be modified.
 *
 * v0, v1, v2, v3
 *      A floating point Number for the vertex attribute value.
 *
 * value
 *      A Float32Array for floating point vector vertex attribute values.
 */
void render_context_3d::vertex_attrib_4_f_v(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_vertex_attrib_intend_code(_parameter);
    if (_parameter.get_argument_count() < 5) return;
    auto v = _parameter.get_argument_at(1);
    float data[4];
    if (!buffer_extract<float>(data, 4, v)) return;

    attrib_data[0] = data[0]; 
    attrib_data[1] = data[1]; 
    attrib_data[2] = data[2];
    attrib_data[3] = data[3];

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t index_; float v0_, v1_, v2_, v3_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->vertex_attrib_4_f(
                index_, v0_, v1_, v2_, v3_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->v0_       = data[0];
    task->v1_       = data[1];
    task->v2_       = data[2];
    task->v3_       = data[3];
    task->context_  = raw_context_.get();
}