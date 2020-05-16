
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_invoke_function  用来和静态函数进行绑定
 * */
using i_invoke_function_callback = void(*)(i_parameter&);
template<typename cls> class i_invoke_function final {
public:
    static i_invoke_function_callback invoker_;
    static void invoke(const FunctionCallbackInfo<Value>& info) {
        if (nullptr != invoker_) {
            HandleScope handle_scope(info.GetIsolate());
            PropertyCallbackInfo<Value>* _null_0 = nullptr;
            PropertyCallbackInfo<void> * _null_1 = nullptr;
            i_parameter parameter(info, *_null_0, *_null_1);
            invoker_(parameter);
        }
    }

public:
    inline operator i_invoker() const {
        i_invoker invoker;
        invoker.as_function_ = &i_invoke_function<cls>::invoke;
        return invoker;
    }
};
template<typename cls> 
i_invoke_function_callback i_invoke_function<cls>::invoker_;


}}