
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_invoke_function  用来和静态函数进行绑定
 * */
using i_invoke_function_callback = void(*)(i_parameter&);
template<typename cls> class i_invoke_function final {
public:
    static i_invoke_function_callback invoker_;
    static JSValueRef invoke(__interpreter_func_args__) {
        if (nullptr == invoker_) {
            return JSValueMakeUndefined(context);
        }
        i_parameter parameter;
        parameter.object_this_    = this_object;
        parameter.context_        = context;
        parameter.argument_count_ = argument_count;
        parameter.arguments_      = (JSValueRef*)arguments;
        invoker_(parameter);
        if (parameter.exception_) {
            *exception = parameter.exception_;
        }
        return parameter.ret_;
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