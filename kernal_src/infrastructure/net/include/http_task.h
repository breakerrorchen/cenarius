
#pragma once
#include "io_center.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_task {
public:
    virtual ~http_task() = default;
public:
    virtual void on_finish(const CURL*, const CURLcode&) {}
    virtual void on_cancel(const CURL*) {}
public:
    virtual void force_release() {
        delete this;
    }
};


}}}