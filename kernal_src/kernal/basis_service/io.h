// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/runnable/block_queue.h"

namespace cenarius { namespace kernal { namespace service {
using namespace asynchronous;
class io final {
public:
    io();
public:
    static void commit(std::function<void()>);

private:
    std::thread thread_;
    std::shared_ptr<runnable_block_queue> queue_;
};


}}}