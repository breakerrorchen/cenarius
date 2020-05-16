
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_invoker
 * */
class i_invoker final {
    __interpreter_friend_class_declare_list__
public:
    i_invoker() = default;
private:
    FunctionCallback        constructor_ = nullptr;
    AccessorGetterCallback  attr_getter_ = nullptr;
    AccessorSetterCallback  attr_setter_ = nullptr;
    FunctionCallback        as_function_ = nullptr;
};


}}