
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_attrib_pointer {
public:
    uint32_t size_       = 0;
    uint32_t type_       = 0;
    uint32_t stride_     = 0;
    uint32_t offset_     = 0;
    bool     normalized_ = false;
    bool     enable_     = false;
};


}}}