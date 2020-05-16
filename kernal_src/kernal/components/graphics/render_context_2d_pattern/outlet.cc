
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_2d_pattern::outlet(js_context& _context, 
    js_object& _object) {
    auto thread_related = related_thread::obtain();
	assert(thread_related);
    assert(_context.is_useable() && _object.is_useable());
    using __class_t__ = render_context_2d_pattern;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.build();
    _object["CanvasPattern"] = _class.to_value(_context);
    thread_related->cls_render_2d_pattern_ = std::move(_class);
}