
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.bindAttribLocation(program, index, name);
 *
 * Parameters
 *      program
 *          A WebGLProgram object to bind.
 *      index
 *          A GLuint specifying the index of the generic vertex to bind.
 *      name
 *          A DOMString specifying the name of the variable to bind to the 
 *          generic vertex index. This name cannot start with "webgl_" 
 *          or "_webgl_", as these are reserved for use by WebGL.
 * 
 * Return value
 *      None.
 */
void render_context_3d::bind_attrib_location(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 3) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!_program || !_program->is_useable()) return;
    auto _1 = _parameter.get_argument_at(1);
    auto _2 = _parameter.get_argument_at(2);
    if (!_1.is_number() || !_2.is_str()) return;
    auto name  = _2.to_string();
    auto index = (uint32_t)_1.to_int32();
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t* program_ = nullptr;
        std::string name_; uint32_t index_ = 0;
        void run(barrel_buffer*) {
            assert(program_);
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            raw_context->bind_attrib_location(
                *program_, index_, name_.c_str());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->program_ = _program->related_value_;
    task->name_    = std::move(name);
    task->index_   = index;
    task->context_ = raw_context_.get();
}