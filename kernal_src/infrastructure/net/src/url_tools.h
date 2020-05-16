
#pragma once
#include "poller.h"

namespace cenarius { namespace infrastructure { namespace net {
class url_tools final {
public:
    static std::string encode(const std::string&);
	static std::string decode(const std::string&);
};


}}}