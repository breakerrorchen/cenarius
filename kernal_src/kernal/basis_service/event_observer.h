// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "common/runtime_base.h"
#include "event_observer_watcher.h"
#include "event_observer_id.h"

namespace cenarius { namespace kernal { namespace service {
using namespace common_base;
using event_observer_callback = 
    std::function<void(uint32_t, std::shared_ptr<runtime_base>)>;
class event_observer final {
public:
    event_observer() = default;
    event_observer(const event_observer&) = delete;
    event_observer(event_observer&&) = delete;
    event_observer& operator=(const event_observer&) = delete;
    event_observer& operator=(event_observer&&) = delete;
    
public:
    static void setup_and_set_current();
    static void dispatch(uint32_t, std::shared_ptr<runtime_base>);
    static std::shared_ptr<event_observer_handle> listen(
        uint32_t, event_observer_callback);
    static void remove(uint32_t, int);
    static void remove(std::shared_ptr<event_observer_handle>);
    static void dispose();

public:
    struct event_observer_item {
        std::shared_ptr<event_observer_handle> handle_;
        event_observer_callback callback_;
    };
    std::map<uint32_t, std::vector<event_observer_item>> pool_;
};


}}}
