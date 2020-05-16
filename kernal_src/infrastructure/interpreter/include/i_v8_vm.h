
#pragma once
#include "i_v8_base.h"

namespace interpreter { inline namespace v8_backend {
using namespace v8;
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

protected:
    void inner_related_data_reset();
    struct inner_t {
        Isolate::CreateParams create_params_;
    };
    std::unique_ptr<inner_t> inner_;

    // raw isolate ptr
    Isolate* _$_ = nullptr;
};


}}