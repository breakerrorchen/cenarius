
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class console {
public:
    void debug    (js_parameter&);
    void log      (js_parameter&);
    void info     (js_parameter&);
    void error    (js_parameter&);
    void warn     (js_parameter&);
    void group    (js_parameter&);
    void group_end(js_parameter&);
public:
    void inspect  (js_parameter&, int);

public:
    static void outlet(js_context&, js_object&);
};


}}}