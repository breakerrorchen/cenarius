
#include "_.h"
using namespace cenarius;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace kernal;
using namespace bestead;
using namespace components;

void image::on_load(js_parameter& parameter) {
    parameter.set_return((js_value)on_load_);
}

void image::set_on_load(js_parameter& parameter) {
    on_load_.reset();
    if (parameter.get_argument_count() == 1) {
        auto v = parameter.get_argument_at(0);
        if (v.is_function()) {
            on_load_ = v;
        }
    }
}