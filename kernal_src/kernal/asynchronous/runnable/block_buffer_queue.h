// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "committer.h"

namespace cenarius { namespace kernal { namespace asynchronous {

class runnable_block_buffer_queue final: public runnable_committer {
public:
    runnable_block_buffer_queue();
    runnable_block_buffer_queue(const runnable_block_buffer_queue&) = delete;
    runnable_block_buffer_queue(runnable_block_buffer_queue&&) = delete;
    runnable_block_buffer_queue& operator=(const runnable_block_buffer_queue&) = delete;
    runnable_block_buffer_queue& operator=(runnable_block_buffer_queue&&) = delete;

public:
    void commit(std::function<void()>) override;

public:    
    void wake(bool all = false);

    // execute all runnable
    uint32_t drained();

private:
    std::queue<std::function<void()>> inner_queue_[2];
    std::queue<std::function<void()>> *in_, *out_;
    mutable std::mutex mutex_; std::condition_variable cond_var_;
};


}}}