
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
/**
 * i_class
 * */
class i_class final {
    __interpreter_friend_class_declare_list__
public:
    ~i_class() = default;
    i_class() = default;
    i_class(const i_vm&);
    i_class(const i_actuator&);
    i_class(const i_context&);
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
    std::string name_; FunctionCallback constructor_ = nullptr;
    struct attr_item_t {
        std::string             name_  ;
        AccessorSetterCallback  setter_;
        AccessorGetterCallback  getter_;
        i_property_attr         attr_  ;
    };
    std::vector<attr_item_t> attrs_;

    struct func_item_t {
        std::string      name_;
        FunctionCallback func_;
        i_property_attr  attr_;
    };
    std::vector<func_item_t> funcs_;
    Isolate* isolate_ = nullptr;
    CopyablePersistent<FunctionTemplate> _$_parent_, _$_;
    CopyablePersistent<ObjectTemplate>   _$_object_template_;
};


}}