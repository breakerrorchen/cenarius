
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/runnable/queue.h"
#include "kernal/cc/care_controller.h"
#include "env.h"

namespace cenarius { namespace platform {
using namespace kernal;
using namespace asynchronous;
using namespace cc;
class care_controller_i final : public care_controller {
public:
    care_controller_i();
    virtual ~care_controller_i();

public:
    // 通知vsync信号，这个函数是线程安全的
    void vsync_dispatch();

    // 提交异步任务，这个函数是线程安全的
    void commit(std::function<void()>) override;

public:
    /**
     * 控制服务启动的时候调用
     * */
    void on_start() override;

    // 这个函数只能在controller线程中才能调用
    // 设置vsync信号回调函数
    void listen_vsync(std::function<void()>) override;

    // 这个函数只能在controller线程中才能调用
    // controller 线程轮训
    // 如果一直没有受激发的信号就会一直阻塞
    void poll_once(uint32_t, bool* timeout) override;

    /**
     * 控制服务退出的时候调用
     * */
    void on_finish() override;

private:
    // async runnable queue
    std::shared_ptr<runnable_queue> queue_;

    // android run loop
    ALooper* native_looper_ = nullptr;

    /**
     * use eventfd to switch threads and simulate receiving 
     * vertical synchronization signals
     * */
    int event_fd_ = 0, vsync_event_fd_ = 0;

    // vsync 信号回调函数
    std::function<void()> vsync_callback_;
};


}}