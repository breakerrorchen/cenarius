
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_parameter
 * */
class i_parameter final {
    __interpreter_friend_class_declare_list__
private:
    i_parameter(const FunctionCallbackInfo<Value>& _,
        const PropertyCallbackInfo<Value>& _null_0,
        const PropertyCallbackInfo<void>&  _null_1)
        : function_(_), getter_(_null_0), setter_(_null_1)
        , kind_(0) {
        ;
    }
    i_parameter(const PropertyCallbackInfo<Value>& _,
        const FunctionCallbackInfo<Value>& _null_0,
        const PropertyCallbackInfo<void>&  _null_1)
        : getter_(_), function_(_null_0), setter_(_null_1)
        , kind_(1) {
        ;
    }
    i_parameter(const PropertyCallbackInfo<void>& _,
        const FunctionCallbackInfo<Value>& _null_0,
        const PropertyCallbackInfo<Value>& _null_1,
        Local<Value> value)
        : setter_(_), function_(_null_0), getter_(_null_1)
        , kind_(2), setter_value_(value) {
        ;
    }

public:
    // get context
    i_context get_context() const;
    // get this
    i_object get_this() const;
    // get argument
    i_value get_argument_at(int) const;
    // get argument_count
    size_t get_argument_count() const;
    // 
    i_value operator[](int) const;
    // set return
    void set_return(i_value);
    // set exception
    void set_exception(i_value);

private:
    // 0 -> func 1 -> getter 2 -> setter
    uint8_t kind_ = 0;
    const FunctionCallbackInfo<Value>& function_    ;
    const PropertyCallbackInfo<Value>& getter_      ;
    Local<Value>                       setter_value_;
    const PropertyCallbackInfo<void>&  setter_      ;
};


}}