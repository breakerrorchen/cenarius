
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
class graphics {
public:
	void window_canvas(js_parameter&);
    void create_canvas(js_parameter&);
    void load_font    (js_parameter&);
    void create_image (js_parameter&);

private:
	js_object_holder window_canvas_;

public:
    static void outlet(js_context&, js_object&);
};


}}}
