
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getVertexAttrib(index, pname);
 *
 * index
 *      A GLuint specifying the index of the vertex attribute.
 *
 * pname
 *      A GLenum specifying the information to query. 
 *      Possible values:
 *          gl.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: Returns the currently bound WebGLBuffer.
 *          gl.VERTEX_ATTRIB_ARRAY_ENABLED: Returns a GLboolean 
 *              that is true if the vertex attribute is enabled at this index. Otherwise false.
 *          gl.VERTEX_ATTRIB_ARRAY_SIZE: 
 *              Returns a GLint indicating the size of an element of the vertex array.
 *          gl.VERTEX_ATTRIB_ARRAY_STRIDE: Returns a GLint indicating the number of bytes 
 *              between successive elements in the array. 0 means that the elements are sequential.
 *          gl.VERTEX_ATTRIB_ARRAY_TYPE: Returns a GLenum representing the array type. 
 *          One of
 *              gl.BYTE
 *              gl.UNSIGNED_BYTE
 *              gl.SHORT
 *              gl.UNSIGNED_SHORT
 *              gl.FLOAT
 *          gl.VERTEX_ATTRIB_ARRAY_NORMALIZED: Returns a GLboolean that is true if fixed-point 
 *              data types are normalized for the vertex attribute array at the given index.
 *          gl.CURRENT_VERTEX_ATTRIB: Returns a Float32Array (with 4 elements) representing 
 *              the current value of the vertex attribute at the given index.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.VERTEX_ATTRIB_ARRAY_INTEGER: Returns a GLboolean indicating whether or not 
 *              an integer data type is in the vertex attribute array at the given index.
 *          gl.VERTEX_ATTRIB_ARRAY_DIVISOR: Returns a GLint describing the frequency divisor 
 *              used for instanced rendering.
 *      When using the ANGLE_instanced_arrays extension:
 *          ext.VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE: 
 *              Returns a GLint describing the frequency divisor used for instanced rendering.
 * Return value
 *      Returns the requested vertex attribute information (as specified with pname).
 */
void render_context_3d::get_vertex_attrib(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    auto _1 = _parameter.get_argument_at(1);
    if (!_0.is_number() || !_1.is_number()) return;
    auto index = _0.to_int32();
    if (index < 0 || index >= 64 || 
        index >= render_attitude_->max_vertex_attribs_) {
        return;
    }
    auto& vertex_attrib = context_cache_.vertex_attrib_[index];

    auto js_context = _parameter.get_context();
    auto pname = (uint32_t)_1.to_int32();
    if (DWL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING == pname) {
        _parameter.set_return(
            (js_value)(vertex_attrib.buffer_));
    }
    else if (DWL_VERTEX_ATTRIB_ARRAY_ENABLED == pname) {
        _parameter.set_return(js_value::create(
            js_context, (bool)vertex_attrib.enable_));
    }
    else if (DWL_VERTEX_ATTRIB_ARRAY_SIZE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)vertex_attrib.size_));
    }
    else if (DWL_VERTEX_ATTRIB_ARRAY_STRIDE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)vertex_attrib.stride_));
    }
    else if (DWL_VERTEX_ATTRIB_ARRAY_TYPE == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)vertex_attrib.type_));
    }
    else if (DWL_VERTEX_ATTRIB_ARRAY_NORMALIZED == pname) {
        _parameter.set_return(js_value::create(
            js_context, (int32_t)vertex_attrib.normalized_));
    }
    else if (DWL_CURRENT_VERTEX_ATTRIB == pname) {
        i_typedarr_buffer buffer; float data[4];
        buffer.addr_ = (void*)data;
        buffer.size_ = sizeof(float) * 4;
        data[0] = vertex_attrib.data_[0];
        data[1] = vertex_attrib.data_[1];
        data[2] = vertex_attrib.data_[2];
        data[3] = vertex_attrib.data_[3];
        _parameter.set_return(
            js_value::create_typed_arr_float32(
            js_context, &buffer));
    }
    else {
        ;
    }
}