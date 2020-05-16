
#if defined(__use_javascriptcore_backend__)
#include <JavaScriptCore/JavaScriptCore.h>
#include <JavaScriptCore/JSTypedArray.h>
#include "interpreter.h"
using namespace interpreter;
using namespace javascriptcore_backend;

/**
 * i_class
 * */
i_class::~i_class() {
    if (_$_parent_) { JSClassRelease(_$_parent_); }
    if (_$_) { JSClassRelease(_$_); }
}

i_class::i_class(const i_class& from) {
    operator=(from);
}

i_class::i_class(i_class&& from) {
    operator=(std::move(from));
}

i_class& i_class::operator=(const i_class& from) {
    if (this != &from) {
        if (_$_parent_) { JSClassRelease(_$_parent_); }
        if (_$_) { JSClassRelease(_$_); }
        _$_parent_ = from._$_parent_; _$_ = from._$_;
        name_ = from.name_;
        if (_$_) { JSClassRetain(_$_); }
        if (_$_parent_) { JSClassRetain(_$_parent_); }
        constructor_ = from.constructor_;
        attrs_ = from.attrs_; funcs_ = from.funcs_;
    }
    return *this;
}

i_class& i_class::operator=(i_class&& from) {
    if (this != &from) {
        if (_$_parent_) { JSClassRelease(_$_parent_); }
        if (_$_) { JSClassRelease(_$_); }
        _$_parent_ = from._$_parent_;  
        from._$_parent_ = nullptr;
        _$_ = from._$_; from._$_ = nullptr;
        name_ = std::move(from.name_);
        constructor_ = from.constructor_;
        from.constructor_ = nullptr;
        attrs_ = std::move(from.attrs_);
        funcs_ = std::move(from.funcs_);
    }
    return *this;
}

void i_class::parent(const i_class& _class) {
    if (this != &_class && _$_ != _class._$_) {
        if (_$_parent_) { JSClassRelease(_$_parent_); }
        _$_parent_ = _class._$_parent_;
        if (_$_parent_) { JSClassRetain(_$_parent_); }
    }
}

void i_class::name(const char* name) {
    name_ = name;
}

void i_class::constructor(i_invoker invoker) {
    constructor_ = invoker.constructor_;
}

void i_class::attr(const char* name, i_invoker setter, 
    i_invoker getter, i_property_attr attr) {
    if (!name) return;
    attr_item_t item; item.name_ = name;
    item.setter_ = setter.attr_setter_;
    item.getter_ = getter.attr_getter_;
    item.attr_   = attr;
    if (item.setter_ && item.getter_) {
        attrs_.push_back(item);
    }
}

void i_class::function(const char* name, i_invoker func,
    i_property_attr attr) {
    if (!name) return;
    func_item_t item; item.name_ = name;
    item.func_ = func.as_function_;
    item.attr_ = attr;
    if (item.func_) {
        funcs_.push_back(item);
    }
}

void i_class::build() {
    if (_$_) { JSClassRelease(_$_); _$_ = nullptr; }
    std::vector<JSStaticValue> attrs;
    attrs.reserve(attrs_.size() + 1);
    for (auto& item: attrs_) {
        attrs.push_back({
            item.name_.c_str(), item.getter_, item.setter_,
            (JSPropertyAttributes)item.attr_
        });
    }
    attrs.push_back({nullptr, nullptr, nullptr, 0});
    std::vector<JSStaticFunction> functions;
    functions.reserve(funcs_.size() + 1);
    for (auto& item: funcs_) {
        functions.push_back({
            item.name_.c_str(),  item.func_,
            (JSPropertyAttributes)item.attr_
        });
    }
    functions.push_back({nullptr, nullptr, 0});

    // class define
    JSClassDefinition class_def = {
        0,
        0,
        name_.c_str(),
        _$_parent_,
        &(attrs[0]),
        &(functions[0]),
        nullptr,
        [](JSObjectRef object) {
            auto base = reinterpret_cast<i_runtime_base*>(
                JSObjectGetPrivate(object));
            if (nullptr != base) {
                auto release = dynamic_cast<i_runtime_release*>(base);
                if (nullptr != release) {
                    release->on_runtime_release();
                }
                base->force_release();
            }
            JSObjectSetPrivate(object, nullptr);
        },
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        constructor_,
        nullptr,
        nullptr
    };
    _$_ = JSClassCreate(&class_def);
}

i_value i_class::to_value(const i_context& context) const {
    if (!_$_ || !context._$_) return i_value();
    auto holder = i_runtime_container<i_class_slot>::create(_$_);
    auto object = JSObjectMake(
        context._$_, _$_, reinterpret_cast<void*>(holder));
    return i_value(context._$_, object);
}

bool i_class::is_instance_of(
    const i_context& context, const i_object& object) {
    if (!context._$_ || !_$_ || !object._$_) return false;
    return JSValueIsObjectOfClass(context._$_, object._$_, _$_);
}

bool i_class::is_instance_of(
    const i_context& context, const i_value& value) {
    if (!context._$_ || !_$_ || !value._$_) return false;
    return JSValueIsObjectOfClass(context._$_, value._$_, _$_);
}

i_object i_class::create_new_instance(const i_context& context) {
    if (!context._$_ || !_$_) return i_object();
    auto object = ::JSObjectMake(context._$_, _$_, nullptr);
    return i_object(context._$_, object);
}

#endif//__use_javascriptcore_backend__