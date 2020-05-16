
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class timer {
public:
    // 普通定时器
    static void set_interval  (js_parameter&);
    static void clear_interval(js_parameter&);
    static void set_timeout   (js_parameter&);
    static void clear_timeout (js_parameter&);
    static void internal_set  (js_parameter&, bool);
    static void internal_clear(js_parameter&);
    
    // 动画定时器
    static void anima_request (js_parameter&);
    static void anima_cancel  (js_parameter&);

public:
    static void outlet(js_context&, js_object&);
};


}}}