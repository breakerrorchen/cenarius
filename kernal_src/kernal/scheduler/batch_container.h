
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace scheduler {
using std::chrono::high_resolution_clock;
using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;
using std::chrono::time_point_cast;
class batch_timer_container final {
public:
    batch_timer_container();
    batch_timer_container(const batch_timer_container&) = delete;
    batch_timer_container(batch_timer_container&&) = delete;
    batch_timer_container& operator=(const batch_timer_container&) = delete;
    batch_timer_container& operator=(batch_timer_container&&) = delete;
    
    struct batch_timer_item final {
        batch_timer_item() = default;
        batch_timer_item(const batch_timer_item&);
        batch_timer_item(batch_timer_item&&);
        batch_timer_item& operator=(const batch_timer_item&);
        batch_timer_item& operator=(batch_timer_item&&);
        uint32_t index_id_ = 0; 
        std::function<void(uint32_t)> callback_;
    };
    
public:
    uint32_t add(std::function<void(uint32_t)>);
    void call();
    void cancel(uint32_t);
    void dispose();

private:
    high_resolution_clock::time_point timer_begin_;
    uint32_t id_ = 0; std::vector<batch_timer_item> in_, out_;
};


}}}