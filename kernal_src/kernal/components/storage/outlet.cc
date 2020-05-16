
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void local_storage::outlet(js_context& _context, js_object& _object) {
	assert(_context.is_useable() && _object.is_useable());
	using __class_t__ = local_storage;
	js_class _class(_context);
	_class.constructor(_I_BIND(__class_t__));
	_class.function("setItem", 	  _I_BIND(__class_t__, set_item));
	_class.function("getItem", 	  _I_BIND(__class_t__, get_item));
	_class.function("removeItem", _I_BIND(__class_t__, remove_item));
	_class.function("clear", 	  _I_BIND(__class_t__, clear));
	_class.build();
	auto instance = _class.create_new_instance(_context);
	assert(instance.is_useable());
	instance.hold_native_data(
        i_runtime_container<__class_t__>::create());
	_object["localStorage"] = instance;
}