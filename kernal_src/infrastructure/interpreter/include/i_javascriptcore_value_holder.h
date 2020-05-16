
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_value_holder decalre and implement
 * persistence of javascript value
 * */
class i_value_holder final {
    __interpreter_friend_class_declare_list__
private:
    i_value_holder(JSContextRef, JSValueRef);
public:
    virtual ~i_value_holder();
    i_value_holder() = default;
    i_value_holder(const i_value_holder&);
    i_value_holder(i_value_holder&&);
    i_value_holder(const i_value&);
    i_value_holder& operator=(const i_value_holder&);
    i_value_holder& operator=(i_value_holder&&);
    i_value_holder& operator=(const i_value&);

public:
    // check is value is useable
    inline bool is_useable() const { 
        return _$_ && context_.is_useable(); 
    }

    // get related context
    inline i_context get_context() const {
        return context_;
    }

public:
    operator i_value() const;
    // clear references of javascript value
    void reset();

protected:
    i_context context_; JSValueRef _$_ = nullptr;
};

    
}}