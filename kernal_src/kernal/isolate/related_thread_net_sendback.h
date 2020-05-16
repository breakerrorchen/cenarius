
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/net/include/io_sendback.h"
#include "kernal/asynchronous/runnable/committer.h"

namespace cenarius { namespace kernal { namespace isolate {
using namespace asynchronous;
using namespace infrastructure;
using namespace net;
class related_thread_net_sendback: public io_sendback {
public:
    bool post(std::function<void()>);
public:
    std::shared_ptr<runnable_committer> committer_;
};


}}}