
#include "../render_context_3d_buffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * WebGL1: 
 * void gl.bufferData(target, size, usage); 
 * void gl.bufferData(target, ArrayBuffer? srcData, usage); 
 * void gl.bufferData(target, ArrayBufferView srcData, usage); 

 * WebGL2: 
 * void gl.bufferData(target, ArrayBufferView srcData, usage, srcOffset, length);
 */
void render_context_3d::buffer_data(js_parameter& _parameter) {
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

    auto _2 = _parameter.get_argument_at(2);
    if (!_2.is_number()) return;
    auto usage = (uint32_t)_2.to_int32();
    if (DWL_STATIC_DRAW  != target &&
        DWL_DYNAMIC_DRAW != target &&
        DWL_STREAM_DRAW  != target) {
        return;
    }

    auto _1 = _parameter.get_argument_at(1);

    // WebGL1:
    // void gl.bufferData(target, size, usage); 
    if (_1.is_number()) {
        auto size = (uint32_t)_1.to_int32();
        struct __task__ {
            puppet_container<canvas_render_3d>* context_ = nullptr;
            uint32_t target_, usage_, buffer_size_ = 0;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
                auto raw_context = context_->data_;
                assert(raw_context);
                raw_context->buffer_data(target_, 
                    (intptr_t)buffer_size_, nullptr, usage_);
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        task->target_ = target;
        task->usage_  = usage;
        task->buffer_size_ = size;
        transmitter_->force_commit();

        // save buffer state
        raw_buffer->size_ = size; raw_buffer->usage_ = usage; 
    }

    // WebGL1:
    // void gl.bufferData(target, ArrayBuffer? srcData, usage);
    // void gl.bufferData(target, ArrayBufferView srcData, usage);
    else if (_1.is_typed_arr()) {
        auto buffer = _1.typedarr_buffer();
        struct __task__ {
            puppet_container<canvas_render_3d>* context_ = nullptr;
            uint32_t target_, usage_; std::vector<uint8_t> buffer_;
            void run(barrel_buffer*) {
                assert(context_ && context_->data_);
                auto raw_context = context_->data_;
                assert(raw_context);
                auto size = (intptr_t)(buffer_.size());
                raw_context->buffer_data(
                    target_, size, buffer_.data(), usage_);
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        task->target_ = target;
        task->usage_  = usage ;
        task->buffer_.resize(buffer.size_);
        if (buffer.size_ > 0) {
            assert(nullptr != buffer.addr_);
            memcpy(task->buffer_.data(), buffer.addr_, buffer.size_);
        }
        transmitter_->force_commit();

        // save buffer state
        raw_buffer->size_ = buffer.size_; raw_buffer->usage_ = usage; 
    }
}