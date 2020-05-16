
#pragma once
#include "ora_branch.h"

namespace cenarius { namespace infrastructure { namespace archiver {
class ora_branch_builder final {
private:
    static std::shared_ptr<ora_branch> 
        __build(uint8_t*, uint8_t*, uint32_t, uint32_t*);
public:
    static std::shared_ptr<ora_branch> build(void*, uint32_t);
};


}}}
