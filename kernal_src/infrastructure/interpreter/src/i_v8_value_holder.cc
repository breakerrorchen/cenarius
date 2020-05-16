
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_value_holder decalre and implement
 * persistence of javascript value
 * */
i_value_holder::i_value_holder(
    Local<Context> context, Local<Value> value) {
    if (!context.IsEmpty()) {
        isolate_ = context->GetIsolate();
        context_.Reset(isolate_, context);
        context_.SetWeak();
        if (!value.IsEmpty()) { 
            _$_.Reset(isolate_, value); 
        }
    }
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
        isolate_ = from.isolate_; 
        _$_ = from._$_; context_ = from.context_;
    }
    return *this;
}

i_value_holder& i_value_holder::operator=(i_value_holder&& from) {
    if (this != &from) {
        isolate_ = from.isolate_; from.isolate_ = nullptr;
        _$_ = std::move(from._$_);
        context_ = std::move(from.context_);
    }
    return *this;
}

i_value_holder& i_value_holder::operator=(const i_value& from) {
    if (from.context_.is_useable() && !from._$_.IsEmpty()) {
        isolate_ = from.context_._$_->GetIsolate();
        _$_.Reset(isolate_, from._$_);
        context_.Reset(isolate_, from.context_._$_);
        context_.SetWeak();
    } else {
        isolate_ = nullptr; context_.Reset(); _$_.Reset();
    }
    return *this;
}

i_value_holder::operator i_value() const {
    if (!isolate_) return i_value();
    return i_value(context_.Get(isolate_), _$_.Get(isolate_));
}

void i_value_holder::reset() {
    isolate_ = nullptr; context_.Reset(); _$_.Reset();
}

#endif//__use_v8_backend__