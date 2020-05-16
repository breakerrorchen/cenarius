
#include "poller.h"
#include "io_curl_stond.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

poller::poller() {
    static std::once_flag _once;
    std::call_once(_once, [&]() { curl_global_init(CURL_GLOBAL_ALL); });
    in_ = &(queue_[0]); out_ = &(queue_[1]);
    uv_loop_init(&looper_);
    uv_async_init(&looper_, &async_, [](uv_async_t* handle) {
        auto _this = reinterpret_cast<poller*>(handle->data);
        if (_this) {
            _this->atomic_queue_lock(true);
            std::swap(_this->in_, _this->out_);
            _this->atomic_queue_lock(false);
            auto task_queue = _this->out_;
            while (!task_queue->empty()) {
                task_queue->front()(_this);
                task_queue->pop_front();
            }
        }
    });
    async_.data = reinterpret_cast<void*>(this);
}

void poller::post(std::function<void(poller*)> task) {
    if (task) {
        atomic_queue_lock(true);
        in_->emplace_back(task); 
        atomic_queue_lock(false); 
        uv_async_send(&async_);
    }
}

void poller::start() {
    curl_handle_ = curl_multi_init();
    curl_multi_setopt(curl_handle_, CURLMOPT_SOCKETFUNCTION, &(curl_common::handle_socket));
    curl_multi_setopt(curl_handle_, CURLMOPT_SOCKETDATA, (void*)this);
    curl_multi_setopt(curl_handle_, CURLMOPT_TIMERFUNCTION,  &(curl_common::start_timeout));
    curl_multi_setopt(curl_handle_, CURLMOPT_TIMERDATA, (void*)this);
    uv_timer_init(&looper_, &timeout_); timeout_.data = reinterpret_cast<void*>(this);
    uv_run(&looper_, UV_RUN_DEFAULT); curl_multi_cleanup(curl_handle_);
}

void poller::stop(std::function<void()> task) {
    post([task {std::move(task)}](poller* _poller) {
        uv_stop(&(_poller->looper_));
        uv_loop_close(&(_poller->looper_));
        task? task(): (void)0;
    });
}

void poller::atomic_queue_lock(bool v) {
    if (v) {
        while(locker_.test_and_set(std::memory_order_acquire)) {
            ;
        }
    } else {
        locker_.clear(std::memory_order_release);
    }
}