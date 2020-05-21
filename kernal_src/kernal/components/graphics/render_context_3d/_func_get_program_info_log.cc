
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      gl.getProgramInfoLog(program);
 * 
 * program
 *      The WebGLProgram to query.
 * 
 * Return value
 *      A DOMString that contains diagnostic messages, 
 *      warning messages, and other information about 
 *      the last linking or validation operation. 
 *      When a WebGLProgram object is initially created, 
 *      its information log will be a string of length 0.
 */
void render_context_3d::get_program_info_log(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, program->reflection_.program_info_.c_str(), false));
}