
#pragma once
#include "io_center.h"
#include "io_sendback.h"
#include "http_contants.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_upload;
class http_upload_related final {
    friend class http_upload;
private:
    http_method method_ = http_method::__get__;
    std::string url_;
    uint32_t timeout_ = 0;
    std::vector<std::string> header_k_;
    std::vector<std::string> header_v_;
    std::string upload_file_;

private:
    std::function<void()> on_recv_header_;
    std::function<void()> on_recv_done_;
    std::function<void()> on_recv_progress_;
    std::shared_ptr<io_sendback> sendback_;
};


}}}