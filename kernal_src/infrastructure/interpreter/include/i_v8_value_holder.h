
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_value_holder decalre and implement
 * persistence of javascript value
 * */
class i_value_holder final {
    __interpreter_friend_class_declare_list__
private:
    i_value_holder(Local<Context>, Local<Value>);
public:
    virtual ~i_value_holder() = default;
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
        return isolate_ &&
            !_$_.IsEmpty() && !context_.IsEmpty();
    }

    // get related context
    inline i_context get_context() const {
        return i_context(context_.Get(isolate_));
    }

public:
    operator i_value() const;
    // clear references of javascript value
    void reset();

protected:
    Isolate* isolate_ = nullptr;
    CopyablePersistent<Value>  _$_;
    CopyablePersistent<Context> context_;
};


}}