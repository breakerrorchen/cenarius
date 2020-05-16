
#include "kernal/isolate/related_thread.h"
#include "_.h"
#include "canvas/_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void graphics::window_canvas(js_parameter& parameter) {
	if (window_canvas_.is_useable()) {
		parameter.set_return((js_value)(window_canvas_));
		return;
	}
    auto thread_related = related_thread::obtain();
	assert(thread_related && thread_related->care_info_);
    auto& info = thread_related->care_info_;
    auto _context = parameter.get_context();
	auto _object = thread_related
        ->cls_canvas_.create_new_instance(_context);
    _object.hold_native_data(i_runtime_container<
        components::canvas>::create(thread_related));
    window_canvas_ = _object; 
    parameter.set_return(_object);
}