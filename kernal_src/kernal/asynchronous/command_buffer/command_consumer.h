// created by chenguodong
// contact me wechat: breakerror
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class command_consumer {
public:
    virtual ~command_consumer() = default;
public:
    /**
     * consumption to execute command, 
     * return false to indicate exit is required
     * */
    virtual void batch_execute(bool wait) = 0;
};


}}}