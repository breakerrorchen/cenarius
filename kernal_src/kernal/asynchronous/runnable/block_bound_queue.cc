
#include "block_bound_queue.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

runnable_block_bound_queue::runnable_block_bound_queue(uint32_t max_size) {
    bound_ = max_size;
}

void runnable_block_bound_queue::commit(std::function<void()> task) {
    if (task) {
        std::unique_lock<std::mutex> locker(mutex_);
        while (count_ + 1 == bound_) {
            not_full_.wait(locker);
        }
        ++count_;
        inner_queue_.push(task); not_empty_.notify_one();
    }
}

void runnable_block_bound_queue::wake(bool all) {
    {
        std::unique_lock<std::mutex> locker(mutex_);
        is_should_wake_ = true;
    }
    not_empty_.notify_one();
}

void runnable_block_bound_queue::wait(std::function<void()>& ret) {
    std::unique_lock<std::mutex> locker(mutex_);
    while (inner_queue_.empty() || !is_should_wake_) {
        not_empty_.wait(locker);
    }
    if (is_should_wake_) { is_should_wake_ = false; }
    if (!inner_queue_.empty()) {
        ret = inner_queue_.front(); inner_queue_.pop();
        --count_;
        not_full_.notify_one();
    }
}

void runnable_block_bound_queue::try_wait(std::function<void()>& ret) {
    std::lock_guard<std::mutex> _guard(mutex_);
    if (!inner_queue_.empty()) {
        ret = inner_queue_.front(); inner_queue_.pop();
        --count_;
        not_full_.notify_one();
    }
}