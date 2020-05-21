
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
    auto shader = js_class_extract::extract<
        render_context_3d_shader>(_0);
    if (!shader || !shader->is_useable()) return;
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto pname = (uint32_t)_1.to_int32();

    auto js_context = _parameter.get_context();
    if (DWL_DELETE_STATUS == pname) {
        _parameter.set_return(js_value::create(
            js_context, shader->is_deleted()));
    } 
    else if (DWL_COMPILE_STATUS == pname) {
        bool status = (shader->state_ == 
            render_context_3d_shader_state::_compile_success_);
        _parameter.set_return(
            js_value::create(js_context, status));
    } 
    else if (DWL_SHADER_TYPE == pname) {
        int32_t type = DWL_NONE;
        if (shader->class_ == 
            render_context_3d_shader_class::_vs_) {
            type = DWL_VERTEX_SHADER;
        }
        else if (shader->class_ ==
            render_context_3d_shader_class::_fs_) {
            type = DWL_FRAGMENT_SHADER;
        }
        _parameter.set_return(
            js_value::create(js_context, type));
    } 
    else {
        ;
    }
}