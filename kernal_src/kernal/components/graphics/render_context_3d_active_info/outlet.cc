
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_3d_active_info::outlet(js_context& _context, 
    js_object& _object) {
    assert(_context.is_useable() && _object.is_useable());
    auto thread_related = related_thread::obtain();
	assert(thread_related);
    using __class_t__ = render_context_3d_active_info;
    js_class _class(_context);
    _class.attr("name", _I_BIND_NULL(), _I_BIND(__class_t__, name));
    _class.attr("size", _I_BIND_NULL(), _I_BIND(__class_t__, size));
    _class.attr("type", _I_BIND_NULL(), _I_BIND(__class_t__, type));
    _class.build();
    _object["WebGLActiveInfo"] = _class.to_value(_context);
    thread_related->cls_render_3d_active_info_ = std::move(_class);
}