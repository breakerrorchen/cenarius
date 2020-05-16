
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous { 
class syncer_spin final {
public:
    inline void wait() { 
        while (!v_.load(std::memory_order_acquire)) { 
            ; 
        } 
    }
    inline void completed_notify() {
        v_.store(true, std::memory_order_release);
    }

    bool try_wait(uint32_t times = 100000) {
        while (true) {
            bool _v = v_.load(std::memory_order_acquire);
            if (times-- <= 0 || _v) {
                return _v;
            }
        }
        return false;
    }
protected:
    std::atomic<bool> v_ = ATOMIC_VAR_INIT(false);
};


}}}