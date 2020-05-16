
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_actuator decalre and implement
 * interpreter for executing code, vm life cycle
 * must be valid during the valid period of the actuator
 * */
class i_actuator final {
    __interpreter_friend_class_declare_list__
public:
    virtual ~i_actuator();
    i_actuator(const i_vm&);
    i_actuator(const i_vm&, const i_class&);
    i_actuator(const i_actuator&);
    i_actuator(i_actuator&&);
    i_actuator& operator=(const i_actuator&);
    i_actuator& operator=(i_actuator&&);

public:
    // get related context
    i_context get_context() const;

protected:
    // a JavaScript execution context. 
    // holds the global object and other execution state
    JSGlobalContextRef _$_ = nullptr;
};

  
}}