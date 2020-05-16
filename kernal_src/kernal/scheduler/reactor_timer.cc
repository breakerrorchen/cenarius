
#include "reactor_timer.h"
using namespace cenarius;
using namespace kernal;
using namespace scheduler;

reactor_timer::reactor_timer(const uint32_t size) {
    timer_pool_reserve_.reserve(size);
    timer_pool_.reserve(size);
    timer_begin_ = high_resolution_clock::now();
}

void reactor_timer::poll() {
    if (timer_pool_.empty()) return;
    if (is_need_make_heap_) {
        std::make_heap(timer_pool_.begin(), timer_pool_.end());
        is_need_make_heap_ = false;
    }
    auto current = reactor_timer::get_current_elapse();
    while (!timer_pool_.empty()) {
        auto& head_node = timer_pool_.front();
        if (head_node.timeout_time_ >= current) break;
        // call timeout callback        
        head_node.timeout_callback_();
        if (head_node.loop_) {
            timer_pool_reserve_.push_back(head_node);
        }
        std::pop_heap(timer_pool_.begin(), timer_pool_.end());
        timer_pool_.resize(timer_pool_.size() -1);
    }

    if (!timer_pool_reserve_.empty()) {
        for (auto& item: timer_pool_reserve_) {
            item.timeout_time_ = current + item.interval_;
            timer_pool_.push_back(item);
        }
        timer_pool_reserve_.clear(); is_need_make_heap_ = true;
    }
}

uint32_t reactor_timer::get_current_elapse() const {
    auto end = high_resolution_clock::now();
    return (uint32_t)duration_cast<
        milliseconds>(end - timer_begin_).count();
}

void reactor_timer::remove(const uint32_t timer_id) {
    int find_index = -1;
    for (int index = 1; index < timer_pool_.size(); ++index) {
        if (timer_id == timer_pool_[index].id_) {
            find_index = index; break;
        }
    }
    if (-1 == find_index) return;
    if (find_index == timer_pool_.size() -1) {
        timer_pool_.resize(timer_pool_.size() -1);
    } else {
        timer_pool_[find_index] = std::move(timer_pool_.back());
        timer_pool_.resize(timer_pool_.size() -1);
        is_need_make_heap_ = true;
    }
}

uint32_t reactor_timer::get_lastest_timeout_time() {
    if (!timer_pool_.empty()) return UINT32_MAX;
    if (is_need_make_heap_) {
        std::make_heap(timer_pool_.begin(), timer_pool_.end());
        is_need_make_heap_ = false;
    }
    auto timeout_time = 
        timer_pool_[0].timeout_time_ - get_current_elapse();
    return timeout_time? timeout_time: 0;
}

uint32_t reactor_timer::add(
    uint32_t time_ms, std::function<void()> callback, bool loop) {
    if (!callback) return 0;
    reactor_timer_item item;
    item.timeout_callback_ = callback;
    item.interval_         = time_ms;
    item.timeout_time_     = get_current_elapse() + time_ms;
    item.id_               = ++current_id_;
    item.loop_             = loop;
    timer_pool_.push_back((item)); is_need_make_heap_ = true;
    return current_id_;
}