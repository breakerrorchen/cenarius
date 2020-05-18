
#pragma once
#include "conf.h"
#include "shader_attrib.h"
#include "shader_uniform.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class shader_reflection final {
public:
    bool is_success_ = false;
    std::string program_info_;
    std::vector<shader_attrib > attribs_;
    std::vector<shader_uniform> uniforms_;
    std::vector<shader_uniform> active_uniforms_;
public:
    inline void reset() {
        is_success_     = false; 
        program_info_   = "";
        attribs_        .clear(); 
        uniforms_       .clear(); 
        active_uniforms_.clear();
    }

public:
    inline shader_uniform* find_uniform(uint32_t _id) {
        for (auto& item: uniforms_) {
            if (item.location_index_ == _id) {
                return &item;
            }
        }
        return nullptr;
    }

    inline int find_uniform_index(uint32_t _id) {
        for (size_t i = 0; i < uniforms_.size(); ++i) {
            if (uniforms_[i].location_index_ == _id) {
                return (int)i;
            }
        }
        return -1;
    }
};


}}}