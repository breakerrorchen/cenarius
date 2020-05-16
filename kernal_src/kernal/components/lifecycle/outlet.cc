
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;
using namespace components;

void lifecycle::outlet(js_context& _context, js_object& _object) {
    assert(_context.is_useable() && _object.is_useable()); 
    using __class_t__ = lifecycle;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.function("on_show"  , _I_BIND(__class_t__, on_show  ));
    _class.function("on_hide"  , _I_BIND(__class_t__, on_hide  ));
    _class.function("on_resume", _I_BIND(__class_t__, on_resume));
    _class.function("on_pause" , _I_BIND(__class_t__, on_pause ));
    _class.function("on_exit"  , _I_BIND(__class_t__, on_exit  ));
    _class.build();
    auto instance = _class.create_new_instance(_context);
    assert(instance.is_useable());
    instance.hold_native_data(
        i_runtime_container<__class_t__>::create());
    _object["lifecycle"] = instance;
}