
#include "event_observer.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace common_base;

bool event_observer_handle::cancel() {
    if (handle_index_ >= 0) {
        event_observer::remove(event_, handle_index_);
        handle_index_ = -1;
    }
    return true;
}

bool event_observer_handle::is_still_listen() const {
    return handle_index_ >= 0;
}