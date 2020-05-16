
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace kernal;
using namespace isolate;
using namespace bestead;
using namespace components;

void image::outlet(js_context& _context, js_object& _object) {
    auto thread_related = related_thread::obtain();
	assert(thread_related);
    assert(_context.is_useable() && _object.is_useable());
    using __class_t__ = image;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.attr("src", 
        _I_BIND(__class_t__, set_src),
        _I_BIND(__class_t__, src));
    _class.attr("width",  _I_BIND_NULL(),
        _I_BIND(__class_t__, width));
    _class.attr("height", _I_BIND_NULL(),
        _I_BIND(__class_t__, height));
    _class.attr("onload", 
        _I_BIND(__class_t__, set_on_load),
        _I_BIND(__class_t__, on_load));
    _class.attr("onerror", 
        _I_BIND(__class_t__, set_on_error),
        _I_BIND(__class_t__, on_error));
    _class.build();
    _object["Image"] = _class.to_value(_context);
    thread_related->cls_image_ = std::move(_class);
}