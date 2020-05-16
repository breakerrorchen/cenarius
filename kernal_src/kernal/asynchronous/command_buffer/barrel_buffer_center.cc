
#include "barrel_buffer_center.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

barrel_buffer_center::barrel_buffer_center(uint32_t init_size, 
    uint32_t buffer_size) {
    buffer_size_ = buffer_size;
    minial_size_ = max_size_ = init_size;
}

std::shared_ptr<barrel_buffer> barrel_buffer_center::obtain() {
    if (current_release_list_) {
        auto buffer = current_release_list_;
        current_release_list_ = current_release_list_->next_;
        buffer->next_ = nullptr;
        return buffer;
    }

    if (create_size_ < max_size_) {
        create_size_++;
        return std::make_shared<barrel_buffer>(buffer_size_);
    }

    std::shared_ptr<barrel_buffer> consume_release_list;
    {
        std::unique_lock<std::mutex> locker(consume_m_out_);
        while (!consume_release_list_head_) {
            cond_var_out_.wait(locker);
        }
        consume_release_list = consume_release_list_head_;
        consume_release_list_head_ = nullptr;
        consume_release_list_tail_ = nullptr;
    }
    auto buffer = consume_release_list;
    consume_release_list = consume_release_list->next_;
    buffer->next_ = nullptr;
    while (create_size_ > max_size_ && consume_release_list) {
        create_size_--;
        consume_release_list = consume_release_list->next_;
    }
    current_release_list_ = consume_release_list;

    return buffer;
}

void barrel_buffer_center::ensure_sufficient(uint32_t size) {
    if (size > minial_size_) { max_size_ = size; }
    while (create_size_ > max_size_ && current_release_list_) {
        create_size_--;
        current_release_list_ = current_release_list_->next_;
    }
}

void barrel_buffer_center::commit(
    std::shared_ptr<barrel_buffer> commit_buffer) {
    if (commit_buffer) {
        {
            std::unique_lock<std::mutex> locker(consume_m_in_);
            if (!consume_head_) {
                consume_head_ = commit_buffer;
            } else {
                consume_tail_->next_ = commit_buffer;
            }
            consume_tail_ = commit_buffer;
        }
        cond_var_in_.notify_one();
    }
}

void barrel_buffer_center::wakeup_consumer() {
    std::unique_lock<std::mutex> locker(consume_m_in_);
    should_wakeup_consumer_ = true;
    cond_var_in_.notify_one();
}

void barrel_buffer_center::batch_execute(bool wait) {
    std::shared_ptr<barrel_buffer> consume_list;
    if (wait) {
        {
            std::unique_lock<std::mutex> locker(consume_m_in_);
            while (!consume_head_ && !should_wakeup_consumer_) {
                cond_var_in_.wait(locker);
            }
            consume_list = consume_head_;
            consume_head_ = consume_tail_ = nullptr;
            should_wakeup_consumer_ = false;
        }
    } else {
        std::unique_lock<std::mutex> locker(consume_m_in_);
        consume_list = consume_head_;
        consume_head_ = consume_tail_ = nullptr;
    }

    while (consume_list) {
        consume_list->execute(); auto node = consume_list; 
        consume_list = consume_list->next_; node->next_ = nullptr;
        {
            std::unique_lock<std::mutex> locker(consume_m_out_);
            if (!consume_release_list_head_) {
                consume_release_list_head_ = node;
            } else {
                consume_release_list_tail_->next_ = node;
            }
            consume_release_list_tail_ = node;
        }
        cond_var_out_.notify_one();
    }
}