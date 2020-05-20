
#include "_func_vertex_attrib.h"

/**
 * Syntax
 *      void gl.vertexAttrib1f(index, v0);
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
void render_context_3d::vertex_attrib_1_f(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    render_context_3d_vertex_attrib_intend_code(_parameter);
    if (_parameter.get_argument_count() < 2) return;
    auto v0 = _parameter[1].to_float();

    attrib_data[0] = v0;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t index_; float v_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->vertex_attrib_1_f(index_, v_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->v_        = v0;
    task->context_  = raw_context_.get();
}