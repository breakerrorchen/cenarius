
#include "batch_container.h"
using namespace cenarius;
using namespace kernal;
using namespace scheduler;

batch_timer_container::batch_timer_item::batch_timer_item(
    const batch_timer_item& from) {
    operator=(from);
}

batch_timer_container::batch_timer_item::batch_timer_item(
    batch_timer_container::batch_timer_item&& from) {
    operator=(std::move(from));
}

batch_timer_container::batch_timer_item& batch_timer_container
    ::batch_timer_item::operator=(
    const batch_timer_container::batch_timer_item& from) {
    if (this != &from) {
        index_id_ = from.index_id_; callback_ = from.callback_;
    }
    return *this;
}

batch_timer_container::batch_timer_item& 
    batch_timer_container::batch_timer_item::operator=(
    batch_timer_container::batch_timer_item&& from) {
    if (this != &from) {
        index_id_ = from.index_id_; from.index_id_ = 0;
        callback_ = std::move(from.callback_);
    }
    return *this;
}

batch_timer_container::batch_timer_container() {
    timer_begin_ = high_resolution_clock::now();
}

uint32_t batch_timer_container::add(
    std::function<void(uint32_t)> callback) {
    if (callback) {
        batch_timer_item item;
        item.callback_ = callback; item.index_id_ = ++id_;
        in_.push_back(item);
    }
    return 0;
}

void batch_timer_container::call() {
    out_.swap(in_);
    if (!out_.empty()) {
        auto end = steady_clock::now();
        auto current = (uint32_t)duration_cast<
            milliseconds>(end - timer_begin_).count();
        for (auto& item: out_) {
            item.callback_(current);
        }
        out_.clear();
    }
}

void batch_timer_container::cancel(uint32_t index_id) {
    for (auto& item: in_) {
        if (item.index_id_ == index_id) {
            item.index_id_ = 0;
            item.callback_ = nullptr;
            break;
        }
    }

    for (auto& item: out_) {
        if (item.index_id_ == index_id) {
            item.index_id_ = 0;
            item.callback_ = nullptr;
            break;
        }
    }
}

void batch_timer_container::dispose() {
    in_.clear(); out_.clear();
}