
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void image_data::outlet(js_context& _context, js_object& _object) {
    auto thread_related = related_thread::obtain();
	assert(thread_related && _context.is_useable());
    using __class_t__ = image_data;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.attr("width", 
        _I_BIND_NULL(), _I_BIND(__class_t__, attr_w));
    _class.attr("height", 
        _I_BIND_NULL(), _I_BIND(__class_t__, attr_h));
    _class.attr("data", 
        _I_BIND_NULL(), _I_BIND(__class_t__, data  ));
    _class.build();
    _object["ImageData"] = _class.to_value(_context);
    thread_related->cls_image_data_ = std::move(_class);
}