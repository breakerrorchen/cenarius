
#pragma once
#include "i_javascriptcore_base.h"

namespace interpreter { inline namespace javascriptcore_backend {
/**
 * typedarray inner buffer
 * */
class i_typedarr_buffer final {
public:
    size_t size_ = 0, offset_ = 0; void* addr_ = nullptr;

public:
    template<typename t> t at(int index) const {
        t data; 
        void* ptr = (char*)addr_ + index * sizeof(data); 
        memcpy((void*)&data, ptr, sizeof(data));
        return data;
    }

    template<typename t> int size() const {
        return size_ / sizeof(t);
    }
};

    
}}