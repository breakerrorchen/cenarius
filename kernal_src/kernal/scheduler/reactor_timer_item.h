
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace scheduler {
class reactor_timer_item final {
public:
    reactor_timer_item() = default;
    reactor_timer_item(const reactor_timer_item&);
    reactor_timer_item(reactor_timer_item&&);
    reactor_timer_item& operator=(const reactor_timer_item&);
    reactor_timer_item& operator=(reactor_timer_item&&);

public:
    std::function<void()>  timeout_callback_;
    bool loop_ = false;
    uint32_t interval_     = 0;
    uint32_t id_           = 0;
    uint32_t timeout_time_ = 0;

public:
    bool operator< (const reactor_timer_item& item) const {
        return timeout_time_ > item.timeout_time_;
    }    
};


}}}