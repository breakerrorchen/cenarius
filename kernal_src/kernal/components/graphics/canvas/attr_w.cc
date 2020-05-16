
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::w(js_parameter& parameter) {
    auto _context = parameter.get_context();
    auto v = js_value::create(_context, w_);
    parameter.set_return(v);
}

void components::canvas::set_w(js_parameter& parameter) {
    if (parameter.get_argument_count() == 0) return;
    auto value = parameter.get_argument_at(0);
    if (!value.is_number()) return;
    auto _w = value.to_int32();
    if (_w != w_) {
    	w_ = (int)_w; need_resize_ = true;
    }
}