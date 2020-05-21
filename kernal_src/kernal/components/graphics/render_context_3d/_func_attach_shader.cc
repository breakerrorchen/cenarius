
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.attachShader(program, shader);
 *
 * Parameters
 *      program
 *          A WebGLProgram.
 *      shader
 *          A fragment or vertex WebGLShader.
 * 
 * Return value
 *      None.
 */
void render_context_3d::attach_shader(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!_program || !_program->is_useable()) return;
    auto _1 = _parameter.get_argument_at(1);
    auto _shader  = js_class_extract::extract<
        render_context_3d_shader>(_1);
    if (!_shader || !_shader->is_useable()) return;
    if (_shader->class_ == render_context_3d_shader_class::_vs_) {
        _program->vs_raw_shader_ = nullptr;
        _program->vs_shader_.reset();
        _program->vs_shader_ = _1;
        _program->vs_raw_shader_ = _shader;
    } else if (
        _shader->class_ == render_context_3d_shader_class::_fs_) {
        _program->fs_raw_shader_ = nullptr;
        _program->fs_shader_.reset();
        _program->fs_shader_ = _1;
        _program->fs_raw_shader_ = _shader;
    }
    
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t *program_ = nullptr, *shader_ = nullptr;
        void run(barrel_buffer*) {
            assert(program_ && shader_);
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->attach_shader(*program_, *shader_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->program_ = _program->related_value_;
    task->shader_  = _shader ->related_value_;
    task->context_ = raw_context_.get();
}