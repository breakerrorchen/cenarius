// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "event_observer_handle.h"

namespace cenarius { namespace kernal { namespace service {
class event_observer_watcher final {
    void* operator new(size_t) = delete;
public:
    event_observer_watcher() = default;
    ~event_observer_watcher();
    event_observer_watcher(const event_observer_watcher&);
    event_observer_watcher(event_observer_watcher&&);
    event_observer_watcher(std::shared_ptr<event_observer_handle>);
    event_observer_watcher& operator=(const event_observer_watcher&);
    event_observer_watcher& operator=(event_observer_watcher&&);
    event_observer_watcher& operator=(std::shared_ptr<event_observer_handle>);

public:
    operator std::shared_ptr<event_observer_handle>();
    bool cancel();
    bool is_still_listen() const;
    
public:
    void reset();

private:
    std::shared_ptr<event_observer_handle> handle_;
};


}}}
