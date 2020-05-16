
#include "queue.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

runnable_queue::runnable_queue() {
    in_ = &(inner_queue_[0]); out_ = &(inner_queue_[1]);
}

void runnable_queue::commit(std::function<void()> task) {
    if (task) {
        spinlocker_watcher wacher(locker_);
        in_->push(task);
    }
}

uint32_t runnable_queue::drained() {
    {
        spinlocker_watcher wacher(locker_);
        std::swap(in_, out_);
    }
    auto num = (uint32_t)out_->size();
    while (!out_->empty()) {
        out_->front()(); out_->pop();
    }
    return num;
}