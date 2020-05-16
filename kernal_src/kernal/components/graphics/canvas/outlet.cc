
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void components::canvas::outlet(js_context& _context, js_object& _object) {
    assert(_context.is_useable() && _object.is_useable());
	auto thread_related = related_thread::obtain();
	assert(thread_related);
    using __class_t__ = canvas;
    js_class _class(_context);
    _class.attr("w", _I_BIND(__class_t__, set_w), _I_BIND(__class_t__, w));
    _class.attr("h", _I_BIND(__class_t__, set_h), _I_BIND(__class_t__, h));
    _class.function("getContext",_I_BIND(__class_t__, get_context));
    _class.build();
    thread_related->cls_canvas_ = std::move(_class);
}