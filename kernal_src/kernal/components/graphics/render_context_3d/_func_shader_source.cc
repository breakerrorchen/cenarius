
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.shaderSource(shader, source);
 *
 * shader
 *      A WebGLShader object in which to set the source code.
 *
 * source
 *      A DOMString containing the GLSL source code to set.
 */
void render_context_3d::shader_source(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_str()) return;
    auto shader = js_class_extract::extract<
        render_context_3d_shader>(_0);
    if (!shader || !shader->is_useable()) return;

    shader->shader_source_ = _1;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* shader_ = nullptr; std::string source_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_ && shader_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->shader_source(
                *shader_, source_.c_str(), source_.length());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->shader_  = shader->related_value_;
    task->source_  = _1.to_string();
    task->context_ = raw_context_.get();
}