
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_object_holder decalre and implement
 * persistence of javascript object
 * */
class i_object_holder final {
    __interpreter_friend_class_declare_list__
private:
    i_object_holder(Local<Context>, Local<Object>);
public:
    virtual ~i_object_holder() = default;
    i_object_holder() = default;
    i_object_holder(const i_object_holder&);
    i_object_holder(i_object_holder&&);
    i_object_holder(const i_object&);
    i_object_holder& operator=(const i_object_holder&);
    i_object_holder& operator=(i_object_holder&&);
    i_object_holder& operator=(const i_object&);

public:
    // check is value is useable
    inline bool is_useable() const { 
        return isolate_ && 
            !_$_.IsEmpty() && !context_.IsEmpty();
    }

    // get related context
    inline i_context get_context() const {
        return i_context(context_.Get(isolate_));
    }

public:
    operator i_object() const;
    operator i_value () const;
    // clear references of javascript object
    void reset();

protected:
    Isolate* isolate_ = nullptr;
    CopyablePersistent<Object>  _$_;
    CopyablePersistent<Context> context_;
};


}}