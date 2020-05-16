#include "common/logger.h"
#include "performance.h"
using namespace cenarius;
using namespace common_base;
using namespace kernal;
using namespace components;
using namespace interpreter;

void performance::now(js_parameter& parameter) {
    auto _context = parameter.get_context();
    auto v = js_value::create(_context, (double)tm_.take());
    parameter.set_return(v);
}

void performance::outlet(
    js_context& _context, js_object& _object) {
    assert(_context.is_useable()); 
    using __class_t__ = performance;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.function("now", _I_BIND(__class_t__, now));
    _class.build();
    auto instance = _class.create_new_instance(_context);
    assert(instance.is_useable());
    instance.hold_native_data(
        i_runtime_container<__class_t__>::create());
    _object["Performance"] = instance;
}