
#include "barrel_buffer.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

barrel_buffer::barrel_buffer(uint32_t buffer_size) {
    buffer_.resize(buffer_size);
}

void barrel_buffer::execute() {
    auto raw_buffer = &(buffer_[0]);
    uint32_t cur = 0; 
    using callback_t = uint32_t(*)(void*, barrel_buffer*);
    auto observer = observer_.lock();
    if (observer) { 
        observer->on_start(); 
    }

    while (cur < offset_) { 
        auto current_buffer = raw_buffer + cur;
        auto data_ptr = current_buffer + sizeof(void*);
        auto offset = (*((callback_t*)
            current_buffer))((void*)data_ptr, this);
        cur += offset + sizeof(void*);
#if   __cenarius_32bit_cpu__
        cur = (((cur + 3) >> 2) << 2);
#elif __cenarius_64bit_cpu__
        cur = (((cur + 7) >> 3) << 3);
#endif
    }
    
    if (syncer_) {
        syncer_->completed_notify();
    }

    if (sync_promise_) {
        sync_promise_->set_value(0);
    }

    if (observer) { 
        observer->on_finish(); observer_.reset();
    }
    offset_ = 0; sync_promise_ = nullptr; syncer_ = nullptr;
}

void* barrel_buffer::offset_alloc(uint32_t size) {
    assert(0 != size);
    if (buffer_.size() - offset_ < size) {
        return nullptr;
    }
    auto data_ptr = &(buffer_[0]) + offset_;
#if   __cenarius_32bit_cpu__
    offset_ += size; offset_ = (((offset_ + 3) >> 2) << 2);
#elif __cenarius_64bit_cpu__
    offset_ += size; offset_ = (((offset_ + 7) >> 3) << 3);
#endif
    return (void*)data_ptr;
}