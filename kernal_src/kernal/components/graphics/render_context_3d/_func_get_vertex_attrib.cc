
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
    
}