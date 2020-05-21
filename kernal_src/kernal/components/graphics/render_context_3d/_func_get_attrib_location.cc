
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      GLint gl.getAttribLocation(program, name);
 * 
 * program
 *      A WebGLProgram containing the attribute variable.
 * 
 * name
 *      A DOMString specifying the name of the 
 *      attribute variable whose location to get.
 * 
 * Return value
 *      A GLint number indicating the 
 *      location of the variable name if found. Returns -1 otherwise.
 */
void render_context_3d::get_attrib_location(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    auto js_context = _parameter.get_context();
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_str()) {
        _parameter.set_return(
            js_value::create(js_context, (int32_t)_1));
        return;
    }

    int32_t attrib_location = -1;
    auto cxx_name = _1.to_string();
    for (auto& item: program->reflection_.attribs_) {
        if (item.name_ == cxx_name) {
            attrib_location = item.location_index_;
        }
    }
    _parameter.set_return(
        js_value::create(js_context, attrib_location));
}