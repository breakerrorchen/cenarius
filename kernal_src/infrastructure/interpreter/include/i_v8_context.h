
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_context decalre and implement
 * interpreter actuator context
 * */
class i_context final {
    __interpreter_friend_class_declare_list__
private:
    i_context(Local<Context> context):_$_(context) {
        assert(!_$_.IsEmpty());
    }
public:
    i_context() = default;
    i_context(const i_context&);
    i_context(i_context&&);
    i_context& operator=(const i_context&);
    i_context& operator=(i_context&&);

public:
    // check is value is useable
    inline bool is_useable() const { return !_$_.IsEmpty(); }
    // global object
    i_object get_global_object() const;
    // eval javascript source code
    i_value eval(const char*, i_value* exception = nullptr) const;

public:
    void gc();

protected:
    // a JavaScript execution context. 
    // holds the global object and other execution state
    Local<Context> _$_;
};


}}