
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/runnable/committer.h"

namespace cenarius { namespace kernal { namespace cc {
using namespace asynchronous;
class care_controller: public runnable_committer {
public:
    virtual ~care_controller() = default;
    
public:
    /**
     * 控制服务启动的时候调用
     * */
    virtual void on_start() = 0;

    // controller训练线程轮训
    // 如果没有受激发的信号会一直阻塞中
    // 当committer收到外部的异步任务一样会让函数返回
    virtual void poll_once(uint32_t, bool* timeout) = 0;

    // 设置vsync信号回调函数
    virtual void listen_vsync(std::function<void()>) = 0;

    /**
     * 控制服务退出的时候调用
     * */
    virtual void on_finish() = 0;
};


}}}