
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_context decalre and implement
 * interpreter actuator context
 * */
i_context::i_context(const i_context& from) {
    _$_ = from._$_;
}

i_context::i_context(i_context&& from) {
    _$_ = from._$_; from._$_ = nullptr;
}

i_context& i_context::operator=(const i_context& from) {
    if (this != &from) {
        _$_ = from._$_;
    }
    return *this;
}

i_context& i_context::operator=(i_context&& from) {
    if (this != &from) {
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

i_object i_context::get_global_object() const {
    if (_$_) {
        return i_object(
            _$_, JSContextGetGlobalObject(_$_));
    }
    return i_object(nullptr, nullptr);
}

i_value i_context::eval(const char* source, i_value* exception) const {
    if (!source || !_$_) { return i_value(); }
    auto script = JSStringCreateWithUTF8CString(source);
    JSValueRef evaluate_exception = nullptr;
    auto value = JSEvaluateScript(
        _$_, script, 0, 0, 0, &evaluate_exception);
    ::JSStringRelease(script); (void)value;
    if (exception) {
        exception->context_._$_ = _$_;
        exception->_$_ = evaluate_exception;
    }
    return i_value(_$_, value);
}

void i_context::gc() {
    if (_$_) {
        JSGarbageCollect(_$_);
    }
}

#endif//__use_javascriptcore_backend__