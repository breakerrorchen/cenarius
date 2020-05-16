
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_parameter
 * */
i_context i_parameter::get_context() const {
    return i_context(context_);
}

i_object i_parameter::get_this() const {
    return i_object(context_, object_this_);
}

i_value i_parameter::get_argument_at(int index) const {
    assert(arguments_);
    return i_value(context_, arguments_[index]);
}

size_t i_parameter::get_argument_count() const {
    return argument_count_;
}

i_value i_parameter::operator[](int index) const {
    return get_argument_at(index);
}

void i_parameter::set_return(i_value value) {
    ret_ = value._$_;
}

void i_parameter::set_exception(i_value value) {
    exception_ = value._$_;
}

#endif//__use_javascriptcore_backend__