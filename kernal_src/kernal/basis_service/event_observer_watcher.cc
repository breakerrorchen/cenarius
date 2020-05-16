
#include "event_observer_watcher.h"
using namespace cenarius;
using namespace kernal;
using namespace service;

event_observer_watcher::~event_observer_watcher() { 
    reset(); 
}

event_observer_watcher::event_observer_watcher(
    const event_observer_watcher& from) {
    handle_ = from.handle_;
}

event_observer_watcher::event_observer_watcher(
    event_observer_watcher&& from) {
    handle_ = std::move(from.handle_);
}

event_observer_watcher::event_observer_watcher(
    std::shared_ptr<event_observer_handle> from) {
    handle_ = from;
}

event_observer_watcher& event_observer_watcher::operator=(
    const event_observer_watcher& from) {
    if (this != &from) {
        reset(); handle_ = from.handle_;
    }
    return *this;
}

event_observer_watcher& event_observer_watcher::operator=(
    event_observer_watcher&& from) {
    if (this != &from) {
        reset(); handle_ = std::move(from.handle_);
    }
    return *this;
}

event_observer_watcher& event_observer_watcher::operator=(
    std::shared_ptr<event_observer_handle> from) {
    reset();  handle_ = from;
    return *this;
}

event_observer_watcher::operator std::shared_ptr<
    event_observer_handle>() {
    return handle_;
}

bool event_observer_watcher::cancel() {
    if (handle_) {
        return handle_->cancel();
    }
    return false;
}

bool event_observer_watcher::is_still_listen() const {
    if (handle_) {
        return handle_->is_still_listen();
    }
    return false;
}

void event_observer_watcher::reset() {  
    if (handle_) { 
        handle_->cancel(); handle_ = nullptr; 
    } 
}