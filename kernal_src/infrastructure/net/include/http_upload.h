
#pragma once
#include "io_center.h"
#include "http_cancelable.h"
#include "http_contants.h"
#include "http_task.h"
#include "http_upload_related.h"
#include "io_committer.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_upload final {
public:
    http_upload& operator=(const http_upload&) = delete;
    http_upload& operator=(http_upload&&) = delete;
    http_upload(const http_upload&) = delete;
    http_upload(http_upload&&) = delete;
    http_upload(const char*);
    http_upload(const std::string&);

public:
    void set_method(http_method);
    void set_header(const char*, const char*);
    void timeout   (uint32_t);
    bool set_file  (const char*);

public:
    std::shared_ptr<http_cancelable> start(std::shared_ptr<io_committer>);

};


}}}