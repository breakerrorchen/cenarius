
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void graphics::outlet(js_context& _context, js_object& _object) {
    assert(_context.is_useable() && _object.is_useable());
    using __class_t__ = graphics;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.function("window_canvas",_I_BIND(__class_t__, window_canvas));
    _class.function("create_canvas",_I_BIND(__class_t__, create_canvas));
    _class.function("load_font",    _I_BIND(__class_t__, load_font));
    _class.function("create_image", _I_BIND(__class_t__, create_image));
    _class.build();
    auto instance = _class.create_new_instance(_context);
    assert(instance.is_useable());
    instance.hold_native_data(
        i_runtime_container<__class_t__>::create());
    _object["graphics"] = instance;
}