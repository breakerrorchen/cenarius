
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
template<typename cls> 
using i_invoke_connection_callback = void(cls::*)(i_parameter&);
template<typename cls, typename t> class i_invoke_connection final {
public:
    static i_invoke_connection_callback<cls> invoke_target_;
    static JSObjectRef constructor(__interpreter_constructor_args__) {
        auto ptr = i_runtime_base::cast<i_class_slot>(constructor);
        if (nullptr == ptr || !ptr->_$_) {
            return constructor;
        }
        auto related_data = i_runtime_container<cls>::create();
        auto object = JSObjectMake(context, ptr->_$_, (void*)related_data);
        if (nullptr != invoke_target_) {
            auto data = dynamic_cast<cls*>(related_data);
            i_parameter parameter;
            parameter.object_this_    = object;
            parameter.context_        = context;
            parameter.argument_count_ = argument_count;
            parameter.arguments_      = (JSValueRef*)arguments;
            (((cls*)(related_data->isa_))->*invoke_target_)(parameter);
            if (parameter.exception_) {
                *exception = parameter.exception_;
            }
        }
        return object;
    }

    static JSValueRef as_function(__interpreter_func_args__) {
        auto data = i_runtime_base::cast<cls>(this_object);
        if (nullptr != invoke_target_ && nullptr != data) {
            i_parameter parameter;
            parameter.object_this_    = this_object;
            parameter.context_        = context;
            parameter.argument_count_ = argument_count;
            parameter.arguments_      = (JSValueRef*)arguments;
            (data->*invoke_target_)(parameter);
            if (parameter.exception_) {
                *exception = parameter.exception_;
            }
            return parameter.ret_;
        }
        return JSValueMakeUndefined(context);
    }

    static JSValueRef attr_getter(__interpreter_attr_getter_args__) {
        auto data = i_runtime_base::cast<cls>(object);
        if (nullptr != invoke_target_ && nullptr != data) {
            i_parameter parameter;
            parameter.object_this_ = object;
            parameter.context_     = context;
            (data->*invoke_target_)(parameter);
            if (parameter.exception_) {
                *exception = parameter.exception_;
            }
            return parameter.ret_;
        }
        return JSValueMakeUndefined(context);
    }

    static bool attr_setter(__interpreter_attr_setter_args__) {
        auto data = i_runtime_base::cast<cls>(object);
        if (nullptr != invoke_target_ && nullptr != data) {
            i_parameter parameter;
            parameter.object_this_    = object;
            parameter.context_        = context;
            parameter.argument_count_ = 1;
            parameter.arguments_      = &value;
            (data->*invoke_target_)(parameter);
            if (parameter.exception_) {
                *exception = parameter.exception_;
            }
        }
        return true;
    }

public:
    inline operator i_invoker() const {
        i_invoker invoker;
        invoker.as_function_ = &i_invoke_connection<cls, t>::as_function;
        invoker.attr_getter_ = &i_invoke_connection<cls, t>::attr_getter;
        invoker.attr_setter_ = &i_invoke_connection<cls, t>::attr_setter;
        invoker.constructor_ = &i_invoke_connection<cls, t>::constructor;
        return invoker;
    }
};
template<typename cls, typename t>
i_invoke_connection_callback<cls> i_invoke_connection<cls, t>::invoke_target_;

    
}}