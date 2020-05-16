
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace interpreter;
using namespace components;

bool image_data::build(js_context& context, uint32_t w, uint32_t h) {
    if (!context.is_useable()) return false;
    js_release_scope __release_scope__(context);
    clamped_arr_.reset();
    buffer_ = nullptr; buffer_size_ = 0;
    w_ = w; h_ = h;
    auto size = w * h * sizeof(uint32_t);
    auto v = js_value::create_clamped_arr(context, size);
    clamped_arr_ = v;
    auto raw = v.typedarr_buffer();
    buffer_ = raw.addr_; buffer_size_ = raw.size_;
    return true;
}

void image_data::attr_w(js_parameter& parameter) {
    auto _context = parameter.get_context();
    parameter.set_return(js_value::create(_context, (int)w_));
}

void image_data::attr_h(js_parameter& parameter) {
    auto _context = parameter.get_context();
    parameter.set_return(js_value::create(_context, (int)h_));
}

void image_data::data(js_parameter& parameter) {
    parameter.set_return((js_value)clamped_arr_);
}