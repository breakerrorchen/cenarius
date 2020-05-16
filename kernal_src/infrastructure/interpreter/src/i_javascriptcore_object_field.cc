
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_object field
 * */
i_object_field::~i_object_field() {
    if (str_k_) { 
        JSStringRelease(str_k_); 
    }
}

i_object_field::operator i_value() {
    if (!object_ || !context_) return i_value();
    JSValueRef field_value = nullptr;
    if (str_k_) {
        field_value = JSObjectGetProperty(
            context_, object_, str_k_, nullptr);
    } else if (val_k_) {
        field_value = JSObjectGetPropertyForKey(
            context_, object_, val_k_, nullptr);
    } else if (num_k_ >= 0) {
        field_value = JSObjectGetPropertyAtIndex(
            context_, object_, num_k_, nullptr);
    }
    return i_value(context_, field_value);
}

i_object_field& i_object_field::operator=(const i_value value) {
    if (!object_ || !context_) return *this;
    if (str_k_) {
        JSObjectSetProperty(
            context_, object_, str_k_, value._$_,
            kJSPropertyAttributeNone, nullptr);   
    } else if (val_k_) {
        JSObjectSetPropertyForKey(
            context_, object_, val_k_, value._$_,
            kJSPropertyAttributeNone, nullptr);  
    } else if (num_k_ >= 0) {
        JSObjectSetPropertyAtIndex(context_, 
            object_, num_k_, value._$_, nullptr);
    }
    return *this;
}

#endif//__use_javascriptcore_backend__