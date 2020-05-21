
#pragma once
#include "conf.h"

namespace cenarius { namespace infrastructure { namespace renderer {
union shader_uniform_value {
    int   i_16_[16];
    float f_16_[16];
    bool  b_16_[16];
    int   sampler_ ; // sampler2D or samplerCube
};

class shader_uniform final {
public:
    inline bool     is_array() const { return size_ > 0; }
    inline uint32_t size()     const { return size_;     }
public:
    shader_uniform_value value_;
    std::string name_;
    uint32_t location_index_ = 0, type_ = 0, size_ = 0;  
};


}}}