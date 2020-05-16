
#include "event_observer.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace common_base;

thread_local std::shared_ptr<event_observer> _g_event_observer;
void event_observer::setup_and_set_current() {
    if (_g_event_observer) return;
    _g_event_observer = std::make_shared<event_observer>();
}

void event_observer::dispatch(
    uint32_t event, std::shared_ptr<runtime_base> data_ptr) {
    assert(_g_event_observer); if (!_g_event_observer) return;
    auto iter = _g_event_observer->pool_.find(event);
    if (_g_event_observer->pool_.end() == iter) return;
    for (auto& item: iter->second) {
        item.callback_(event, data_ptr);
    }
}

std::shared_ptr<event_observer_handle> event_observer::listen(
    uint32_t event, event_observer_callback callback) {
    assert(_g_event_observer); 
    if (!_g_event_observer || !callback) return nullptr;
    auto iter = _g_event_observer->pool_.find(event);
    if (_g_event_observer->pool_.end() == iter) {
        std::vector<event_observer_item>  vec;
        _g_event_observer->pool_[event] = vec;
        iter = _g_event_observer->pool_.find(event);
    }
    auto& sub_pools = iter->second;
    auto handle = std::make_shared<event_observer_handle>();
    handle->event_ = event; 
    handle->handle_index_ = sub_pools.size();
    sub_pools.push_back({handle, callback});
    return handle;
}

void event_observer::remove(uint32_t event, int index) {
    assert(_g_event_observer); 
    if (!_g_event_observer || index < 0) return;
    auto iter = _g_event_observer->pool_.find(event);
    if (_g_event_observer->pool_.end() == iter) return;
    auto& sub_pools = iter->second;
    auto sub_pool_size = sub_pools.size();
    if (index >= sub_pool_size) return;
    if (index < sub_pool_size -1) {
        sub_pools[index].handle_->handle_index_ = -1;
        sub_pools[index].callback_ = nullptr;
        sub_pools.back().handle_->handle_index_ = index;
        sub_pools[index] = sub_pools[sub_pool_size -1];
    }
    sub_pools.resize(sub_pool_size -1);
}

void event_observer::remove(
    std::shared_ptr<event_observer_handle> handle) {
    if (handle) {
        event_observer::remove(
            handle->event_, handle->handle_index_);
    }
}

void event_observer::dispose() {
    _g_event_observer = nullptr;
}