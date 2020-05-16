
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace common_base {
template<class cls> class move_trait final {
public:
    move_trait() = default;
    move_trait(move_trait&& that) {
        related_data_ = std::move(that.related_data_);
    }

    move_trait(const move_trait& that) {
        auto v = const_cast<move_trait*>(&that);
        related_data_ = std::move(v->related_data_);
    }
        
    move_trait(cls& related_data) {
        related_data_ = std::move(related_data);
    }

    move_trait& operator=(const move_trait& that) {
        if (this == &that) return *this;
        auto v = const_cast<move_trait*>(&that);
        related_data_ = std::move(v->related_data_);
        return *this;
    }

    move_trait& operator=(move_trait&& that) {
        related_data_ = std::move(that.related_data);
        return *this;
    }
    
public:
    cls related_data_;
};


}}