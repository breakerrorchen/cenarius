
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * i_vm decalre
 * represents the isolation of runtime data.
 * representing an interpreter virtual machine instance.
 * */
class i_vm final {
    __interpreter_friend_class_declare_list__
public:
    virtual ~i_vm();
    i_vm();
    i_vm(const i_vm&) = delete;
    i_vm& operator=(const i_vm&) = delete;
    i_vm(i_vm&&);
    i_vm& operator=(i_vm&&);

public:
    void gc();

protected:
    // a group that associates JavaScript contexts with one another. 
    // contexts in the same group may share and exchange JavaScript objects
    JSContextGroupRef _$_ = nullptr;
};
    
}}