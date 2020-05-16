
#pragma once
#include "ora_i.h"
#include "ora_node.h"

namespace cenarius { namespace infrastructure { namespace archiver {
class ora_branch_builder;
class ora_branch final {
    friend class ora_branch_builder;
public:
    ora_branch() = default;
    ora_branch(const ora_branch&) = delete;
    ora_branch& operator=(const ora_branch&) = delete;

public:
    ora_node* get_node(const char*); 

public:
    bool merge(std::shared_ptr<ora_branch>);

private:
    std::map<std::string, ora_node> nodes_;
    std::map<std::string, std::shared_ptr<ora_branch>> children_;

private:
    uint8_t* base_buffer_ = nullptr;
};


}}}
