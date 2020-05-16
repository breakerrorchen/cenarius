#include "common/logger.h"
#include "console.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace interpreter;

void console::debug(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::log(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::info(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::error(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::warn(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::group(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::group_end(js_parameter& parameter) {
    inspect(parameter, 0);
}

void console::inspect(js_parameter& parameter, int) {
    if (parameter.get_argument_count() > 0) {
        auto val = parameter.get_argument_at(0);
        auto cxx_str = val.to_json_string();
__log_error("console: %s", cxx_str.c_str());
    }
}

void console::outlet(js_context& _context, js_object& _object) {
    assert(_context.is_useable() && _object.is_useable()); 
    using __class_t__ = console;
    js_class _class(_context);
    _class.constructor(_I_BIND(__class_t__));
    _class.function("debug",     _I_BIND(__class_t__, debug));
    _class.function("log",       _I_BIND(__class_t__, log));
    _class.function("info",      _I_BIND(__class_t__, info));
    _class.function("error",     _I_BIND(__class_t__, error));
    _class.function("warn",      _I_BIND(__class_t__, warn));
    _class.function("group",     _I_BIND(__class_t__, group));
    _class.function("group_end", _I_BIND(__class_t__, group_end));
    _class.build();
    auto instance = _class.create_new_instance(_context);
    assert(instance.is_useable());
    instance.hold_native_data(
        i_runtime_container<__class_t__>::create());
    _object["console"] = instance;
}