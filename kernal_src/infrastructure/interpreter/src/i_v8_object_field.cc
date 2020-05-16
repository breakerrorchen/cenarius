
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_object field
 * */
i_object_field::operator i_value() {
    if (context_.IsEmpty() || object_.IsEmpty()) {
        return i_value();
    }
    Local<Value> field_value;
    if (!val_k_.IsEmpty()) {
        auto maybe_value = object_->Get(context_, val_k_);
        if (!maybe_value.IsEmpty()) {
            field_value = maybe_value.ToLocalChecked();
        }
    } else if (num_k_ >= 0) {
        auto maybe_value = object_->Get(context_, num_k_);
        if (!maybe_value.IsEmpty()) {
            field_value = maybe_value.ToLocalChecked();
        }
    }
    return i_value(context_, field_value);
}

i_object_field& i_object_field::operator=(const i_value v) {
    if (!context_.IsEmpty() && !object_.IsEmpty()) {
        if (!val_k_.IsEmpty()) {
            auto name = Local<Name>::Cast(val_k_);
            object_->DefineOwnProperty(
                context_, name, v._$_, None);
        } else if (num_k_ >= 0) {
            object_->Set(context_, num_k_, v._$_);
        }
    }
    return *this;
}

#endif//__use_v8_backend__