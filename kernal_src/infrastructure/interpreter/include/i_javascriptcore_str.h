
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_str decalre and implement
 * */
class i_str final {
    __interpreter_friend_class_declare_list__
private:
    i_str(JSContextRef context, JSStringRef str)
        : context_(context), _$_(str) {
        if (_$_) { JSStringRetain(_$_); }
    }
public:
    virtual ~i_str();
    i_str(const i_context&);
    i_str(const i_context&, const char* str = nullptr);
    i_str(const i_str&);
    i_str(i_str&&);
    i_str& operator=(const i_str&);
    i_str& operator=(i_str&&);

public:
    // check is value is useable
    inline bool is_useable() const { return _$_; }
    // reset or set cxx string
    bool reset(const char* str = nullptr);
    // convert to cxx string
    operator std::string() const;
    // to value
    operator i_value() const;
    
protected:
    i_context context_; JSStringRef _$_ = nullptr;
};

    
}}