
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

void render_context_3d::drawbuffer_w(js_parameter& _parameter) {
    assert(related_canvas_);
    auto related_cnavas = related_canvas_->get();
    if (!related_cnavas) return;
    int h = 0;
    related_cnavas->get_size(nullptr, &h);
    auto js_context = _parameter.get_context();
    _parameter.set_return(js_value::create(js_context, h));
}