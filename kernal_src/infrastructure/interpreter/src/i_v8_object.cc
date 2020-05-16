
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_object decalre and implement
 * persistence of javascript value
 * */
i_object::i_object(const i_context& context) {
    context_ = context;
}

i_object::i_object(const i_object& from) {
    operator=(from);
}

i_object::i_object(i_object&& from) {
    operator=(std::move(from));
}

i_object& i_object::operator=(const i_object& from) {
    if (this != &from) {
        context_ = from.context_; _$_ = from._$_;
    }
    return *this;
}

i_object& i_object::operator=(i_object&& from) {
    if (this != &from) {
        _$_ = std::move(from._$_);
        context_ = std::move(from.context_);
    }
    return *this;
}

bool i_object::can_hold_native_data() const {
    if (_$_.IsEmpty()) { return false; }
    return _$_->InternalFieldCount() > 0;
}

bool i_object::hold_native_data(i_runtime_base* base_ptr) const {
    if (!context_.is_useable() || _$_.IsEmpty()) {
        return false;
    }
    if (_$_->InternalFieldCount() <= 0) return false;
    auto isolate = context_._$_->GetIsolate();
    auto void_ptr = reinterpret_cast<void*>(base_ptr);
    if (nullptr == void_ptr) {
        _$_->SetInternalField(
            0, Local<Value>::Cast(Null(isolate)));
    } else {
        auto external = External::New(isolate, void_ptr);
        _$_->SetInternalField(
            0, Local<Value>::Cast(external));
        base_ptr->external_.Reset(isolate, external);
        base_ptr->external_.SetWrapperClassId(1);
        base_ptr->external_.SetWeak(base_ptr, [](
            const WeakCallbackInfo<i_runtime_base>& data) {
            auto base_ptr = data.GetParameter();
            if (nullptr != base_ptr) {
                auto release = dynamic_cast<
                    i_runtime_release*>(base_ptr);
                if (nullptr != release) {
                    release->on_runtime_release();
                }
                base_ptr->force_release();
            }
        }, WeakCallbackType::kParameter);
    }
    return true;
}

bool i_object::get_prototype(i_value& v) const {
    if (_$_.IsEmpty()) {
        v._$_ = Local<Value>();
        return false;
    } else {
        v._$_ = _$_->GetPrototype();
        return true;
    }
}

bool i_object::set_prototype(const i_value& v) const {
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto ret = _$_->SetPrototype(context_._$_, v._$_);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::has_field(const i_value& v) const {
    if (v._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto ret = _$_->Has(context_._$_, v._$_);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::has_field(const char* k) const {
    if (!k) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        k, NewStringType::kNormal).ToLocal(&str);
    auto value = Local<Value>::Cast(str);
    auto ret = _$_->Has(context_._$_, value);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::has_field(const i_str& k) const {
    if (!k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    auto str = k._$_.Get(raw_isolate);
    auto value = Local<Value>::Cast(str);
    auto ret = _$_->Has(context_._$_, value);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::del_field(const i_value& k) const {
    if (k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto ret = _$_->Delete(context_._$_, k._$_);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::del_field(const char* k) const {
    if (!k) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        k, NewStringType::kNormal).ToLocal(&str);
    auto value = Local<Value>::Cast(str);
    auto ret = _$_->Delete(context_._$_, value);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::del_field(const i_str& k) const {
    if (!k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    auto str = k._$_.Get(raw_isolate);
    auto value = Local<Value>::Cast(str);
    auto ret = _$_->Delete(context_._$_, value);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::get_field(uint32_t index, i_value& ret) const {
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    ret.context_ = context_;
    auto maybe_value = _$_->Get(context_._$_, index);
    if (!maybe_value.IsEmpty()) {
        ret._$_ = maybe_value.ToLocalChecked();
        return true;
    } else {
        ret._$_ = Local<Value>();
        return false;
    }
}

bool i_object::get_field(const i_value& k, i_value& ret) const {
    if (k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    ret.context_ = context_;
    auto maybe_value = _$_->Get(context_._$_, k._$_);
    if (!maybe_value.IsEmpty()) {
        ret._$_ = maybe_value.ToLocalChecked();
        return true;
    } else {
        ret._$_ = Local<Value>();
        return false;
    }
}

bool i_object::get_field(const i_str& k, i_value& ret) const {
    if (k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    ret.context_ = context_;
    auto raw_isolate = context_._$_->GetIsolate();
    auto str = k._$_.Get(raw_isolate);
    auto value = Local<Value>::Cast(str);
    auto maybe_value = _$_->Get(context_._$_, value);
    if (!maybe_value.IsEmpty()) {
        ret._$_ = maybe_value.ToLocalChecked();
        return true;
    } else {
        ret._$_ = Local<Value>(); 
        return false;
    }
}

bool i_object::get_field(const char* k, i_value& ret) const {
    if (!k) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    ret.context_ = context_;
    auto raw_isolate = context_._$_->GetIsolate();
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        k, NewStringType::kNormal).ToLocal(&str);
    auto value = Local<Value>::Cast(str);
    auto maybe_value = _$_->Get(context_._$_, value);
    if (!maybe_value.IsEmpty()) {
        ret._$_ = maybe_value.ToLocalChecked();
        return true;
    } else {
        ret._$_ = Local<Value>();
        return false;
    }
}

bool i_object::set_field(uint32_t index, const i_value& v) const {
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto ret = _$_->Set(context_._$_, index, v._$_);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::set_field(const i_value& k, 
    const i_value& v, i_property_attr attr) const {
    if (k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto name = Local<Name>::Cast(k._$_);
    if (name.IsEmpty()) return false;
    auto ret = _$_->DefineOwnProperty(context_._$_, 
        name, v._$_, (PropertyAttribute)attr);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;
}

bool i_object::set_field(const i_str& k,
    const i_value& v, i_property_attr attr) const {
    if (k._$_.IsEmpty()) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    auto str = k._$_.Get(raw_isolate);
    auto name = Local<Name>::Cast(str);
    if (name.IsEmpty()) return false;
    auto ret = _$_->DefineOwnProperty(context_._$_, 
        name, v._$_, (PropertyAttribute)attr);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;  
}

bool i_object::set_field(const char* k,
    const i_value& v, i_property_attr attr) const {
    if (!k) return false;
    if (_$_.IsEmpty() || !context_.is_useable()) {
        return false;
    }
    auto raw_isolate = context_._$_->GetIsolate();
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        k, NewStringType::kNormal).ToLocal(&str);
    auto name = Local<Name>::Cast(str);
    if (name.IsEmpty()) return false;
    auto ret = _$_->DefineOwnProperty(context_._$_, 
        name, v._$_, (PropertyAttribute)attr);
    if (!ret.IsNothing()) {
        return ret.ToChecked();
    }
    return false;  
}

i_object_field i_object::operator[](uint32_t k) {
    i_object_field field;
    field.num_k_ = k; 
    field.object_ = _$_; field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](i_value k) {
    i_object_field field;
    field.val_k_ = k._$_; 
    field.object_ = _$_; field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](i_str k)  {
    if (!context_.is_useable()) { return i_object_field(); }
    auto raw_isolate = context_._$_->GetIsolate();
    i_object_field field;
    field.val_k_ = 
        Local<Value>::Cast(k._$_.Get(raw_isolate)); 
    field.object_ = _$_; field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](const char* k) {
    if (!context_.is_useable()) { return i_object_field(); }
    auto raw_isolate = context_._$_->GetIsolate();
    Local<String> str;
    String::NewFromUtf8(raw_isolate, 
        k, NewStringType::kNormal).ToLocal(&str);
    i_object_field field;
    field.val_k_ = Local<Value>::Cast(str);
    field.object_ = _$_; field.context_ = context_._$_;
    return field;
}

i_object i_object::create(const i_context& context) {
    if (!context.is_useable()) {
        return i_object();
    }
    auto raw_isolate = context._$_->GetIsolate();
    auto obt = ObjectTemplate::New(raw_isolate);
    Local<Object> object;
    obt->NewInstance(context._$_).ToLocal(&object);
    return i_object(context._$_, object);
}

#endif//__use_v8_backend__