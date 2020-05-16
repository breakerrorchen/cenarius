
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_3d_buffer::outlet(js_context& _context, 
    js_object& _object) {
    assert(_context.is_useable() && _object.is_useable());
    auto thread_related = related_thread::obtain();
	assert(thread_related);
    using __class_t__ = render_context_3d_buffer;
    js_class _class(_context);
    _class.build();
    _object["WebGLBuffer"] = _class.to_value(_context);
    thread_related->cls_render_3d_buffer_ = std::move(_class);
}