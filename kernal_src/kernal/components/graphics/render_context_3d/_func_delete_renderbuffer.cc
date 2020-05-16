
#include "../render_context_3d_renderbuffer/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_3d::delete_renderbuffer(js_parameter& _parameter) {
    if (_parameter.get_argument_count() != 1) return;
    auto v = _parameter.get_argument_at(0);
    auto _i = js_class_extract::extract<render_context_3d_renderbuffer>(v);
    if (_i) {
        _i->dispose();
    }
}