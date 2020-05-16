
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * WebGL1: 
 * void gl.bufferSubData(target, offset, ArrayBuffer srcData); 
 * void gl.bufferSubData(target, offset, ArrayBufferView srcData); 

 * WebGL2: 
 * void gl.bufferSubData(target, dstByteOffset, ArrayBufferView srcData, srcOffset, length);
 */
void render_context_3d::buffer_sub_data(js_parameter& _parameter) {
    assert(transmitter_ && raw_context_ && render_attitude_);
    if (_parameter.get_argument_count() != 3) return;
    auto _0 = _parameter.get_argument_at(0);
    if (!_0.is_number()) return;
    auto target = (uint32_t)_0.to_int32();
    if (DWL_ARRAY_BUFFER != target && 
        DWL_ELEMENT_ARRAY_BUFFER != target) {
        return;
    }

    auto _1 = _parameter.get_argument_at(1);
    if (!_1.is_number()) return;
    auto offset = _1.to_int32();

    auto _2 = _parameter.get_argument_at(2);
    auto buffer = _2.typedarr_buffer();
    struct __task__ {
        puppet_container<canvas_render_3d>* context_ = nullptr;
        std::vector<uint8_t> buffer_;
        uint32_t target_; int32_t offset_ = 0;
        void run(barrel_buffer*) {
            assert(context_ && context_->data_);
            auto raw_context = context_->data_;
            assert(raw_context);
            auto size = (intptr_t)(buffer_.size());
            raw_context->buffer_sub_data(target_, 
                (intptr_t)offset_, size, buffer_.data());
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    task->target_ = target;
    task->offset_ = offset;
    task->buffer_.resize(buffer.size_);
    if (buffer.size_ > 0) {
        assert(nullptr != buffer.addr_);
        memcpy(task->buffer_.data(), buffer.addr_, buffer.size_);
    }
    transmitter_->force_commit();
}