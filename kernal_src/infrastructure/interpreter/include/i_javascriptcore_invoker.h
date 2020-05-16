
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_invoker
 * */
class i_invoker final {
    __interpreter_friend_class_declare_list__
public:
    i_invoker() = default;
private:
    JSObjectCallAsConstructorCallback constructor_ = nullptr;
    JSObjectGetPropertyCallback       attr_getter_ = nullptr;
    JSObjectSetPropertyCallback       attr_setter_ = nullptr;
    JSObjectCallAsFunctionCallback    as_function_ = nullptr;
};

    
}}