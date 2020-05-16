
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_object decalre and implement
 * persistence of javascript value
 * */
class i_object final {
    __interpreter_friend_class_declare_list__
    i_object(JSContextRef ctx, JSObjectRef object)
        :_$_(object), context_(ctx) {
        ;
    }
public:
    i_object() = default;
    i_object(const i_context&);
    i_object(const i_object&);
    i_object(i_object&&);
    i_object& operator=(const i_object&);
    i_object& operator=(i_object&&);

public:
    // check is value is useable
    inline bool is_useable() const {
        return _$_ && context_.is_useable();
    }

    // get related context
    inline i_context get_context() const {
        return context_;
    }

public:
    /**
     * hold native data, 
     * */
    bool can_hold_native_data() const;
    bool hold_native_data(i_runtime_base*) const;

    // prototype and fields
    bool get_prototype(i_value&)             const;
    bool set_prototype(const i_value&)       const;
    bool has_field(const i_value&)           const;
    bool has_field(const char*)              const;
    bool has_field(const i_str&)             const;
    bool del_field(const i_value&)           const;
    bool del_field(const char*)              const;
    bool del_field(const i_str&)             const;
    bool get_field(uint32_t,       i_value&) const;
    bool get_field(const i_value&, i_value&) const;
    bool get_field(const i_str&,   i_value&) const;
    bool get_field(const char*,    i_value&) const;
    bool set_field(uint32_t,       const i_value&) const;
    bool set_field(const i_value&, const i_value&, i_property_attr) const;
    bool set_field(const i_str&,   const i_value&, i_property_attr) const;
    bool set_field(const char*,    const i_value&, i_property_attr) const;

public:
    i_object_field operator[](uint32_t);
    i_object_field operator[](i_value);
    i_object_field operator[](i_str);
    i_object_field operator[](const char*);

public:
    // create empty object
    static i_object create(const i_context&);

protected:
    i_context context_; JSObjectRef _$_ = nullptr;
};

    
}}