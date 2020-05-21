
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace interpreter;

void render_context_3d_shader_precison::range_min(
    js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, min_));
}

void render_context_3d_shader_precison::range_max(
    js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, max_));
}

void render_context_3d_shader_precison::precision(
    js_parameter& _parameter) {
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(
        js_context, precision_));
}