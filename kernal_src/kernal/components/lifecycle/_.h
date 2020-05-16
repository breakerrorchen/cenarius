
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class lifecycle {
public:
    void on_show  (js_parameter&);
    void on_hide  (js_parameter&);
    void on_resume(js_parameter&);
    void on_pause (js_parameter&);
    void on_exit  (js_parameter&);
public:
    static void outlet(js_context&, js_object&);
};


}}}