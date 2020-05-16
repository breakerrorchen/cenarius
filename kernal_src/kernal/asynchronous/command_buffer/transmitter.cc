
#include "transmitter.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

command_transmitter::command_transmitter(
    std::shared_ptr<barrel_buffer_center> center,
    std::shared_ptr<barrel_buffer_observer> observer)
    : center_(center), observer_(observer) {
    assert(center);
    if (!center) {
        throw std::runtime_error(__FILE__);
    }
}

command_transmitter::~command_transmitter() {
    force_commit(false, true);
}

command_transmitter::command_transmitter(command_transmitter&& from) {
    center_ = std::move(from.center_);
    current_barrel_buffer_ = std::move(from.current_barrel_buffer_);
}

command_transmitter& command_transmitter::operator=(
    command_transmitter&& from) {
    if (this != &from) {
        center_ = std::move(from.center_);
        current_barrel_buffer_ 
            = std::move(from.current_barrel_buffer_);
    }
    return *this;
}

void command_transmitter::force_commit(bool sync_wait, bool spin) {
    if (current_barrel_buffer_) {
        if (sync_wait) {
            if (spin) {
                syncer_spin syncer;
                current_barrel_buffer_->syncer_ = &syncer;
                current_barrel_buffer_->sync_promise_ = nullptr;
                center_->commit(std::move(current_barrel_buffer_));
                current_barrel_buffer_ = nullptr;
                syncer.wait();
            } else {
                std::promise<uint8_t> sync_promise;
                current_barrel_buffer_->sync_promise_ = &sync_promise;
                current_barrel_buffer_->syncer_ = nullptr;
                center_->commit(std::move(current_barrel_buffer_));
                current_barrel_buffer_ = nullptr;
                sync_promise.get_future().get();
            }
        } else {
            current_barrel_buffer_->sync_promise_ = nullptr;
            current_barrel_buffer_->syncer_ = nullptr;
            center_->commit(std::move(current_barrel_buffer_));
            current_barrel_buffer_ = nullptr;
        }
    }
}