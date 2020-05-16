
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class render_context_3d_active_info {
public:
    render_context_3d_active_info() = default;

public:
    void name(js_parameter&);
	void size(js_parameter&);
    void type(js_parameter&);

public:
    static void outlet(js_context&, js_object&);
};


}}}