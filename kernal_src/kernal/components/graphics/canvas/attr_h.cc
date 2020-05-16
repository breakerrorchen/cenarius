
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::h(js_parameter& parameter) {
    auto _context = parameter.get_context();
    auto v = js_value::create(_context, h_);
    parameter.set_return(v);
}

void components::canvas::set_h(js_parameter& parameter) {
    if (parameter.get_argument_count() == 0) return;
    auto value = parameter.get_argument_at(0);
    if (!value.is_number()) return;
    auto _h = value.to_int32();
    if (_h != h_) {
    	h_ = (int)_h; need_resize_ = true;
    }
}