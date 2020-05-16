
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

void content::on_resize(uint32_t w, uint32_t h) {
    auto& _context = content_context_;
    if (_context && _context->care_info_) {
        _context->care_info_->window_w_ = w;
        _context->care_info_->window_h_ = h;
    }
    
    assert(related_thread_);
    auto& on_size = related_thread_->on_size_changed_;
    if (!on_size.is_useable()) {
    	return;
    }
    js_release_scope release_scope(on_size);
    auto context = on_size.get_context();
    auto callback = (js_value)on_size;
    js_value arguments[2];
    arguments[0] = js_value::create(context, (long)w);
    arguments[1] = js_value::create(context, (long)h);
    callback.function_invoke(
    	nullptr, arguments, 2, nullptr);
}