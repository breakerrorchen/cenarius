
#pragma once
#include "remote_container.h"
using namespace cenarius;
using namespace kernal;
using namespace bestead;

remote_container::~remote_container() {
    remote_container::clear();
}

void remote_container::clear() {
    remote_base* current = remote_base_.next_;
    while (current) {
        auto next = current->next_;
        current->force_release();
        current = next;
    }
}
