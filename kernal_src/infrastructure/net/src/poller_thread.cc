
#include "poller_thread.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

poller_thread::poller_thread() {
    ;
}

bool poller_thread::try_post(std::function<void(poller*)> task) {
    assert(poller_);
    if (task && poller_) {
        poller_->post(task); return true;
    }
    return false;
}

void poller_thread::start() {
    std::mutex locker; std::condition_variable cond_var;
    auto _protected_self = shared_from_this();
    bool _thread_ready = false;
    auto _thread = std::thread([
        _protected_self, &_thread_ready, &cond_var, &locker]() {
        _protected_self->poller_ = std::make_shared<poller>();
        {
            std::lock_guard<std::mutex> guard(locker);
            _thread_ready = true;
        }
        cond_var.notify_one();
        _protected_self->poller_->start();
    });
    std::unique_lock<std::mutex> guard(locker);
    cond_var.wait(guard, [&]{ return _thread_ready; });
    loop_thread_.swap(_thread);
}

void poller_thread::stop(std::function<void()> task, bool wait) {
    assert(poller_);
    if (poller_) { poller_->stop(task); }
    wait? loop_thread_.join(): loop_thread_.detach();
}