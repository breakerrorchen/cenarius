
#include "../render_context_3d_active_info/_.h"
#include "../render_context_3d_program/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      WebGLActiveInfo gl.getActiveAttrib(program, index);
 * 
 * program
 *      A WebGLProgram containing the vertex attribute.
 * 
 * index
 *      A GLuint specifying the index of the vertex attribute to get. 
 *      This value is an index 0 to N - 1 as returned 
 *      by gl.getProgramParameter(program, gl.ACTIVE_ATTRIBUTES).
 * 
 * Return value
 *      A WebGLActiveInfo object.
 */
void render_context_3d::get_active_attrib(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto program = js_class_extract::extract<
        render_context_3d_program>(_0);
    if (!program || !program->is_useable()) return;
    if (!program->reflection_.is_success_)  return;
    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto& attribs = program->reflection_.attribs_;
    auto index = _1.to_int32();
    if (index < 0 || index > attribs.size()) return;
    auto& item = attribs[index];
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    auto js_context = _parameter.get_context();
    auto _obj = thread_related->cls_render_3d_active_info_
        .create_new_instance(js_context);
    render_context_3d_active_info* _instance = nullptr;
    _obj.hold_native_data(i_runtime_container<
        render_context_3d_active_info>::create(&_instance));
    assert(nullptr != _instance);
    _instance->name_ = item.name_;
    _instance->type_ = item.type_;
    _instance->size_ = item.size_;
    _parameter.set_return((js_value)_obj);
}