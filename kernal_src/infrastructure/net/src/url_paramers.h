
#pragma once
#include "poller.h"

namespace cenarius { namespace infrastructure { namespace net {
class url_paramers final {
public:
    url_paramers(const char*);
public:
    bool add(const char*, const char*);
    std::string get();
private:
    std::string url_; bool has_paramer_ = false;
};

}}}