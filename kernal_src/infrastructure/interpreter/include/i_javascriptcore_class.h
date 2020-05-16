
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_class
 * */
class i_class final {
    __interpreter_friend_class_declare_list__
public:
    ~i_class();
    i_class() = default;
    i_class(const i_vm&) { ; }
    i_class(const i_actuator&) { ; }
    i_class(const i_context&) { ; }
    i_class(const i_class&);
    i_class(i_class&&);
    i_class& operator=(const i_class&);
    i_class& operator=(i_class&&);

public:
    void parent(const i_class&);
    void name(const char*);
    void constructor(i_invoker);
    void attr(const char*, i_invoker, i_invoker, 
        i_property_attr attr = i_property_attr::none);
    void function(const char*, i_invoker, 
        i_property_attr attr = i_property_attr::none);
    void build();

public:
    // class => value
    i_value to_value(const i_context&) const;
    // is instance
    bool is_instance_of(const i_context&, const i_object&);
    bool is_instance_of(const i_context&, const i_value &);
    // create new class instance
    i_object create_new_instance(const i_context&);

private:
    std::string name_; construct_t constructor_ = nullptr;
    struct attr_item_t {
        std::string     name_  ;
        attr_setter     setter_;
        attr_getter     getter_;
        i_property_attr attr_  ;
    };
    std::vector<attr_item_t> attrs_;

    struct func_item_t {
        std::string     name_;
        function_t      func_;
        i_property_attr attr_;
    };
    std::vector<func_item_t> funcs_;
    JSClassRef _$_parent_ = nullptr, _$_ = nullptr;
};

    
}}