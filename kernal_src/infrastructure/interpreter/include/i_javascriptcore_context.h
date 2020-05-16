
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_context decalre and implement
 * interpreter actuator context
 * */
class i_context final {
    __interpreter_friend_class_declare_list__
private:
    i_context(JSContextRef context):_$_(context) {
        assert(_$_);
    }
public:
    i_context() = default;
    i_context(const i_context&);
    i_context(i_context&&);
    i_context& operator=(const i_context&);
    i_context& operator=(i_context&&);

public:
    // check is value is useable
    inline bool is_useable() const { return _$_; }
    // global object
    i_object get_global_object() const;
    // eval javascript source code
    i_value eval(const char*, i_value* exception = nullptr) const;

public:
    void gc();

protected:
    // a JavaScript execution context. 
    // holds the global object and other execution state
    JSContextRef _$_ = nullptr;
};

    
}}