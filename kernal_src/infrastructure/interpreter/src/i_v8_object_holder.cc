
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_object_holder decalre and implement
 * persistence of javascript object
 * */
i_object_holder::i_object_holder(
    Local<Context> context, Local<Object> object) {
    if (!context.IsEmpty()) {
        isolate_ = context->GetIsolate();
        context_.Reset(isolate_, context);
        context_.SetWeak();
        if (!object.IsEmpty()) { 
            _$_.Reset(isolate_, object); 
        }
    }
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
        isolate_ = from.isolate_; _$_ = from._$_;
        context_ = from.context_;
    }
    return *this;
}

i_object_holder& i_object_holder::operator=(i_object_holder&& from) {
    if (this != &from) {
        isolate_ = from.isolate_; from.isolate_ = nullptr;
        _$_ = std::move(from._$_);
        context_ = std::move(from.context_);
    }
    return *this;
}

i_object_holder& i_object_holder::operator=(const i_object& from) {
    if (from.context_.is_useable()) {
        isolate_ = from.context_._$_->GetIsolate();
        _$_.Reset(isolate_, from._$_);
        context_.Reset(isolate_, from.context_._$_);
        context_.SetWeak();
    } else {
        isolate_ = nullptr; _$_.Reset(); context_.Reset();
    }
    return *this;
}

i_object_holder::operator i_object() const {
    if (nullptr == isolate_) return i_object();
    return i_object(context_.Get(isolate_), _$_.Get(isolate_));
}

i_object_holder::operator i_value() const {
    if (nullptr == isolate_) return i_value();
    auto v = Local<Value>::Cast(_$_.Get(isolate_));
    return i_value(context_.Get(isolate_), v);
}

#endif//__use_v8_backend__