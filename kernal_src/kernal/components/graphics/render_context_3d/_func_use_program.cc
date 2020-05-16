
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.useProgram(program);
 *
 * program
 *      A WebGLProgram to use.
 */
void render_context_3d::use_program(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (nullptr == program) return;
    context_cache_.current_program_ = _0;
    context_cache_.raw_current_program_ = program;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* program_ = nullptr;
        void run(barrel_buffer*) {
            assert(program_ && context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->use_program(*program_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->program_ = program->related_value_; 
    task->context_ = raw_context_.get();
}