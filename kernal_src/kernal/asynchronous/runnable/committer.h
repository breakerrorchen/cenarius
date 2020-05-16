
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace asynchronous {
class runnable_committer {
public:
    virtual ~runnable_committer() = default;

public:
    virtual void commit(std::function<void()>) = 0;
};


}}} // end => cenarius.kernal.asynchronous

