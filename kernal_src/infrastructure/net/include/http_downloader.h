
#pragma once
#include "io_center.h"
#include "io_committer.h"
#include "http_cancelable.h"
#include "http_contants.h"
#include "http_task.h"
#include "http_downloader_related.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_downloader final {
public:
    http_downloader& operator=(const http_downloader&) = delete;
    http_downloader& operator=(http_downloader&&) = delete;
    http_downloader(const http_downloader&) = delete;
    http_downloader(http_downloader&&) = delete;
    http_downloader(const char*);
    http_downloader(const std::string&);

public:
    // 多线程网络设计，这些是初始化函数
    // 在start之后这些函数就不可以调用了
    bool sendback   (std::shared_ptr<io_sendback>);
    void set_proxy  (const char*);
    void set_method (http_method);
    void set_header (const char*, const char*);
    void timeout    (uint32_t);
    bool save_mem   (bool); // 用以标记是不是在内存中存储一份数据
    bool save_file  (const char*);
    bool start      (std::shared_ptr<io_committer>);
    void cancel     (std::shared_ptr<io_committer>);

    // 多线程网络设计
    // 在start之后这些回调函数必须切换回sendback线程执行
    // 可以在start之后重复调用这些函数
    void on_header  (std::function<void(std::shared_ptr<http_header>)>);
    void on_progress(std::function<void(int, int, float)>);
    void on_cancel  (std::function<void()>);
    void on_error   (std::function<void()>);
    void on_finish  (std::function<void(bool success, std::string&)>);

private:
    std::shared_ptr<http_cancelable> cancelable_;
    std::shared_ptr<http_downloader_related> related_;
};


}}}