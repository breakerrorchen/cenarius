
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_3d_shader_precison {
public:
    render_context_3d_shader_precison() = default;

public:
    void range_min(js_parameter&);
	void range_max(js_parameter&);
    void precision(js_parameter&);
    
public:
    float min_, max_, precision_;
public:
    static void outlet(js_context&, js_object&);
};


}}}