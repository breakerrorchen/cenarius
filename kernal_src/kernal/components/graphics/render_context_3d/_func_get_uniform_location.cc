
#include "common/cxx_str_tools.h"
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_uniform_location/_.h"
#include "_.h"
using namespace cenarius;
using namespace common_base;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      WebGLUniformLocation = WebGLRenderingContext.getUniformLocation(program, name);
 *
 * program
 *      The WebGLProgram in which to locate the specified uniform variable.
 *
 * name
 *      A DOMString specifying the name of the uniform variable whose location 
 *      is to be returned. The name can't have any whitespace in it, 
 *      and you can't use this function to get the location of any uniforms starting 
 *      with the reserved string "gl_", since those are internal to the WebGL layer.
 *
 *      The possible values correspond to the uniform names returned by getActiveUniform; 
 *      see that function for specifics on 
 *      how declared uniforms map to uniform location names.
 *      
 *      Additionally, for uniforms declared as arrays, the following names are also valid:
 *          The uniform name without the [0] suffix. 
 *              E.g. the location returned for arrayUniform 
 *              is equivalent to the one for arrayUniform[0].
 *          The uniform name indexed with an integer. 
 *              E.g. the location returned for arrayUniform[2] 
 *              would point directly to the third entry of the arrayUniform uniform.
 *
 * Return value
 *      A WebGLUniformLocation value indicating the location of the named variable, 
 *      if it exists. If the specified variable doesn't exist, null is returned instead.
 */
void render_context_3d::get_uniform_location(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    auto _context = _parameter.get_context();
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    auto _program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (nullptr == _program || !_1.is_str()) return;
    static std::string array_ending("[0]");
    auto cxx_name = _1.to_string();
    if (str_tools::end_with(cxx_name, array_ending)) {
        cxx_name.resize(cxx_name.length() - 3);
    }

    auto& all_uniforms = _program->reflection_.uniforms_;
    int32_t location_index = -1;
    for (auto& item: all_uniforms) {
        if (item.name_ == cxx_name) {
            location_index = item.location_index_;
            break;
        }
    }
    if (-1 == location_index) return;
    auto _obj = thread_related->cls_render_3d_uniform_location_
        .create_new_instance(_context);
    if (!_obj.is_useable()) return;
    render_context_3d_uniform_location* _instance = nullptr;
    _obj.hold_native_data(i_runtime_container<
        render_context_3d_uniform_location>::create(&_instance));
    _instance->location_ = (uint32_t)location_index;
    _parameter.set_return((js_value)_obj);
}