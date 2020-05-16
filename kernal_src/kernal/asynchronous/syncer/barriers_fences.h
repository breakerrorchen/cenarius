
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class barriers_fences final {
public:
    inline void force_mem_store() {
        v_.store(true, std::memory_order_release);
    }

    inline void force_mem_load() {
        v_.load(std::memory_order_acquire);
    }
    
private:
    std::atomic<bool> v_ = ATOMIC_VAR_INIT(false);
};


}}} // end => cenarius.kernal.asynchronous