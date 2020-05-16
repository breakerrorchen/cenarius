// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class barrel_buffer_observer {
public:
    virtual ~barrel_buffer_observer() = default;
public:
    /**
     * Called when the instruction buffer starts executing.
     * Will be called in the thread consuming the buffer
     * */
    virtual void on_start () { ; }

    /**
     * Called when the instruction buffer after executing.
     * Will be called in the thread consuming the buffer
     * */
    virtual void on_finish() { ; }
};


}}} 