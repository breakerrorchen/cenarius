
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

void render_context_2d::is_point_in_stroke(js_parameter& _parameter) {
    assert(related_);
    if (_parameter.get_argument_count() != 2) return;
    auto js_context = _parameter.get_context();
    auto x = _parameter[0].to_float();
    auto y = _parameter[1].to_float();
    auto& path = related_->lt_current_path_;
    auto is_in = path.contains((SkScalar)x, (SkScalar)y);
    _parameter.set_return(js_value::create(js_context, is_in));
}