
#include "kernal/isolate/related_thread.h"
#include "_.h"
#include "canvas/_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void graphics::create_canvas(js_parameter& parameter) {
	auto thread_related = related_thread::obtain();
	assert(thread_related && thread_related->care_info_);
    auto& info = thread_related->care_info_;
    int32_t w = -1, h = -1;
    if (parameter.get_argument_count() >= 2) {
    	auto _0 = parameter.get_argument_at(0);
    	if (_0.is_number()) {
    		w = _0.to_int32();
    	}
    	auto _1 = parameter.get_argument_at(1);
    	if (_1.is_number()) {
    		h = _1.to_int32();
    	}
    }

    if (0 > w || 0 > h) {
        w = info->window_w_; h = info->window_h_;
    }
    auto _context = parameter.get_context();
    auto _object = thread_related
        ->cls_canvas_.create_new_instance(_context);
    _object.hold_native_data(i_runtime_container<
        components::canvas>::create(thread_related, w, h));
    parameter.set_return(_object);
}