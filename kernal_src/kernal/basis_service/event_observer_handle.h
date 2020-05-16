// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace service {
class event_observer;
class event_observer_handle final {
    friend class event_observer;
public:
    bool cancel();
    bool is_still_listen() const;
private:
    uint32_t event_ = 0; int handle_index_ = -1;
};


}}}
