// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "committer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class runnable_block_queue final: public runnable_committer {
public:
    runnable_block_queue() = default;
    runnable_block_queue(const runnable_block_queue&) = delete;
    runnable_block_queue(runnable_block_queue&&) = delete;
    runnable_block_queue& operator=(const runnable_block_queue&) = delete;
    runnable_block_queue& operator=(runnable_block_queue&&) = delete;

public:
    void commit(std::function<void()>) override;

public:    
    void wake    (bool all = false);
    void wait    (std::function<void()>&);
    void try_wait(std::function<void()>&);

private:
    mutable std::mutex mutex_;
    std::queue<std::function<void()>> inner_queue_;
    std::condition_variable cond_var_;
};


}}}