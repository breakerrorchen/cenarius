
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_parameter
 * */
class i_parameter final {
    __interpreter_friend_class_declare_list__
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
    JSContextRef context_    = nullptr;
    JSObjectRef object_this_ = nullptr;
    size_t argument_count_   = 0;
    JSValueRef* arguments_   = nullptr;
    JSValueRef ret_          = nullptr;
    JSValueRef exception_    = nullptr;
};

    
}}