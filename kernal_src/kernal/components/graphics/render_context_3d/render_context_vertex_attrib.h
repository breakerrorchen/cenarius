
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_3d_buffer;
class render_context_vertex_attrib {
public:
    uint32_t size_       = 0;
    uint32_t type_       = 0;
    uint32_t stride_     = 0;
    uint32_t offset_     = 0;
    bool     normalized_ = false;
    bool     enable_     = false;
    
public:
    float data_[4] = {0, 0, 0, 1};
    
public:
    js_value_holder buffer_;
    render_context_3d_buffer* raw_buffer_ = nullptr;
};


}}}