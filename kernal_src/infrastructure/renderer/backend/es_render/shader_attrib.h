
#pragma once
#include "conf.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class shader_attrib final {
public:
    uint32_t location_index_  = 0;
    std::string name_;
    uint32_t type_ = 0, size_ = 0;
};


}}}