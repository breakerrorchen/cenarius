
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_str decalre and implement
 * */
class i_str final {
    __interpreter_friend_class_declare_list__
private:
    i_str(Local<Context> context, Local<String> str) {
        if (!context.IsEmpty()) {
            isolate_ = context->GetIsolate();
            context_.Reset(isolate_, context);
            context_.SetWeak();
            if (!str.IsEmpty()) {
                _$_.Reset(isolate_, str);
            }
        }
    }
public:
    virtual ~i_str() = default;
    i_str(const i_context&);
    i_str(const i_context&, const char* str = nullptr);
    i_str(const i_str&);
    i_str(i_str&&);
    i_str& operator=(const i_str&);
    i_str& operator=(i_str&&);

public:
    // check is value is useable
    bool is_useable() const;
    // reset or set cxx string
    bool reset(const char* str = nullptr);
    // convert to cxx string
    operator std::string() const;
    // to value
    operator i_value() const;

protected:
    Isolate* isolate_ = nullptr;
    CopyablePersistent<String>  _$_;
    CopyablePersistent<Context> context_;
};



}}