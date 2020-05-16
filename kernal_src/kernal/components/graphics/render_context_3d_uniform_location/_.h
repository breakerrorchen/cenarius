
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_3d_uniform_location {
public:
    render_context_3d_uniform_location() = default;
public:
    static void outlet(js_context&, js_object&);
};


}}}