
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class syncer_condition final {
public:
    inline void wait() {
        std::unique_lock<std::mutex> locker(m_);
        if (is_completed_) return;
        cond_var_.wait(locker, [this]{ return is_completed_; });
    }

    inline void completed_notify() {
        std::unique_lock<std::mutex> locker(m_);
        is_completed_ = true; 
        cond_var_.notify_one();
    }

protected:
    bool is_completed_ = false; 
    mutable std::mutex m_; std::condition_variable cond_var_;
};


}}}