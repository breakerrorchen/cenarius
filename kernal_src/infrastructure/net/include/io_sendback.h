
#pragma once
#include "io_center.h"

namespace cenarius { namespace infrastructure { namespace net {
class io_sendback {
public:
    virtual ~io_sendback() = default;
public:
    virtual bool post(std::function<void()>) = 0;
};


}}}