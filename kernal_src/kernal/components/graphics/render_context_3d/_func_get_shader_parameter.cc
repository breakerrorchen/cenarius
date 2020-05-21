
#include "../render_context_3d_shader/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getShaderParameter(shader, pname);
 * 
 * shader
 *      A WebGLShader to get parameter information from.
 *
 * pname
 *      A GLenum specifying the information to query. Possible values:
 *          gl.DELETE_STATUS: Returns a GLboolean indicating whether 
 *              or not the shader is flagged for deletion.
 *          gl.COMPILE_STATUS: Returns a GLboolean indicating whether 
 *              or not the last shader compilation was successful.
 *          gl.SHADER_TYPE: Returns a GLenum indicating whether 
 *              the shader is a vertex shader (gl.VERTEX_SHADER) 
 *              or fragment shader (gl.FRAGMENT_SHADER) object.
 * 
 *  Return value
 *      Returns the requested shader information (as specified with pname).
 */
void render_context_3d::get_shader_parameter(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _i = js_class_extract::extract<render_context_3d_shader>(_0);
    if (!_i || !_i->is_useable()) return;
    auto _1 = _parameter.get_argument_at(1);
    
}