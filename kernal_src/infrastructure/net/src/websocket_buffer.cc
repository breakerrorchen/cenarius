
#include "websocket_buffer.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

websocket_buffer::websocket_buffer(uint32_t size) {
    buffer_.resize(size);
}

uint32_t websocket_buffer::append(uint8_t* buffer, uint32_t size) {
    if (nullptr == buffer || 0 == size) { return size_; }
    if (size + size_ > buffer_.size()) {
        std::vector<uint8_t> new_buffer; 
        new_buffer.resize(size + size_);
        memcpy(&(new_buffer[0]), &(buffer_[0]) + offset_, size_);
        memcpy(&(new_buffer[0]) + size_, buffer, size);
        buffer_.swap(new_buffer);
        size_ = size + size_; offset_ = 0; 
    } else {
        if (buffer_.size() - offset_ - size_ < size) {
            memmove(&(buffer_[0]), &(buffer_[0]) + offset_, size_);
            memcpy(&(buffer_[0]) + size_, buffer, size);
            size_ = size + size_; offset_ = 0; 
        } else {
            memcpy(&(buffer_[0]) + offset_ + size_, buffer, size);
            size_ = size + size_;
        }
    }
    return size_;
}

uint32_t websocket_buffer::size() const {
    return size_;
}

uint32_t websocket_buffer::offset(uint32_t size) {
    assert(size <= size_);
    offset_ += size; size_ -= size;
    return size_;
}

uint8_t* websocket_buffer::c_buffer() const {
    if (buffer_.empty()) {
        return nullptr;
    }
    return (uint8_t*)((&(buffer_[0])) + offset_);
}