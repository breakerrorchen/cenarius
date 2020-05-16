// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/syncer/spinlocker_watcher.h"
#include "committer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class runnable_queue final: public runnable_committer {
public:
    runnable_queue();
    runnable_queue(const runnable_queue&) = delete;
    runnable_queue(runnable_queue&&) = delete;
    runnable_queue& operator=(const runnable_queue&) = delete;
    runnable_queue& operator=(runnable_queue&&) = delete;

public:
    void commit(std::function<void()>) override;
        
    // execute all runnable
    uint32_t drained();

private:
    spinlocker locker_;
    std::queue<std::function<void()>> inner_queue_[2];
    std::queue<std::function<void()>> *in_, *out_;
};


}}} // end => cenarius.kernal.asynchronous