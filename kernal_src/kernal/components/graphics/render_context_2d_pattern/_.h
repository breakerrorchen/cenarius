
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas_render_2d.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
using namespace infrastructure;
using namespace renderer;
class render_context_2d_pattern {
public:
    virtual ~render_context_2d_pattern() = default;
public:
    static void outlet(js_context&, js_object&);
};


}}}