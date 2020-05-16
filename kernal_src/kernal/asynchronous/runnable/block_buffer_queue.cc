
#include "block_buffer_queue.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

runnable_block_buffer_queue::runnable_block_buffer_queue() {
    in_ = &(inner_queue_[0]); out_ = &(inner_queue_[1]);
}

void runnable_block_buffer_queue::commit(
    std::function<void()> task) {
    if (task) {
        std::lock_guard<std::mutex> _guard(mutex_);
        in_->push(task); cond_var_.notify_one();
    }
}

void runnable_block_buffer_queue::wake(bool all) {
    {
        std::unique_lock<std::mutex> locker(mutex_);
        in_->push([]() {});
    }

    if (!all) {
        cond_var_.notify_one();
    } else {
        cond_var_.notify_all();
    }
}

uint32_t runnable_block_buffer_queue::drained() {
    {
        std::unique_lock<std::mutex> locker(mutex_);
        while (in_->empty()) {
            cond_var_.wait(locker);
        }
        std::swap(in_, out_);
    }
    
    uint32_t num = (uint32_t)out_->size();
    while (!out_->empty()) {
        out_->front()(); out_->pop();
    }
    return num;
}