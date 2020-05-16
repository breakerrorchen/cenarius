
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_value_holder decalre and implement
 * persistence of javascript value
 * */
i_value_holder::i_value_holder(JSContextRef context, JSValueRef value) {
    if (context) {
        context_._$_ = JSContextGetGlobalContext(context);
        if (value) { 
            JSValueProtect(context, value); _$_ = value;
        }
    }
}

i_value_holder::~i_value_holder() {
    reset();
}

i_value_holder::i_value_holder(const i_value_holder& from) {
    operator=(from);
}

i_value_holder::i_value_holder(i_value_holder&& from) {
    operator=(std::move(from));
}

i_value_holder::i_value_holder(const i_value& from) {
    operator=(from);
}

i_value_holder& i_value_holder::operator=(const i_value_holder& from) {
    if (this != &from) {
        reset(); 
        if (context_.is_useable() && from._$_) {
            _$_ = from._$_; JSValueProtect(context_._$_, _$_);
        }
        context_ = from.context_;
    }
    return *this;
}

i_value_holder& i_value_holder::operator=(i_value_holder&& from) {
    if (this != &from) {
        reset();
        context_ = std::move(from.context_); 
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

i_value_holder& i_value_holder::operator=(const i_value& from) {
    reset();
    context_._$_ = JSContextGetGlobalContext(from.context_._$_);
    if (context_.is_useable() && from._$_) {
        JSValueProtect(from.context_._$_, from._$_);
        _$_ = from._$_;
    }
    return *this;
}

i_value_holder::operator i_value() const {
    return i_value(context_._$_, _$_);
}

void i_value_holder::reset() {
    if (_$_ && context_.is_useable()) {
        JSValueUnprotect(context_._$_, _$_);
    }
    _$_ = nullptr; context_._$_ = nullptr;
}

#endif//__use_javascriptcore_backend__