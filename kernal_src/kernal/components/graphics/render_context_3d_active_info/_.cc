
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace interpreter;

void render_context_3d_active_info::name(js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, name_.c_str(), false));
}

void render_context_3d_active_info::size(js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, (int32_t)size_, false));
}

void render_context_3d_active_info::type(js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, (int32_t)type_, false));
}