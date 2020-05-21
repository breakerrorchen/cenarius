
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      DOMString gl.getShaderSource(shader);
 * 
 * shader
 *      A WebGLShader object to get the source code from.
 *
 *  Return value
 *      A DOMString containing the source code of the shader.
 */
void render_context_3d::get_shader_source(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    auto shader = js_class_extract::extract<
        render_context_3d_shader>(v);
    if (!shader || !shader->is_useable()) return;
    _parameter.set_return((js_value)shader->shader_source_);
}