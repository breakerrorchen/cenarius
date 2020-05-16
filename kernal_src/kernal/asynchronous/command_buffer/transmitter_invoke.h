// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "barrel_buffer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
template<typename cls> class command_transmitter_invoke final {
public:
    static uint32_t invoke(void* data_ptr, barrel_buffer* buffer) {
        auto cls_ptr = static_cast<cls*>(data_ptr);
        cls_ptr->run(buffer); cls_ptr->~cls();
        return sizeof(cls);
    }
};


}}}