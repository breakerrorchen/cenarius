
#include "block_queue.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

void runnable_block_queue::commit(std::function<void()> task) {
    if (task) {
        std::lock_guard<std::mutex> _guard(mutex_);
        inner_queue_.push(task); cond_var_.notify_one();
    }
}

void runnable_block_queue::wake(bool all) {
    std::unique_lock<std::mutex> locker(mutex_);
    inner_queue_.push([](){});
    if (!all) {
        cond_var_.notify_one();
    } else {
        cond_var_.notify_all();
    }
}

void runnable_block_queue::wait(std::function<void()>& ret) {
    std::unique_lock<std::mutex> locker(mutex_);
    while (inner_queue_.empty()) {
        cond_var_.wait(locker);
    }
    ret = inner_queue_.front(); inner_queue_.pop();
}

void runnable_block_queue::try_wait(std::function<void()>& ret) {
    std::unique_lock<std::mutex> locker(mutex_);
    if (inner_queue_.empty()) return;
    ret = inner_queue_.front(); inner_queue_.pop();
}