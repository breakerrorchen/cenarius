
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_object_holder decalre and implement
 * persistence of javascript object
 * */
class i_object_holder final {
    __interpreter_friend_class_declare_list__
private:
    i_object_holder(JSContextRef, JSObjectRef);
public:
    virtual ~i_object_holder();
    i_object_holder();
    i_object_holder(const i_object_holder&);
    i_object_holder(i_object_holder&&);
    i_object_holder(const i_object&);
    i_object_holder& operator=(const i_object_holder&);
    i_object_holder& operator=(i_object_holder&&);
    i_object_holder& operator=(const i_object&);

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
    operator i_object() const;
    operator i_value () const;
    // clear references of javascript object
    void reset();

protected:
    i_context context_; JSObjectRef _$_ = nullptr; 
};

    
}}