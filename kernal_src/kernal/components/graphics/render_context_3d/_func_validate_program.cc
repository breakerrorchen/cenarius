
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
    auto _i = js_class_extract::extract<render_context_3d_program>(v);
    bool useable = _i && _i->is_useable();
    if (!useable) {
        _parameter.set_return(js_value::create(js_context, false));
    }
    useable = _i->reflection_.is_success_;
    _parameter.set_return(js_value::create(js_context, useable));
}