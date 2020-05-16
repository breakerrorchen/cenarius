
#pragma once
#include "mmap.h"
#include "ora_i.h"
#include "ora_branch.h"

namespace cenarius { namespace infrastructure { namespace archiver {
class ora_center;
class ora_bundle final {
    friend class ora_center;
public:
    ora_bundle() = default;
    ora_bundle(const ora_bundle&) = delete;
    ora_bundle(ora_bundle&&) = delete;

public:
    bool load(const char*);

private:
    std::shared_ptr<mem_map>    memmap_;
    std::shared_ptr<ora_branch> branch_;

private:
    uint16_t version_[3] = {0, 0, 0};
};


}}}