
#include "kernal/isolate/related_thread.h"
#include "_.h"
#include "kernal/components/graphics/render_context_2d_gradient/_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_2d::create_linear_gradient(js_parameter& parameter) {
    // auto thread_related = related_thread::obtain();
    // assert(thread_related);
    // if (parameter.get_argument_count() == 4) {
    //     auto x0 = parameter[0].to_float();
    //     auto y0 = parameter[1].to_float();
    //     auto x1 = parameter[2].to_float();
    //     auto y1 = parameter[3].to_float();
    //     auto _context = parameter.get_context();
    //     auto _obj = thread_related->cls_render_2d_gradient_
    //         .create_new_instance(_context);
    //     if (_obj.is_useable()) {
    //         render_context_2d_gradient* _instance = nullptr;
    //         _obj.hold_native_data(i_runtime_container<
    //             render_context_2d_gradient>::create(&_instance));
    //         if (_instance) {
    //             _instance->build_linear(x0, y0, x1, y1);
    //         }
    //     }
    //     parameter.set_return((js_value)_obj);
    // }
}