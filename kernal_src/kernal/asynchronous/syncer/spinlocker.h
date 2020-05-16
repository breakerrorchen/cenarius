
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class spinlocker final {
public:
    inline void lock(bool v) {
        if (v) {
            while(locked_.test_and_set(std::memory_order_acquire)) {
                ;
            }
        } else {
            locked_.clear(std::memory_order_release);
        }
    }
    
protected:
    std::atomic_flag locked_ = ATOMIC_FLAG_INIT;
};


}}}