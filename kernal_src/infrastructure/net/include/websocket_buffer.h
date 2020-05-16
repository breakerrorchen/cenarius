
#pragma once
#include "io_center.h"

namespace cenarius { namespace infrastructure { namespace net {
class websocket_buffer final {
public:
    websocket_buffer(uint32_t size = 2048);
public:
    uint32_t append(uint8_t*, uint32_t);
    uint32_t size() const;
    uint32_t offset(uint32_t);
    uint8_t* c_buffer() const;

private:
    std::vector<uint8_t> buffer_; 
    uint32_t offset_ = 0, size_ = 0;
};


}}}