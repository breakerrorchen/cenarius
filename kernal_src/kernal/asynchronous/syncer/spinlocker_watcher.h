
#pragma once
#include "common/base_header_inct.h"
#include "spinlocker.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class spinlocker_watcher final {
public:
    void* operator new(size_t) = delete;
    void  operator=   (const spinlocker_watcher&) = delete;
    void  operator=   (spinlocker_watcher&&) = delete;
    spinlocker_watcher() = delete;
    spinlocker_watcher(const spinlocker_watcher&) = delete;
    spinlocker_watcher(spinlocker_watcher&&) = delete;
    spinlocker_watcher(spinlocker& lock):locker_(lock) {
    	locker_.lock(true);
    }
    ~spinlocker_watcher() { locker_.lock(false); }

private:
    spinlocker& locker_;
};


}}}