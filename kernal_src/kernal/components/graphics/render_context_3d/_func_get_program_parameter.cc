
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getProgramParameter(program, pname);
 * 
 * program
 *      A WebGLProgram to get parameter information from.
 * 
 * pname
 *     A Glenum specifying the information to query. Possible values:
 *      gl.DELETE_STATUS: Returns a GLboolean indicating whether 
 *          or not the program is flagged for deletion.
 *      gl.LINK_STATUS: Returns a GLboolean indicating whether 
 *          or not the last link operation was successful.
 *      gl.VALIDATE_STATUS: Returns a GLboolean indicating whether 
 *          or not the last validation operation was successful.
 *      gl.ATTACHED_SHADERS: Returns a GLint indicating the number 
 *          of attached shaders to a program.
 *      gl.ACTIVE_ATTRIBUTES: Returns a GLint indicating the number 
 *          of active attribute variables to a program.
 *      gl.ACTIVE_UNIFORMS: Returns a GLint indicating the number 
 *          of active uniform variables to a program.
 *      When using a WebGL 2 context, 
 *          the following values are available additionally:
 *          gl.TRANSFORM_FEEDBACK_BUFFER_MODE: Returns a GLenum indicating 
 *              the buffer mode when transform feedback is active. 
 *              May be gl.SEPARATE_ATTRIBS or gl.INTERLEAVED_ATTRIBS.
 *          gl.TRANSFORM_FEEDBACK_VARYINGS: 
 *              Returns a GLint indicating the number 
 *              of varying variables to capture in transform feedback mode.
 *          gl.ACTIVE_UNIFORM_BLOCKS: Returns a GLint indicating the 
 *              number of uniform blocks containing active uniforms.
 *  Return value
 *      Returns the requested program information (as specified with pname).
 */
void render_context_3d::get_program_parameter(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;

    auto js_context = _parameter.get_context();
    auto& reflection = program->reflection_;
    auto pname = (uint32_t)_1.to_int32();
    if (DWL_DELETE_STATUS == pname) {
        _parameter.set_return(js_value::create(
            js_context, program->is_deleted()));
    }
    else if (DWL_LINK_STATUS == pname) {
        _parameter.set_return(js_value::create(
            js_context, reflection.is_linked_));
    } 
    else if (DWL_VALIDATE_STATUS == pname) {
        _parameter.set_return(js_value::create(
            js_context, reflection.is_validate_));
    }
    else if (DWL_ATTACHED_SHADERS == pname) {
        int32_t num = 0;
        if (program->vs_shader_.is_useable()) {
            ++num;
        }
        if (program->fs_shader_.is_useable()) {
            ++num;
        }
        _parameter.set_return(
            js_value::create(js_context, num));
    } 
    else if (DWL_ACTIVE_ATTRIBUTES == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)reflection.attribs_.size()));
    } 
    else if (DWL_ACTIVE_UNIFORMS == pname) {
        _parameter.set_return(js_value::create(js_context, 
            (int32_t)reflection.active_uniforms_.size()));
    } 
    else {
        ;
    }
}