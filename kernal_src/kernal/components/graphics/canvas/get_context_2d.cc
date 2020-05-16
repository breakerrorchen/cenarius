
#include "kernal/isolate/related_thread.h"
#include "../render_context_2d/_.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void components::canvas::get_context_2d(js_parameter& parameter) {
	if (_3d_context_.is_useable()) {
		return;
	}

	if (_2d_context_.is_useable()) {
		parameter.set_return((js_value)(_2d_context_));
		return;
	}
	auto thread_related = related_thread::obtain();
	assert(thread_related);
	auto _context = parameter.get_context();
	auto _object = thread_related
        ->cls_render_context_2d_.create_new_instance(_context);
   	_object.hold_native_data(i_runtime_container<
	   	render_context_2d>::create(
		transmitter_, raw_canvas_, alived_watcher_.get()));
   	_2d_context_ = _object; parameter.set_return(_object);
}