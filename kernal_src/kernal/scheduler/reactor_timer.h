
#pragma once
#include "common/base_header_inct.h"
#include "reactor_timer_item.h"

namespace cenarius { namespace kernal { namespace scheduler {
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;
using std::chrono::time_point_cast;
class reactor_timer final {
public:
    reactor_timer(const uint32_t size = 1024);
    reactor_timer(const reactor_timer&) = delete;
    reactor_timer(reactor_timer&&);
    reactor_timer& operator=(const reactor_timer&) = delete;
    reactor_timer& operator=(reactor_timer&&);

public:
    uint32_t add(uint32_t, std::function<void()>, bool loop = false);

    // poll all timer callback
    void poll();
    // remove a time callback by time ID
    void remove(const uint32_t);

public:
    // get last timeout time
    uint32_t get_lastest_timeout_time();

private:
    bool is_need_make_heap_ = false;
    std::vector<reactor_timer_item> timer_pool_;
    std::vector<reactor_timer_item> timer_pool_reserve_;
    uint32_t current_id_ = 0;
    high_resolution_clock::time_point timer_begin_;

private:
    uint32_t get_current_elapse() const;
};


}}}