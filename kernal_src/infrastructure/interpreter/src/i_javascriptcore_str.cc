
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_str decalre and implement
 * */
i_str::~i_str() { 
    if (_$_) { JSStringRelease(_$_); }
}

i_str::i_str(const i_context& context) {
    context_ = JSContextGetGlobalContext(context._$_);
}

i_str::i_str(const i_context& context, const char* str) {
    context_ = JSContextGetGlobalContext(context._$_);
    if (str && context._$_) {
        _$_ = JSStringCreateWithUTF8CString(str);
    }
}

i_str::i_str(const i_str& from) {
    operator=(from);
}

i_str::i_str(i_str&& from) {
    operator=(std::move(from));
}

i_str& i_str::operator=(const i_str& from) {
    if (this != &from) {
        reset(nullptr);
        context_ = from.context_; _$_ = from._$_;
        if (_$_) {
            JSStringRetain(_$_);
        }
    }
    return *this;
}

i_str& i_str::operator=(i_str&& from) {
    if (this != &from) {
        reset(nullptr);
        context_ = std::move(from.context_);
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

bool i_str::reset(const char* str) {
    if (_$_) { JSStringRelease(_$_); }
    _$_ = nullptr;
    if (str) {
        _$_ = JSStringCreateWithUTF8CString(str);
    }
    return true;
}

i_str::operator std::string() const {
    if (!_$_) return std::string();
    std::string cxx_str;
    cxx_str.resize(JSStringGetMaximumUTF8CStringSize(_$_));
    if (0 == cxx_str.length()) return std::string();
    size_t write_size = JSStringGetUTF8CString(
        _$_, (char*)(cxx_str.c_str()), cxx_str.length());
    cxx_str.resize(write_size);
    return cxx_str;
}

i_str::operator i_value() const {
    if (!_$_ || !context_._$_) {
        return i_value(nullptr, nullptr);
    }
    return i_value(context_._$_, 
        JSValueMakeString(context_._$_, _$_));
}

#endif//__use_javascriptcore_backend__