
#pragma once
#if !defined(__use_v8_backend__)
#error only build for v8
#endif
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <memory>
#include <mutex>
#include <functional>
#include <typeindex>
#include <v8.h>
#include <v8-util.h>
#include <v8-inspector.h>
#include <libplatform/libplatform.h>

namespace interpreter { inline namespace v8_backend {
using namespace v8;

/**
 * related classes are defined in advance
 * */
class i_initializer;
class i_vm;
class i_release_scope;
class i_actuator;
class i_context;
class i_value;
class i_value_holder;
class i_object;
class i_object_field;
class i_object_holder;
class i_str;
class i_class;
class i_class_slot;
class i_class_extract;
class i_parameter;
class i_invoker;
class i_runtime_base;
template<typename t> class i_runtime_container;
template<typename t> class i_invoke_function;
template<typename cls, typename t> class i_invoke_connection;
template<typename t> 
using CopyablePersistent = Persistent<t, CopyablePersistentTraits<t>>;

// attr
enum class i_property_attr: uint8_t {
    none        = None      ,
    read_only   = ReadOnly  ,
    dont_enum   = DontEnum  ,
    dont_delete = DontDelete,
};

/**
 * runtime_release, runtime_base and runtime_container
 * */
class i_runtime_release {
public:
    virtual ~i_runtime_release() = default;
public:
    virtual void on_runtime_release() {
        ;
    }
};

class i_runtime_base {
    __interpreter_friend_class_declare_list__
public:
    virtual ~i_runtime_base() = default;
public:
    inline void force_release() {
        delete this;
    }

    template<typename t> t* cast() {
        if (isa_index_ == typeid(t)) {
            return reinterpret_cast<t*>(isa_);
        }
        return dynamic_cast<t*>(this);
    }

private:
    void* isa_ = nullptr;
    std::type_index isa_index_ = typeid(void);

private:
    Persistent<External> external_;

private:
    template<typename t> static t* cast(Local<Object> object) {
        if (object.IsEmpty()) return nullptr;
        if (object->InternalFieldCount() <= 0) return nullptr;
        auto related = object->GetInternalField(0);
        auto external = Local<External>::Cast(related);
        if (external.IsEmpty()) return nullptr;
        auto base = reinterpret_cast<
            i_runtime_base*>(external->Value());
        if (nullptr == base) return nullptr;
        return base->cast<t>();
    }
};

template<typename t>
class i_runtime_container: public t, public i_runtime_base {
public:
    template<typename ...args_t>
    i_runtime_container(args_t&&... arguments)
        : t(std::forward<args_t>(arguments)...) {
        ;
    }

public:
    template<typename ...args_t> static i_runtime_base* 
        create(args_t&&... arguments) {
        auto data_ptr = new i_runtime_container<t>(
            std::forward<args_t>(arguments)...);
        data_ptr->isa_ = dynamic_cast<t*>(data_ptr);
        data_ptr->isa_index_ = typeid(t);
        return dynamic_cast<i_runtime_base*>(data_ptr);
    }

    static i_runtime_base* create(t** _instance = nullptr) {
        auto data_ptr = new i_runtime_container<t>();
        if (nullptr != _instance) {
            *_instance = dynamic_cast<t*>(data_ptr);
        }
        data_ptr->isa_ = dynamic_cast<t*>(data_ptr);
        data_ptr->isa_index_ = typeid(t);
        return dynamic_cast<i_runtime_base*>(data_ptr);
    }
};


}}