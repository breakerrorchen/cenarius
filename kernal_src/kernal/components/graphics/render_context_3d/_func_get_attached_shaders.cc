
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      sequence<WebGLShader> gl.getAttachedShaders(program);
 * 
 * program
 *      A WebGLProgram object to get attached shaders for.
 * 
 * Return value
 *      An Array of WebGLShader objects that are attached to the given WebGLProgram.
 */
void render_context_3d::get_attached_shaders(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    auto js_context = _parameter.get_context();
    js_value arr[2]; int arr_size = 0;
    if (program->vs_shader_.is_useable()) {
        arr[arr_size++] = (js_value)program->vs_shader_;
    }
    if (program->fs_shader_.is_useable()) {
        arr[arr_size++] = (js_value)program->fs_shader_;
    }
    _parameter.set_return(js_value::create(js_context, arr, arr_size));
}