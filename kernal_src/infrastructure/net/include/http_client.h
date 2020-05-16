
#pragma once
#include "io_center.h"
#include "io_committer.h"
#include "io_sendback.h"
#include "http_contants.h"
#include "http_cancelable.h"
#include "http_task.h"
#include "http_header.h"
#include "http_client_related.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_client final {
public:
    http_client& operator=(const http_client&) = delete;
    http_client& operator=(http_client&&) = delete;
    http_client(const http_client&) = delete;
    http_client(http_client&&) = delete;
    http_client(const char*);
    http_client(const std::string&);

public:
    // 多线程网络设计，这些是初始化函数
    // 在start之后这些函数就不可以调用了
    bool sendback  (std::shared_ptr<io_sendback>);
    void set_proxy (const char*);
    void set_method(http_method);
    void set_header(const char*, const char*);
    void set_parame(const char*, const char*);
    void timeout   (uint32_t);

    // 多线程网络设计
    // 在start之后这些回调函数必须切换回sendback线程执行
    // 可以在start之后重复调用这些函数
    void on_header (std::function<void(std::shared_ptr<http_header>)>);
    void on_content(std::function<void(std::string&, int code)>);
    void on_cancel (std::function<void()>);
    void on_error  (std::function<void()>);

public:
    bool start(std::shared_ptr<io_committer>);
    void cancel();

private:
    std::shared_ptr<http_cancelable> cancelable_;
    std::shared_ptr<http_client_related> related_;
};


}}}