// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "barrel_buffer_center.h"
#include "barrel_buffer_observer.h"
#include "transmitter_invoke.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class command_transmitter final {
public:
    command_transmitter(std::shared_ptr<barrel_buffer_center>,
        std::shared_ptr<barrel_buffer_observer> observer = nullptr);
    ~command_transmitter();
    command_transmitter(const command_transmitter&) = delete;
    command_transmitter(command_transmitter&&);
    command_transmitter& operator=(const command_transmitter&) = delete;
    command_transmitter& operator=(command_transmitter&&);
    
public:
    // Force buffer submission
    // parameters can control whether synchronous blocking is required
    // spin => use cxx promis or spinlock waiter
    void force_commit(bool sync_wait = false, bool spin = false);

public:
    // Helper functions to automatically encode objects and queue commit
    // Will automatically apply for the buffer, 
    // automatically submit when the buffer is full
    template<typename cls, typename ...args_t>
    inline cls* alloc(args_t&&... arguments) {
        if (!current_barrel_buffer_) {
            current_barrel_buffer_ = center_->obtain();
            current_barrel_buffer_->observer_ = observer_;
        }
        auto alloc_size = sizeof(cls) + sizeof(void*);
        auto buffer = current_barrel_buffer_->offset_alloc(alloc_size);
        if (nullptr == buffer) {
            center_->commit(current_barrel_buffer_);
            current_barrel_buffer_ = center_->obtain();
            current_barrel_buffer_->observer_ = observer_;
            buffer = current_barrel_buffer_->offset_alloc(alloc_size);
        }
        auto _func = &(command_transmitter_invoke<cls>::invoke);
        memcpy(buffer, (void*)(&_func), sizeof(void*));
        return new((void*)((uint8_t*)buffer 
            + sizeof(void*))) cls(std::forward<args_t>(arguments)...);
    }

private:
    std::shared_ptr<barrel_buffer_observer> observer_;
    std::shared_ptr<barrel_buffer_center> center_;
    std::shared_ptr<barrel_buffer> current_barrel_buffer_;
};


}}}