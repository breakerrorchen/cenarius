
#pragma once
#include "curl.h"
#include "io_committer.h"
#include "http_task.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_downloader;
class http_client;
class http_cancelable final: 
    public std::enable_shared_from_this<http_cancelable> {
    friend class http_downloader;
    friend class http_client;
public:
    bool cancel(std::shared_ptr<io_committer>);
public:
    /**
     * 网络库内部操作，
     * */
    bool is_cancle_ = false; CURL* channel_handle_ = nullptr;
};


}}}