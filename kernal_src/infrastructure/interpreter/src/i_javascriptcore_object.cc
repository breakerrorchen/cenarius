
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

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
        context_ = std::move(from.context_); 
        _$_ = from._$_; from._$_ = nullptr;
    }
    return *this;
}

bool i_object::can_hold_native_data() const {
    if (!_$_) return false;
    if (JSObjectGetPrivate(_$_)) return true;
    static int data = 0;
    JSObjectSetPrivate(_$_, (void*)&data);
    auto can = !!JSObjectGetPrivate(_$_);
    JSObjectSetPrivate(_$_, nullptr);
    return can;
}

bool i_object::hold_native_data(i_runtime_base* base_ptr) const {
    if (!can_hold_native_data()) return false;
    auto base = reinterpret_cast<i_runtime_base*>(
        JSObjectGetPrivate(_$_));
    if (nullptr != base) {
        auto release = dynamic_cast<i_runtime_release*>(base);
        if (nullptr != release) {
            release->on_runtime_release();
        }
        base->force_release();
    }
    auto void_ptr = reinterpret_cast<void*>(base_ptr);
    if (nullptr == void_ptr){
        JSObjectSetPrivate(_$_, nullptr);
        return false;
    } else {
        JSObjectSetPrivate(_$_, void_ptr);
        return JSObjectGetPrivate(_$_) == void_ptr;
    }
    return true;
}

bool i_object::get_prototype(i_value& value) const {
    if (!context_._$_ || !_$_) {
        value._$_ = nullptr;
        return false;
    }
    value.context_ = context_;
    value._$_ = JSObjectGetPrototype(context_._$_, _$_);
    return true;
}

bool i_object::set_prototype(const i_value& value) const {
    if (!context_._$_ || !_$_) { return false; }
    JSObjectSetPrototype(context_._$_, _$_, value._$_);
    return true;
}

bool i_object::has_field(const i_value& value) const {
    if (!context_._$_ || !_$_ || !value._$_) return false;
    return JSObjectHasPropertyForKey(
        context_._$_, _$_, value._$_, nullptr);
}

bool i_object::has_field(const char* k) const {
    if (!context_._$_ || !_$_ || !k) return false;
    auto jsstr = JSStringCreateWithUTF8CString(k);
    auto has = JSObjectHasProperty(context_._$_, _$_, jsstr);
    JSStringRelease(jsstr);
    return has;
}

bool i_object::has_field(const i_str& str) const {
    if (!context_._$_ || !_$_ || !str._$_) return false;
    return JSObjectHasProperty(context_._$_, _$_, str._$_);
}

bool i_object::del_field(const i_value& value) const {
    if (!context_._$_ || !_$_ || !value._$_) return false;
    return JSObjectDeletePropertyForKey(
        context_._$_, _$_, value._$_, nullptr);
}

bool i_object::del_field(const char* k) const {
    if (!context_._$_ || !_$_ || !k) return false;
    auto jsstr = JSStringCreateWithUTF8CString(k);
    auto success = JSObjectDeleteProperty(
        context_._$_, _$_, jsstr, nullptr);
    JSStringRelease(jsstr);
    return success;
}

bool i_object::del_field(const i_str& str) const {
    if (!context_._$_ || !_$_ || !str._$_) return false;
    return JSObjectDeleteProperty(
        context_._$_, _$_, str._$_, nullptr);
}

bool i_object::get_field(uint32_t index, i_value& value) const {
    if (!context_._$_ || !_$_) {
        value._$_ = nullptr;
        return false;
    }
    value.context_ = context_;
    value._$_ = JSObjectGetPropertyAtIndex(
        context_._$_, _$_, (unsigned)index, nullptr);
    return true;
}

bool i_object::get_field(const i_value& k, i_value& value) const {
    if (!context_._$_ || !_$_ || !k._$_) {
        value._$_ = nullptr;
        return false;
    }
    value.context_ = context_;
    value._$_ = JSObjectGetPropertyForKey(
        context_._$_, _$_, k._$_, nullptr);
    return true;
}

bool i_object::get_field(const i_str& k, i_value& value) const {
    if (!context_._$_ || !_$_ || !k._$_) {
        value._$_ = nullptr;
        return false;
    }
    value.context_ = context_;
    value._$_ = JSObjectGetProperty(
        context_._$_, _$_, k._$_, nullptr);
    return true;
}

bool i_object::get_field(const char* k, i_value& value) const {
    if (!context_._$_ || !_$_ || !k)  {
        value._$_ = nullptr;
        return false;
    }
    value.context_ = context_;
    auto jsstr = JSStringCreateWithUTF8CString(k);
    value._$_ = JSObjectGetProperty(
        context_._$_, _$_, jsstr, nullptr);
    JSStringRelease(jsstr);
    return true;
}

bool i_object::set_field(uint32_t index, const i_value& value) const {
    if (!context_._$_ || !_$_) return false;
    JSObjectSetPropertyAtIndex(
        context_._$_, _$_, index, value._$_, nullptr);
    return true;
}

bool i_object::set_field(const i_value& k, 
    const i_value& value, i_property_attr attr) const {
    if (!context_._$_ || !_$_ || !k._$_) return false;
    JSObjectSetPropertyForKey(
        context_._$_, _$_, k._$_, value._$_,
        (JSPropertyAttributes)attr, nullptr);
    return true;
}

bool i_object::set_field(const i_str& k,
    const i_value& value, i_property_attr attr) const {
    if (!context_._$_ || !_$_ || !k._$_) return false;
    JSObjectSetProperty(
        context_._$_, _$_, k._$_, value._$_,
        (JSPropertyAttributes)attr, nullptr);
    return true;
}

bool i_object::set_field(const char* k,
    const i_value& value, i_property_attr attr) const {
    if (!context_._$_ || !_$_ || !k) return false;
    auto jsstr = JSStringCreateWithUTF8CString(k);
    JSObjectSetProperty(
        context_._$_, _$_, jsstr, value._$_,
        (JSPropertyAttributes)attr, nullptr);
    JSStringRelease(jsstr);
    return true;
}

i_object_field i_object::operator[](uint32_t k) {
    i_object_field field;
    field.num_k_ = k; field.object_ = _$_;
    field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](i_value k) {
    i_object_field field;
    field.val_k_ = k._$_; field.object_ = _$_;
    field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](i_str k) {
    i_object_field field;
    field.str_k_ = k._$_; field.object_ = _$_;
    if (field.str_k_) {
        JSStringRetain(field.str_k_);
    }
    field.context_ = context_._$_;
    return field;
}

i_object_field i_object::operator[](const char* k) {
    i_object_field field; field.object_ = _$_;
    auto jsstr = JSStringCreateWithUTF8CString(k);
    field.str_k_ = jsstr;
    if (field.str_k_) {
        JSStringRetain(field.str_k_);
    }
    field.context_ = context_._$_;
    return field;
}

i_object i_object::create(const i_context& context) {
    if (!context._$_) return i_object();
    i_object object(context);
    object._$_ = JSObjectMake(
        context._$_, i_initializer::_$_class_, nullptr);
    return object;
}

#endif//__use_javascriptcore_backend__