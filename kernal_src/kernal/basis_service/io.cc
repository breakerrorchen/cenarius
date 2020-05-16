
#include "io.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace service;

io::io() {
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

void io::commit(std::function<void()> task) {
    if (!task) return;
    static io _instance;
    _instance.queue_->commit(task);
}