
#if defined(__use_v8_backend__)
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>
#include "interpreter.h"
using namespace interpreter;
using namespace v8_backend;

/**
 * i_class
 * */
i_class::i_class(const i_vm& vm):isolate_(vm._$_) {
    ;
}

i_class::i_class(const i_actuator& actuator) 
    : isolate_(actuator.vm_) {
    ;
}

i_class::i_class(const i_context& _context)
    : isolate_(_context._$_->GetIsolate()) {
    ;
}

i_class::i_class(const i_class& from) {
    operator=(from);
}

i_class::i_class(i_class&& from) {
    operator=(std::move(from));
}

i_class& i_class::operator=(const i_class& from) {
    if (this != &from) {
        constructor_ = from.constructor_;
        name_ = from.name_;
        attrs_ = from.attrs_; 
        funcs_ = from.funcs_;
        isolate_ = from.isolate_;
        _$_ = from._$_;
        _$_parent_ = from._$_parent_;
        _$_object_template_ = from._$_object_template_;
    }
    return *this;
}

i_class& i_class::operator=(i_class&& from) {
    if (this != &from) {
        constructor_ = from.constructor_;
        from.constructor_ = nullptr;
        name_  = std::move(from.name_ );
        attrs_ = std::move(from.attrs_); 
        funcs_ = std::move(from.funcs_);
        isolate_ = from.isolate_; from.isolate_ = nullptr;
        _$_ = std::move(from._$_);
        _$_parent_ = std::move(from._$_parent_);
        _$_object_template_ = std::move(from._$_object_template_);
    }
    return *this;
}

void i_class::parent(const i_class& from) {
    _$_parent_ = from._$_;
}

void i_class::name(const char* name) {
    name_ = name;
}

void i_class::constructor(i_invoker invoke) {
    constructor_ = invoke.constructor_;
}

void i_class::attr(const char* name, 
    i_invoker setter, i_invoker getter, i_property_attr attr) {
    if (!name) return;
    attr_item_t item; item.name_ = name;
    item.setter_ = setter.attr_setter_;
    item.getter_ = getter.attr_getter_;
    item.attr_   = attr;
    attrs_.push_back(item);
}

void i_class::function(
    const char* name, i_invoker func, i_property_attr attr) {
    if (!name) return;
    func_item_t item; item.name_ = name;
    item.func_ = func.as_function_;
    item.attr_ = attr;
    funcs_.push_back(item);
}

void i_class::build() {
    if (!isolate_) return; 
    if (!_$_.IsEmpty()) { _$_.Reset(); }
    auto function_template = FunctionTemplate::New(isolate_, constructor_);
    _$_.Reset(isolate_, function_template);
    if (!_$_parent_.IsEmpty()) {
        function_template->Inherit(_$_parent_.Get(isolate_));
    }
    auto object_template = function_template->InstanceTemplate();
    object_template->SetInternalFieldCount(1);
    for (auto& item : attrs_) {
        Local<String> k;
        String::NewFromUtf8(isolate_, 
            item.name_.c_str(), NewStringType::kNormal).ToLocal(&k);
        auto attr = (PropertyAttribute)item.attr_;
        object_template->SetAccessor(k, item.getter_, item.setter_, 
            Local<Value>(), DEFAULT, attr);
    }

    for (auto& item : funcs_) {
        Local<String> k;
        String::NewFromUtf8(isolate_, 
            item.name_.c_str(), NewStringType::kNormal).ToLocal(&k);
        auto attr = (PropertyAttribute)item.attr_;
        object_template->Set(
            k, FunctionTemplate::New(isolate_, item.func_), attr);
    }
    _$_object_template_.Reset(isolate_, object_template);
}

i_value i_class::to_value(const i_context& context) const {
    if (!context.is_useable() || !isolate_) { return i_value(); }
    auto func_tmpl = _$_.Get(isolate_);
    if (func_tmpl.IsEmpty()) return i_value();
    Local<Function> function;
    func_tmpl->GetFunction(context._$_).ToLocal(&function);
    return i_value(context._$_, Local<Value>::Cast(function));
}

bool i_class::is_instance_of(
    const i_context&, const i_object& object) {
    if (object._$_.IsEmpty() || _$_.IsEmpty()) return false;
    return _$_.Get(isolate_)
        ->HasInstance(Local<Value>::Cast(object._$_));
}

bool i_class::is_instance_of(
    const i_context&, const i_value& value) {
    if (value._$_.IsEmpty() || _$_.IsEmpty()) return false;
    return _$_.Get(isolate_)->HasInstance(value._$_);
}

i_object i_class::create_new_instance(const i_context& context) {
    if (!context.is_useable()) return i_object();
    if (_$_object_template_.IsEmpty() || !isolate_) {
        return i_object();
    }
    auto obt = _$_object_template_.Get(isolate_);
    if (obt.IsEmpty()) { return i_object(); }
    Local<Object> _object;
    if (!obt->NewInstance(context._$_).ToLocal(&_object)) {
        return i_object();
    }
    return i_object(context._$_, _object);
}

#endif//__use_v8_backend__