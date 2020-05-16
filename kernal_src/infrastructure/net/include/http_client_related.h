
#pragma once
#include "io_center.h"
#include "io_sendback.h"
#include "http_contants.h"
#include "http_header.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_client;
class http_client_related final {
    friend class http_client;
private:
    // 用来做线程切换
    // 在发送到网络线程后, 不可以继续操作
    http_method method_ = http_method::__get__;
    std::string url_;
    uint32_t timeout_ = 0;
    std::vector<std::string> header_k_;
    std::vector<std::string> header_v_;
    std::vector<std::string> parame_k_;
    std::vector<std::string> parame_v_;
    std::string post_content_;
    std::string proxy_; // "127.0.0.1:8888"

private:
    // 当指定的时机到来会通过sendback切换回线程执行
    // 假设设置和sendback后的线程是一个，那么可以随时修改
    std::function<void(std::shared_ptr<http_header>)> on_header_;
    std::function<void(std::string&, int code)> on_content_;
    std::function<void()> on_cancel_;
    std::function<void()> on_error_;

private:
    // 用来做线程切换
    // 在发送到网络线程后, 不可以继续操作
    std::shared_ptr<io_sendback> sendback_;
};


}}}