
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_3d_shader_precison::outlet(js_context& _context, 
    js_object& _object) {
    assert(_context.is_useable() && _object.is_useable());
    auto thread_related = related_thread::obtain();
	assert(thread_related);
    using __class_t__ = render_context_3d_shader_precison;
    js_class _class(_context);
    _class.attr("rangeMin", 
        _I_BIND_NULL(), _I_BIND(__class_t__, range_min));
    _class.attr("rangeMax", 
        _I_BIND_NULL(), _I_BIND(__class_t__, range_max));
    _class.attr("precision", 
        _I_BIND_NULL(), _I_BIND(__class_t__, precision));
    _class.build();
    _object["WebGLShaderPrecisionFormat"] = _class.to_value(_context);
    thread_related->cls_render_3d_shader_precison_ = std::move(_class);
}