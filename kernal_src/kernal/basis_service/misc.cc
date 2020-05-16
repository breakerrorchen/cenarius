
#include "misc.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace service;

misc::misc() {
    queue_ = std::make_shared<runnable_block_queue>();
    auto raw_queue = queue_;
    auto thread = std::thread([raw_queue]() {
        while (true) {
            std::function<void()> runnable;
            raw_queue->wait(runnable);
            if (runnable) {
                runnable();
            }
        }
    });
    thread_.swap(thread);
}

void misc::commit(std::function<void()> task) {
    if (!task) return;
    static misc _instance;
    _instance.queue_->commit(task);
}