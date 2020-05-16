
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_invoke_connection 用来和对象函数进行绑定
 * */
template<typename cls> 
using i_invoke_connection_callback = void(cls::*)(i_parameter&);
template<typename cls, typename t> class i_invoke_connection final {
public:
    static i_invoke_connection_callback<cls> invoke_target_;
    static void constructor(const FunctionCallbackInfo<Value>& info) {
        HandleScope handle_scope(info.GetIsolate());
        auto raw_isolate = info.GetIsolate();
        auto related_data = i_runtime_container<cls>::create();
        if (invoke_target_) {
            PropertyCallbackInfo<Value>* _null_0 = nullptr;
            PropertyCallbackInfo<void> * _null_1 = nullptr;
            i_parameter parameter(info, *_null_0, *_null_1);
            (((cls*)(related_data->isa_))->*invoke_target_)(parameter);
        }
        auto void_ptr = reinterpret_cast<void*>(related_data);
        auto external = External::New(raw_isolate, void_ptr);
        related_data->external_.Reset(raw_isolate, external);
        related_data->external_.SetWrapperClassId(1);
        related_data->external_.SetWeak(related_data, [](
            const WeakCallbackInfo<i_runtime_base>& data) {
            auto ptr = data.GetParameter();
            if (!ptr) return;
            auto release = dynamic_cast<i_runtime_release*>(ptr);
            if (release) { release->on_runtime_release(); }
            ptr->force_release();
        }, WeakCallbackType::kParameter);
        info.Holder()->SetInternalField(0, external);
    }

    static void as_function(const FunctionCallbackInfo<Value>& info) {
        if (nullptr == invoke_target_) return;
        HandleScope handle_scope(info.GetIsolate());
        PropertyCallbackInfo<Value>* _null_0 = nullptr;
        PropertyCallbackInfo<void> * _null_1 = nullptr;
        i_parameter parameter(info, *_null_0, *_null_1);
        auto ptr = i_runtime_base::cast<cls>(info.Holder());
        if (nullptr != ptr) {
            (ptr->*invoke_target_)(parameter);
        }
    }

    static void attr_getter(Local<String> property, 
        const PropertyCallbackInfo<Value>& info) {
        if (nullptr == invoke_target_) return;
        HandleScope handle_scope(info.GetIsolate());
        FunctionCallbackInfo<Value>* _null_0 = nullptr;
        PropertyCallbackInfo<void> * _null_1 = nullptr;
        i_parameter parameter(info, *_null_0, *_null_1);
        auto ptr = i_runtime_base::cast<cls>(info.Holder());
        if (nullptr != ptr) {
            (ptr->*invoke_target_)(parameter);
        }
    }

    static void attr_setter(Local<String> property,
        Local<Value> value, const PropertyCallbackInfo<void>& info) {
        if (nullptr == invoke_target_) return;
        HandleScope handle_scope(info.GetIsolate());
        FunctionCallbackInfo<Value>* _null_0 = nullptr;
        PropertyCallbackInfo<Value>* _null_1 = nullptr;
        i_parameter parameter(info, *_null_0, *_null_1, value);
        auto ptr = i_runtime_base::cast<cls>(info.Holder());
        if (nullptr != ptr) {
            (ptr->*invoke_target_)(parameter);
        }
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