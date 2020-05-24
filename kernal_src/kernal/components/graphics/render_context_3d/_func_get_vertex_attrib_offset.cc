
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      GLintptr gl.getVertexAttribOffset(index, pname);
 *
 * index
 *      A GLuint specifying the index of the vertex attribute.
 *
 * pname
 *      A GLenum which must be gl.VERTEX_ATTRIB_ARRAY_POINTER.
 *
 * Return value
 *      A GLintptr indicating the address of the vertex attribute.
 */
void render_context_3d::get_vertex_attrib_offset(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    uint32_t index = (uint32_t)_0.to_int32();
    if (index >= render_attitude_->max_vertex_attribs_ || index >= 64){
        return;
    }
    uint32_t pname = (uint32_t)_1.to_int32();
    if (DWL_VERTEX_ATTRIB_ARRAY_POINTER != pname) {
        return;
    }
    auto offset = (int32_t)context_cache_.vertex_attrib_[index].offset_;
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, offset));
}