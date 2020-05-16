// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "committer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
    
class runnable_block_bound_queue final: public runnable_committer {
public:
    runnable_block_bound_queue(uint32_t max_size = 1024);
    runnable_block_bound_queue(const runnable_block_bound_queue&) = delete;
    runnable_block_bound_queue(runnable_block_bound_queue&&) = delete;
    runnable_block_bound_queue& operator=(const runnable_block_bound_queue&) = delete;
    runnable_block_bound_queue& operator=(runnable_block_bound_queue&&) = delete;

public:
    void commit(std::function<void()>) override;

public:    
    void wake    (bool all = false);
    void wait    (std::function<void()>&);
    void try_wait(std::function<void()>&);

private:
    std::queue<std::function<void()>> inner_queue_;
    mutable std::mutex mutex_;
    std::condition_variable not_full_, not_empty_; 
    size_t count_ = 0, bound_ = 0; bool is_should_wake_ = false;
};


}}}