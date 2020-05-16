// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "barrel_buffer.h"
#include "command_consumer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class barrel_buffer_center: public command_consumer {
public:
    barrel_buffer_center(
        uint32_t init_size = 64, uint32_t buffer_size = 16384);
    barrel_buffer_center(const barrel_buffer_center&) = delete;
    barrel_buffer_center(barrel_buffer_center&&) = delete;

public:
    /**
     * Get a buffer. If it can still be created, create a new one. 
     * If it cannot be created, wait for release.
     * */
    std::shared_ptr<barrel_buffer> obtain();

    /**
     * make sure there are enough buffers to schedule
     * */
    void ensure_sufficient(uint32_t);

    /**
     * Submit a buffer to the consumer, where they consume
     * */
    void commit(std::shared_ptr<barrel_buffer>);

    /**
     * Outside force wakeup consumer
     * */
    void wakeup_consumer();

public:
    // consumer thread batch consumption
    void batch_execute(bool wait) override;

private:
    uint32_t create_size_ = 0, max_size_ = 0, buffer_size_ = 0;
    uint32_t minial_size_ = 0;
    std::shared_ptr<barrel_buffer> current_release_list_;
private:
    std::shared_ptr<barrel_buffer> consume_release_list_head_;
    std::shared_ptr<barrel_buffer> consume_release_list_tail_;
    std::condition_variable cond_var_in_, cond_var_out_;
    std::mutex consume_m_in_, consume_m_out_; 
    std::shared_ptr<barrel_buffer> consume_head_, consume_tail_;
    bool should_wakeup_consumer_ = false;
};


}}}