
#pragma once
#include "base_header_inct.h"

namespace cenarius { namespace common_base {
using std::chrono::high_resolution_clock;
using std::chrono::steady_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::system_clock;
using std::chrono::time_point;
using std::chrono::time_point_cast;

class time_meter final {
public:
    time_meter() { time_meter::reset(); }
public:
    static inline uint64_t current_system_time() {
        auto _time_point = time_point_cast<
            milliseconds>(steady_clock::now());
        return (uint64_t)duration_cast<milliseconds>(
            _time_point.time_since_epoch()).count();
    }

    inline void reset() {
        begin_ = high_resolution_clock::now();
    }

    // get time form last reset
    inline uint32_t take() const {
        return (uint32_t)duration_cast<milliseconds>(
            steady_clock::now() - begin_).count();
    }

private:
    high_resolution_clock::time_point begin_;
};


}}