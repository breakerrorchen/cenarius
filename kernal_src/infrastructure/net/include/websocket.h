
#pragma once
#include "io_center.h"
#include "io_committer.h"
#include "io_sendback.h"
#include "http_contants.h"
#include "http_task.h"
#include "websocket_related.h"

namespace cenarius { namespace infrastructure { namespace net {
class websocket final: public std::enable_shared_from_this<websocket> {
public:
    websocket& operator=(const websocket&) = delete;
    websocket& operator=(websocket&&) = delete;
    websocket(const websocket&) = delete;
    websocket(websocket&&) = delete;
    websocket(const char*);
    websocket(const std::string&);

public:
    // 多线程网络设计，这些是初始化函数
    // 在start之后这些函数就不可以调用了
    bool sendback    (std::shared_ptr<io_sendback>);
    void set_proxy   (const char*);
    void set_header  (const char*, const char*);
    void set_protocol(const char*);
    void timeout     (uint32_t); 

    // 多线程网络设计
    // 在start之后这些回调函数必须切换回sendback线程执行
    // 可以在start之后重复调用这些函数
    void on_header   (std::function<void(std::shared_ptr<http_header>)>);
    void on_connect  (std::function<void()>);
    void on_recv_text(std::function<void(std::string&)>);
    void on_recv_data(std::function<void(std::string&)>);
    void on_recv_ping(std::function<void()>);
    void on_recv_pong(std::function<void()>);
    void on_close    (std::function<void()>);
    void on_error    (std::function<void()>);

public:
    // websocket的数据收发函数
    bool start    (std::shared_ptr<io_committer>);
    bool send_text(std::shared_ptr<io_committer>, std::string&, bool);
    bool send_data(std::shared_ptr<io_committer>, std::string&, bool);
    bool send_ping(std::shared_ptr<io_committer>);
    bool send_pong(std::shared_ptr<io_committer>);
    bool close    (std::shared_ptr<io_committer>);

public:
    inline uint32_t get_sendbuffer_size() {
        if (!related_) return false;
        uint32_t size = 0;
        related_->get_sendbuffer_size(&size);
        return size;
    }

public:
    std::shared_ptr<websocket_related> related_;

public:
    // 标记当前websocket的状态
    websocket_state state_ = websocket_state::__closed__;
};


}}}