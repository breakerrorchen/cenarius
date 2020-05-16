
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace common_base {
class runtime_base {
public:
    virtual ~runtime_base() = default;
public:
    template<typename cls> inline cls* cast_as() {
        return dynamic_cast<cls*>(this);
    }
};

template<typename cls>
class runtime_base_container final: public cls, public runtime_base {
public:
    template<typename ...args_t>
    static std::shared_ptr<runtime_base> create(args_t&&... arguments) {
        auto ptr = std::make_shared<runtime_base_container<cls>>(
            std::forward<args_t>(arguments)...);
        return std::dynamic_pointer_cast<runtime_base>(ptr);
    }

public:
    template<typename ...args_t>
    runtime_base_container(args_t&&... arguments)
        : cls(std::forward<args_t>(arguments)...) {
        ;
    }
};


}}