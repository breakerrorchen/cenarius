
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.linkProgram(program);
 * 
 * pname
 *      The WebGLProgram to link. 
 */
void render_context_3d::link_program(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter[0];
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* program_ = nullptr;
        shader_reflection* reflection_ = nullptr;
        void run(barrel_buffer*) {
            assert(program_ && reflection_);
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->link_program(*program_, reflection_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->program_    = program->related_value_;
    task->reflection_ = &program->reflection_;
    task->context_    = raw_context_.get();
    transmitter_->force_commit(true);
}