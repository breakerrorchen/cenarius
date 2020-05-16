
#pragma once
#include "io_center.h"
#include "io_sendback.h"
#include "http_contants.h"
#include "http_header.h"
#include "websocket_status.h"

namespace cenarius { namespace infrastructure { namespace net {
class websocket;
class websocket_channel;
class websocket_related final {
    friend class websocket;
    friend class websocket_channel;
private:
    // 用来做线程切换
    // 在发送到网络线程后, 不可以继续操作
    http_method method_ = http_method::__get__;
    std::string url_;
    uint32_t timeout_ = 0;
    std::string protocol_ = "chat,superchat";
    std::vector<std::string> header_k_;
    std::vector<std::string> header_v_;
    std::string proxy_; // "127.0.0.1:8888"

private:
    // 当指定的时机到来会通过sendback切换回线程执行
    // 假设设置和sendback后的线程是一个，那么可以随时修改
    std::function<void(std::shared_ptr<http_header>)> on_header_;
    std::function<void()> on_connect_;
    std::function<void(std::string&)> on_recv_text_;
    std::function<void(std::string&)> on_recv_data_;
    std::function<void()> on_ping_ ;
    std::function<void()> on_pong_ ;
    std::function<void()> on_close_;
    std::function<void()> on_error_;
private:
    // 用来做线程切换
    // 在发送到网络线程后, 不可以继续操作
    std::shared_ptr<io_sendback> sendback_;

private:
    void set_sendbuffer_size(uint32_t data) {
        while(locker_.test_and_set(std::memory_order_acquire));
        sendbuffer_size_ = data;
        locker_.clear(std::memory_order_release);
    }

    void get_sendbuffer_size(uint32_t* ret) {
        if (nullptr == ret) return;
        while(locker_.test_and_set(std::memory_order_acquire));
        *ret = sendbuffer_size_;
        locker_.clear(std::memory_order_release);
    }

    // 多线程中共享的数据
    uint32_t sendbuffer_size_ = 0;
    std::atomic_flag locker_ = ATOMIC_FLAG_INIT;

private:
    // 只能在网络线程中处理
    websocket_channel* related_channel_ = nullptr;

public:
    std::weak_ptr<websocket> related_client_;
};


}}}