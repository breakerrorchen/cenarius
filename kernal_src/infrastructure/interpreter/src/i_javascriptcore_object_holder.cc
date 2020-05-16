
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_object_holder decalre and implement
 * persistence of javascript object
 * */
i_object_holder::i_object_holder(JSContextRef context, JSObjectRef object) {
    if (context) {
        context_._$_ = JSContextGetGlobalContext(context);
        if (object) {
            JSValueProtect(context_._$_, object); _$_ = object;
        }
    }
}

i_object_holder::~i_object_holder() {
    reset();
}

i_object_holder::i_object_holder(const i_object_holder& from) {
    operator=(from);
}

i_object_holder::i_object_holder(i_object_holder&& from) {
    operator=(std::move(from));
}

i_object_holder::i_object_holder(const i_object& from) {
    operator=(from);
}

i_object_holder& i_object_holder::operator=(const i_object_holder& from) {
    if (this != &from) {
        reset();
        if (context_._$_ && from._$_) {
            _$_ = from._$_; JSValueProtect(context_._$_, _$_);
        }
        context_ = from.context_; 
    }
    return *this;
}

i_object_holder& i_object_holder::operator=(i_object_holder&& from) {
    if (this != &from) {
        reset();
        context_ = std::move(from.context_);
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

i_object_holder& i_object_holder::operator=(const i_object& from) {
    reset();
    context_._$_ = JSContextGetGlobalContext(from.context_._$_);
    if (context_.is_useable() && from._$_) {
        _$_ = from._$_; JSValueProtect(from.context_._$_, _$_);
    }
    return *this;
}

i_object_holder::operator i_object() const {
    return i_object(context_._$_, _$_);
}

i_object_holder::operator i_value () const {
    return i_value (context_._$_, _$_);
}

void i_object_holder::reset() {
    if (_$_ && context_._$_) {
        JSValueUnprotect(context_._$_, _$_);
    }
    _$_ = nullptr; context_._$_ = nullptr;
}

#endif//__use_javascriptcore_backend__