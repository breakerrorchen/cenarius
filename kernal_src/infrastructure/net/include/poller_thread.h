
#pragma once
#include "poller.h"
#include "io_committer.h"

namespace cenarius { namespace infrastructure { namespace net {
class poller_thread final : public io_committer 
    , public std::enable_shared_from_this<poller_thread> {
public:
    poller_thread();
    poller_thread(const poller_thread&) = delete;
    poller_thread(poller_thread&&) = delete;
    poller_thread& operator=(const poller_thread&) = delete;
    poller_thread& operator=(poller_thread&&) = delete;

public:
    void post(std::function<void(poller*)> task) override {
        if (task) {
            poller_thread::try_post(task);
        }
    }
    /**
     * Notify and execute asynchronous tasks
     * */
    bool try_post(std::function<void(poller*)>);

public:
    // start thread and start poller loop
    void start();
        
    // stop thread and wait thread exit
    void stop(std::function<void()>, bool wait = true);

private:
    std::thread loop_thread_; std::shared_ptr<poller> poller_;
};


}}}