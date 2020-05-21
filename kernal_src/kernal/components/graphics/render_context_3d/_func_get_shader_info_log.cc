
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      gl.getShaderInfoLog(shader);
 * 
 * shader
 *      A WebGLShader to query.
 *
 *  Return value
 *      A DOMString that contains diagnostic messages, 
 *      warning messages, and other information about 
 *      the last compile operation. When a WebGLShader 
 *      object is initially created, its information 
 *      log will be a string of length 0.
 */
void render_context_3d::get_shader_info_log(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    auto shader = js_class_extract::extract<
        render_context_3d_shader>(v);
    if (!shader || !shader->is_useable()) return;
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, shader->compile_log_.c_str(), false));
}