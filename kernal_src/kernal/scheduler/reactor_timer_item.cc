
#include "reactor_timer_item.h"
using namespace cenarius;
using namespace kernal;
using namespace scheduler;

reactor_timer_item::reactor_timer_item(const reactor_timer_item& from) {
    operator=(from);
}

reactor_timer_item::reactor_timer_item(reactor_timer_item&& from) {
    operator=(std::move(from));
}

reactor_timer_item& reactor_timer_item::operator=(const reactor_timer_item& from) {
    if (this != &from) {
        loop_             = from.loop_;
        id_               = from.id_;
        timeout_time_     = from.timeout_time_; 
        interval_         = from.interval_;
        timeout_callback_ = from.timeout_callback_;
    }
    return *this;
}

reactor_timer_item& reactor_timer_item::operator=(reactor_timer_item&& from) {
    if (this != &from) {
        loop_               = from.loop_;
        interval_           = from.interval_;
        timeout_time_       = from.timeout_time_;
        id_                 = from.id_;
        from.loop_          = false;
        from.interval_      = 0;
        from.timeout_time_  = 0;
        from.id_            = 0;
        timeout_callback_   = std::move(from.timeout_callback_);
    }
    return *this;
}