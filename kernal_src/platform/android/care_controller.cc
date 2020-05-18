#include "common/logger.h"
#include "care_controller.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace cc;
using namespace platform;

#define __wake_event_fd__(fd)                       \
    {                                               \
        uint64_t u = 1;                             \
        ::write(fd, &u, sizeof(uint64_t));          \
    }

#define __reset_event_fd__(fd)                      \
    {                                               \
        uint64_t u = 0;                             \
        ::read(fd, &u, sizeof(uint64_t));           \
    }

/**
 * 给上层控制器线程提供跨平台的接口支持
 * 给上层提供三方面的支持：
 * 1. 提供一个异步队列, 用来做线程切换和异步任务
 * 2. 提供对vscyn分发的支持
 * 3. 提供poll超时服务，提供给上层用以做定时器
 * */
care_controller_i::care_controller_i() {
    queue_ = std::make_shared<runnable_queue>();
    vsync_event_fd_ = ::eventfd(0, EFD_CLOEXEC|EFD_NONBLOCK);
	event_fd_ = ::eventfd(0, EFD_CLOEXEC|EFD_NONBLOCK);
}

care_controller_i::~care_controller_i() {
    if (native_looper_) {
        ::ALooper_release(native_looper_);
    }
    ::close(event_fd_); ::close(vsync_event_fd_);
    __log_error("%s %d", __FILE__, __LINE__);
}

void care_controller_i::vsync_dispatch() {
    __wake_event_fd__(vsync_event_fd_);
}

void care_controller_i::commit(std::function<void()> task) {
    assert(queue_);
    if (task) {
        // 提交异步任务，并唤醒android looper
        queue_->commit(task); __wake_event_fd__(event_fd_);
    }
}

/**
 * 通过控制器线程来触发，这里构建Android Looper
 * 同时构建2个eventfd用来做异步切换线程和监听vsync事件
 * 
 * ！！！notice
 * ALooper_prepare 貌似只是在当前线程构建looper并绑定到线程上面
 * ALooper_prepare 返回的对象貌似没有增加引用计数
 * */
void care_controller_i::on_start() {
    assert(!native_looper_);
    native_looper_ = ::ALooper_prepare(ALOOPER_PREPARE_ALLOW_NON_CALLBACKS);
    assert(native_looper_);
    ::ALooper_acquire(native_looper_);
    ::ALooper_addFd(native_looper_, vsync_event_fd_, 
        vsync_event_fd_, ALOOPER_EVENT_INPUT, nullptr, nullptr);
    ::ALooper_addFd(native_looper_, event_fd_, 
        event_fd_, ALOOPER_EVENT_INPUT, nullptr, nullptr);
}

// 只可以在控制器线程中调用
void care_controller_i::listen_vsync(std::function<void()> callback) {
    vsync_callback_ = callback;
}

void care_controller_i::poll_once(uint32_t timems, bool* is_timeout) {
    assert(native_looper_ && queue_);
    auto ret = ::ALooper_pollOnce(timems, nullptr, nullptr, nullptr);
    if (event_fd_ == ret) {
        queue_->drained(); 
        __reset_event_fd__(event_fd_);
    } else if (vsync_event_fd_ == ret && vsync_callback_) {
        vsync_callback_(); 
        __reset_event_fd__(vsync_event_fd_);
    } else if (ALOOPER_POLL_TIMEOUT == ret && is_timeout) {
        *is_timeout = true;
    }
}

void care_controller_i::on_finish() {
    ;
}