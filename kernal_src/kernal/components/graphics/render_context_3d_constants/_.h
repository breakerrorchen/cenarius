
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "../render_context_3d/render_constants.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_3d_constants {
public:
    static void outlet(js_context&, js_object&);
};


}}}