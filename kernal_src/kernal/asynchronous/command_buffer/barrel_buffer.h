// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"
#include "kernal/asynchronous/syncer/syncer_spin.h"
#include "barrel_buffer_observer.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class barrel_buffer_center;
class command_transmitter;
class barrel_buffer final {
    friend class barrel_buffer_center;
    friend class command_transmitter;
public:
    barrel_buffer(uint32_t buffer_size = 1024 * 8);
    barrel_buffer(const barrel_buffer&) = delete;
    barrel_buffer(barrel_buffer&&) = delete;
    barrel_buffer& operator=(const barrel_buffer&) = delete;
    barrel_buffer& operator=(barrel_buffer&&) = delete;

public:
    /**
     * Execute all execution objects temporarily stored in 
     * this buffer and clear the data
     * */
    void execute();

public:
    /**
     * Used to monitor the state change of the Buffer, 
     * which will be called in the consuming thread
     * */
    std::weak_ptr<barrel_buffer_observer> observer_;

private:
    /**
     * force sync
     * */
    std::promise<uint8_t>* sync_promise_ = nullptr;

    /**
     * force sync spin
     * */
    syncer_spin* syncer_ = nullptr;

    /**
     * Allocate a specified size of memory. 
     * If nullptr is returned, the current buffer does not 
     * have the ability to classify.
     * */
    void* offset_alloc(uint32_t);

private:
    std::shared_ptr<barrel_buffer> next_;
    std::vector<uint8_t> buffer_; uint32_t offset_ = 0;
};


}}} 