
#pragma once
#include "ora_i.h"

namespace cenarius { namespace infrastructure { namespace archiver {
class ora_branch_builder;
class ora_node {
    friend class ora_branch_builder;
public:
    ora_node() = default;
    ora_node(const ora_node&);
    ora_node(ora_node&&);
    ora_node& operator=(const ora_node&);
    ora_node& operator=(ora_node&&);
    virtual ~ora_node() = default;

public:
    inline uint8_t* get_buffer() const {
        return buffer_;
    }

    inline uint32_t get_size() const {
        return size_;
    }

private:
    uint8_t* buffer_ = nullptr; uint32_t size_ = 0;
};


}}}