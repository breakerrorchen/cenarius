
#include "_.h"
using namespace cenarius;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace kernal;
using namespace bestead;
using namespace components;

void image::width(js_parameter& parameter) {
    auto _context = parameter.get_context();
    if (raw_image_) {
        parameter.set_return(
            js_value::create(_context, raw_image_->width( )));
    } else {
        parameter.set_return(js_value::create(_context, 0));
    }
}

void image::height(js_parameter& parameter) {
    auto _context = parameter.get_context();
    if (raw_image_) {
        parameter.set_return(
            js_value::create(_context, raw_image_->height()));
    } else {
        parameter.set_return(js_value::create(_context, 0));
    }
}