
#include "kernal/isolate/related_thread.h"
#include "../render_context_3d/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::get_context_3d(js_parameter& parameter) {
    if (_2d_context_.is_useable()) { return; }
    if (_3d_context_.is_useable()) {
        parameter.set_return((js_value)(_3d_context_));
        return;
    }
    auto thread_related = related_thread::obtain();
    assert(thread_related);
	auto _context = parameter.get_context();
    auto _object = thread_related
        ->cls_render_context_3d_.create_new_instance(_context);
    _object.set_prototype(thread_related->render_context_3d_proto_);
    _object.hold_native_data(
        i_runtime_container<render_context_3d>::create(transmitter_, 
        raw_canvas_, render_attitude_, alived_watcher_.get()));
    _3d_context_ = _object; parameter.set_return(_object);
}