
#include "../render_context_3d_buffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getBufferParameter(target, pname);
 * 
 * target
 *  A Glenum specifying the target buffer object. Possible values:
 *      gl.ARRAY_BUFFER: Buffer containing vertex attributes, 
 *          such as vertex coordinates, texture coordinate data, or vertex color data.
 *      gl.ELEMENT_ARRAY_BUFFER: Buffer used for element indices.
 *  When using a WebGL 2 context, the following values are available additionally:
 *      gl.COPY_READ_BUFFER: Buffer for copying from one buffer object to another.
 *      gl.COPY_WRITE_BUFFER: Buffer for copying from one buffer object to another.
 *      gl.TRANSFORM_FEEDBACK_BUFFER: Buffer for transform feedback operations.
 *      gl.UNIFORM_BUFFER: Buffer used for storing uniform blocks.
 *      gl.PIXEL_PACK_BUFFER: Buffer used for pixel transfer operations.
 *      gl.PIXEL_UNPACK_BUFFER: Buffer used for pixel transfer operations.
 * 
 * pname
 *  A Glenum specifying information to query. Possible values:
 *      gl.BUFFER_SIZE: Returns a GLint indicating the size of the buffer in bytes.
 *      gl.BUFFER_USAGE: Returns a GLenum indicating the usage pattern of the buffer.
 *      This is either:
 *          gl.STATIC_DRAW,
 *          gl.DYNAMIC_DRAW,
 *          gl.STREAM_DRAW.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.STATIC_READ,
 *          gl.DYNAMIC_READ,
 *          gl.STREAM_READ,
 *          gl.STATIC_COPY,
 *          gl.DYNAMIC_COPY,
 *          gl.STREAM_COPY.
 * 
 * Return value
 *      Depends on the requested information (as specified with pname). 
 *      Either a GLint or a GLenum.
 */
void render_context_3d::get_buffer_parameter(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 3) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    render_context_3d_buffer* raw_buffer = nullptr;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_ARRAY_BUFFER == target) {
        raw_buffer = context_cache_.raw_arraybuffer_bind_;
    } else if (DWL_ELEMENT_ARRAY_BUFFER == target) {
        raw_buffer = context_cache_.raw_element_arraybuffer_bind_;
    } else {
        return;
    }
    if (nullptr == raw_buffer) return;

    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto pname = (uint32_t)_1.to_int32();
    if (DWL_BUFFER_SIZE == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(
            js_value::create(js_context, (int32_t)raw_buffer->size_ ));
    } else if (DWL_BUFFER_USAGE == pname) {
        auto js_context = _parameter.get_context();
        _parameter.set_return(
            js_value::create(js_context, (int32_t)raw_buffer->usage_));
    } else {
        ;
    }
}