
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_str decalre and implement
 * */
i_str::i_str(const i_context& context) {
    if (!context._$_.IsEmpty()) {
        isolate_ = context._$_->GetIsolate();
        context_.Reset(isolate_, context._$_);
        if (!context_.IsWeak()) {
            context_.SetWeak();
        }
    }
}

i_str::i_str(const i_context& context, const char* str) {
    if (!context._$_.IsEmpty()) {
        isolate_ = context._$_->GetIsolate();
        context_.Reset(isolate_, context._$_);
        if (!context_.IsWeak()) {
            context_.SetWeak();
        }
    }
    reset(str);
}

i_str::i_str(const i_str& from) {
    operator=(from);
}

i_str::i_str(i_str&& from) {
    operator=(std::move(from));
}

i_str& i_str::operator=(const i_str& from) {
    if (this != &from) {
        isolate_ = from.isolate_;
        _$_ = from._$_; context_ = from.context_; 
        if (!context_.IsWeak()) {
            context_.SetWeak();
        }
    }
    return *this;
}

i_str& i_str::operator=(i_str&& from) {
    if (this != &from) {
        isolate_ = from.isolate_; from.isolate_ = nullptr;
        _$_ = std::move(from._$_);
        context_ = std::move(from.context_);
    }
    return *this;
}

bool i_str::is_useable() const {
    return isolate_ && 
        !_$_.IsEmpty() && context_.IsEmpty();
}

bool i_str::reset(const char* str) {
    if (nullptr != str) {
        if (nullptr != isolate_) {
            auto _str = String::NewFromUtf8(
                isolate_, str, NewStringType::kNormal);
            _$_.Reset(isolate_, _str.ToLocalChecked());
        }
    } else {
        _$_.Reset();
    }
    return true;
}

i_str::operator std::string() const {
    if (!isolate_ || _$_.IsEmpty()) return std::string();
    Local<String> str = _$_.Get(isolate_);
    std::string cxx_str = 
        *(String::Utf8Value(isolate_, str));
    return cxx_str;
}

i_str::operator i_value() const {
    if (!isolate_) { return i_value(); }
    auto context = context_.Get(isolate_);
    auto str = _$_.Get(isolate_);
    return i_value(context, Local<Value>::Cast(str));
}

#endif//__use_v8_backend__