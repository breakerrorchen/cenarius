
#if defined(WIN32) || defined(_WIN32)
#pragma once
#include "mmap.h"
#include <windows.h>

namespace cenarius { namespace infrastructure { namespace archiver {
class mmap_windows final: public mem_map {
public:
    mmap_windows();
    virtual ~mmap_windows();

public:
    bool open(const char*)   override;
    bool close()             override;
    bool is_available()      override;
    bool get_size(uint32_t*) override;
    bool get_addr(uint8_t**) override;

private:
    HANDLE h_file_    = INVALID_HANDLE_VALUE;
    HANDLE h_mapping_ = INVALID_HANDLE_VALUE;
    uint32_t size_    = 0;
    uint8_t* addr_    = nullptr;
};
using mmap_inner_impl_t = mmap_windows;

}}
#endif