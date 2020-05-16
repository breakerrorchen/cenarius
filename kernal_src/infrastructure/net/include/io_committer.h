
#pragma once
#include <functional>

namespace cenarius { namespace infrastructure { namespace net {
class poller;
class io_committer {
public:
    virtual ~io_committer() = default;
public:
    virtual void post(std::function<void(poller*)>) = 0;
};


}}}