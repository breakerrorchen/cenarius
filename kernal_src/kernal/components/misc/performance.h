
#pragma once
#include "common/base_header_inct.h"
#include "common/timer_meter.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class performance {
public:
    void now(js_parameter&);
private:
    common_base::time_meter tm_;

public:
    static void outlet(js_context&, js_object&);
};


}}}