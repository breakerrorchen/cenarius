
#pragma once
#include <memory>

namespace cenarius { namespace infrastructure { namespace archiver {
class mem_map : public std::enable_shared_from_this<mem_map> {
public:
    mem_map() = default;
    virtual ~mem_map() = default;

public:
    virtual bool open(const char*)   = 0;
    virtual bool close()             = 0;
    virtual bool is_available()      = 0;
    virtual bool get_size(uint32_t*) = 0;
    virtual bool get_addr(uint8_t**) = 0;

public:
    static std::shared_ptr<mem_map> build();
};


}}}