
#include "kernal/isolate/related_thread.h"
#include "_.h"
#include "kernal/components/image_data/_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void render_context_2d::create_image_data(js_parameter& _parameter) {
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    uint32_t w = 0, h = 0;

    // ImageData ctx.createImageData(width, height);
    if (_parameter.get_argument_count() == 2) {
        auto _0 = _parameter[0].to_int32();
        auto _1 = _parameter[1].to_int32();
        if (_0 <= 0 || _1 <= 0) return;
        w = (uint32_t)_0; h = (uint32_t)_1;
    } 
    
    // ImageData ctx.createImageData(imagedata);
    else if (_parameter.get_argument_count() == 1) {
        auto val = _parameter[0];
        auto _instance = js_class_extract
            ::extract<image_data>(val);
        if (nullptr == _instance) return;
        w = _instance->w_; h = _instance->h_;
    }
    
    auto _context = _parameter.get_context();
    auto _obj = thread_related->cls_image_data_
        .create_new_instance(_context);
    if (_obj.is_useable()) {
        image_data* _instance = nullptr;
        _obj.hold_native_data(i_runtime_container<
            image_data>::create(&_instance));
        if (_instance) {
            _instance->build(_context, w, h);
        }
    }
    _parameter.set_return((js_value)_obj);
}