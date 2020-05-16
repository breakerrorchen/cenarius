
#include "mmap.h"
#include "mmap_posix.h"
#include "mmap_windows.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;
std::shared_ptr<mem_map> mem_map::build() {
    return std::dynamic_pointer_cast<mem_map>(
        std::make_shared<mmap_inner_impl_t>());
}