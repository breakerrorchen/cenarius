
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_object field
 * */
class i_object_field final {
    __interpreter_friend_class_declare_list__
    i_object_field() = default;
public:
    operator i_value();
    i_object_field& operator=(const i_value);
private:
    Local<Value> val_k_; int num_k_ = -1;
    Local<Context> context_; Local<Object> object_;
};


}}