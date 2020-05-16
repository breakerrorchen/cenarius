
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class image_data {
public:
    virtual ~image_data() = default;
    
public:
    bool build(js_context&, uint32_t, uint32_t);
public:
    void attr_w(js_parameter&);
    void attr_h(js_parameter&);
    void data  (js_parameter&);

public:
    // image的尺寸
    uint32_t w_ = 0, h_ = 0;
    // javascript value 和 内存的地址和大小
    void* buffer_ = nullptr; size_t buffer_size_ = 0;
    js_value_holder clamped_arr_;

public:
    static void outlet(js_context&, js_object&);
};


}}}