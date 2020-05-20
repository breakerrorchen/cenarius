
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.vertexAttribPointer(index, size, type, normalized, stride, offset);
 * 
 * index
 *      A GLuint specifying the index of the vertex attribute that is to be modified. 
 *  
 * size
 *      A GLint specifying the number of components per vertex attribute. 
 *      Must be 1, 2, 3, or 4.
 *
 * type
 *      A GLenum specifying the data type of each component in the array. 
 *      Possible values:
 *          gl.BYTE: signed 8-bit integer, with values in [-128, 127]
 *          gl.SHORT: signed 16-bit integer, with values in [-32768, 32767]
 *          gl.UNSIGNED_BYTE: unsigned 8-bit integer, with values in [0, 255]
 *          gl.UNSIGNED_SHORT: unsigned 16-bit integer, with values in [0, 65535]
 *          gl.FLOAT: 32-bit IEEE floating point number
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.HALF_FLOAT: 16-bit IEEE floating point number
 *
 * normalized
 *      A GLboolean specifying whether integer data values should be normalized 
 *      into a certain range when being cast to a float.
 *          For types gl.BYTE and gl.SHORT, normalizes the values to [-1, 1] if true.
 *          For types gl.UNSIGNED_BYTE and gl.UNSIGNED_SHORT, 
 *              normalizes the values to [0, 1] if true.
 *          For types gl.FLOAT and gl.HALF_FLOAT, this parameter has no effect.
 * 
 * stride
 *      A GLsizei specifying the offset in bytes between the beginning of consecutive 
 *      vertex attributes. Cannot be larger than 255. 
 *      If stride is 0, the attribute is assumed to be tightly packed, that is, 
 *      the attributes are not interleaved but each attribute is in a separate block, 
 *      and the next vertex' attribute follows immediately after the current vertex.
 *
 * offset
 *      A GLintptr specifying an offset in bytes of the first component in the vertex 
 *      attribute array. Must be a multiple of the byte length of type. 
 *
 * Return value
 *      None.
 *
 * Errors thrown
 *      A gl.INVALID_VALUE error is thrown if offset is negative.
 *      A gl.INVALID_OPERATION error is thrown if stride and offset are not multiples 
 *          of the size of the data type.
 *      A gl.INVALID_OPERATION error is thrown 
 *          if no WebGLBuffer is bound to the ARRAY_BUFFER target.
 *      When using a WebGL 2 context, a gl.INVALID_OPERATION error is thrown 
 *          if this vertex attribute is defined as a integer in the vertex shader 
 *          (e.g. uvec4 or ivec4, instead of vec4).
 */
void render_context_3d::vertex_attrib_pointer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() < 6) return;
    if (!context_cache_.raw_arraybuffer_bind_) return;
    auto index = (uint32_t)_parameter[0].to_int32();
    if (index >= 64 || render_attitude_->max_vertex_attribs_ <= index) {
        return;
    }
    auto size = _parameter[1].to_int32();
    if (1 != size && 2 != size && 3 != size && 4 != size) {
        return;
    }
    auto type = (uint32_t)_parameter[2].to_int32();
    if (DWL_BYTE            != type && 
        DWL_SHORT           != type && 
        DWL_UNSIGNED_BYTE   != type &&
        DWL_UNSIGNED_SHORT  != type &&
        DWL_FLOAT           != type) {
        return;
    }
    auto normalized = _parameter[3].to_bool();
    auto stride = _parameter[4].to_int32();
    if (stride < 0 || stride >= 255) return;
    
    auto offset = _parameter[5].to_int32();
    if (DWL_SHORT == type) {
        if (0 != offset % 2) return;
    } else if (DWL_UNSIGNED_SHORT == type) {
        if (0 != offset % 2) return;
    } else if (DWL_FLOAT == type) {
        if (0 != offset % 4) return;
    }

    auto& item = context_cache_.attrib_pointer_[index];
    item.buffer_     = context_cache_.arraybuffer_bind_;
    item.raw_buffer_ = context_cache_.raw_arraybuffer_bind_;
    item.size_       = size;
    item.type_       = type;
    item.stride_     = stride;
    item.offset_     = offset;

    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        uint32_t index_, type_; int32_t size_;
        bool normalized_; uint32_t stride_, offset_;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            void* offset = (void*)((char*)0 + offset_);
            raw_context->vertex_attrib_pointer(index_, 
                size_, type_,normalized_, stride_, offset);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->index_      = index;
    task->size_       = size;
    task->type_       = type;
    task->normalized_ = normalized;
    task->stride_     = stride;
    task->offset_     = offset;
    task->context_    = raw_context_.get();
}