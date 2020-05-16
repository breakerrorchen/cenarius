
#include "../render_context_3d_buffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      void gl.bindBuffer(target, buffer);
 *
 * target
 *      A GLenum specifying the binding point (target). Possible values:
 *          gl.ARRAY_BUFFER:                Buffer containing vertex attributes, such as vertex 
 *              coordinates, texture coordinate data, or vertex color data.
 *          gl.ELEMENT_ARRAY_BUFFER:        Buffer used for element indices.
 *      When using a WebGL 2 context, the following values are available additionally:
 *          gl.COPY_READ_BUFFER:            Buffer for copying from one buffer object to another.
 *          gl.COPY_WRITE_BUFFER:           Buffer for copying from one buffer object to another.
 *          gl.TRANSFORM_FEEDBACK_BUFFER:   Buffer for transform feedback operations.
 *          gl.UNIFORM_BUFFER:              Buffer used for storing uniform blocks.
 *          gl.PIXEL_PACK_BUFFER:           Buffer used for pixel transfer operations.
 *          gl.PIXEL_UNPACK_BUFFER:         Buffer used for pixel transfer operations.
 * 
 * buffer
 *      A WebGLBuffer to bind.
 * 
 * Return value
 *      None.
 * 
 * Exceptions
 *      Only one target can be bound to a given WebGLBuffer. An attempt to bind the buffer to 
 *      another target will throw an INVALID_OPERATION error 
 *      and the current buffer binding will remain the same.
 * 
 *      A WebGLBuffer which has been marked for deletion with deleteBuffer cannot be 
 *      (re-)bound. An attempt to do so will generate an INVALID_OPERATION error, 
 *      and the current binding will remain untouched.
 */
void render_context_3d::bind_buffer(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 2) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_ARRAY_BUFFER != target && DWL_ELEMENT_ARRAY_BUFFER != target) {
        return;
    }
    auto _1 = _parameter.get_argument_at(1);
    auto buffer = js_class_extract::extract<
        render_context_3d_buffer>(_1);
    if (buffer && !buffer->is_useable()) {
        buffer = nullptr;
    }

    if (nullptr == buffer) {
        if (DWL_ARRAY_BUFFER == target) {
            context_cache_.raw_arraybuffer_bind_ = nullptr;
            context_cache_.arraybuffer_bind_.reset();
        } else if (DWL_ELEMENT_ARRAY_BUFFER == target) {
            context_cache_.raw_element_arraybuffer_bind_ = nullptr;
            context_cache_.element_arraybuffer_bind_.reset();
        }

        struct __task__ {
            puppet_container<canvas_render_3d>* context_ = nullptr;
            uint32_t target_ = 0;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
                auto raw_context = context_->data_;
                assert(raw_context);
                raw_context->bind_buffer(target_, 0);
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->target_  = target;
            task->context_ = raw_context_.get();
        }
    } else {
        if (DWL_ARRAY_BUFFER == target) {
            context_cache_.raw_arraybuffer_bind_ = buffer;
            context_cache_.arraybuffer_bind_ = _1;
        } else if (DWL_ELEMENT_ARRAY_BUFFER == target) {
            context_cache_.raw_element_arraybuffer_bind_ = buffer;
            context_cache_.element_arraybuffer_bind_ = _1;
        }

        struct __task__ {
            puppet_container<canvas_render_3d>* context_ = nullptr;
            uint32_t target_ = 0, *buffer_ = nullptr;
            void run(barrel_buffer*) {
                assert(buffer_);
                assert(context_ && context_->data_);
                auto raw_context = context_->data_;
                assert(raw_context);
                raw_context->bind_buffer(target_, *buffer_);
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        task->target_  = target;
        task->buffer_  = buffer->related_value_;
        task->context_ = raw_context_.get();
    }
}