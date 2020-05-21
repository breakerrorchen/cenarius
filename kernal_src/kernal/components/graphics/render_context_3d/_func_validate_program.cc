
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.validateProgram(program);
 *
 * program
 *      A WebGLProgram to validate.
 */
void render_context_3d::validate_program(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto js_context = _parameter.get_context();
    auto v = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(v);
    if (!program || !program->is_useable()) return;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* program_ = nullptr; 
        bool* validate_ = nullptr;
        void run(barrel_buffer*) {
            assert(program_ && validate_);
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->validate_program(*program_);
            int32_t validate_v = 0;
            raw_context->get_program_i_v(
                *program_, DWL_VALIDATE_STATUS, &validate_v);
            *validate_ = (bool)validate_v;
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->program_  = program->related_value_;
    task->validate_ = &(program->reflection_.is_validate_);
    task->context_  = raw_context_.get();

    // ！！！同步
    transmitter_->force_commit(true);
}