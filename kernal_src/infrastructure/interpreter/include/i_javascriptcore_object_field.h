
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_object field
 * */
class i_object_field final {
    __interpreter_friend_class_declare_list__
    i_object_field() = default;
public:
    ~i_object_field();
public:
    operator i_value();
    i_object_field& operator=(const i_value);
private:
    JSStringRef str_k_; JSValueRef val_k_;
    int num_k_ = -1;
    JSContextRef context_; JSObjectRef object_;
};

    
}}