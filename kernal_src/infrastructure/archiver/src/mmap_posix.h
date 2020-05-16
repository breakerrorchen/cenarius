
#if defined(__APPLE__) || defined(__ANDROID__) \
    || defined(ANDROID) || defined(__linux__) 
#pragma once
#include "mmap.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

namespace cenarius { namespace infrastructure { namespace archiver {
class mmap_posix final: public mem_map {
public:
    mmap_posix();
    virtual ~mmap_posix();

public:
    bool open(const char*)   override;
    bool close()             override;
    bool is_available()      override;
    bool get_size(uint32_t*) override;
    bool get_addr(uint8_t**) override;

private:
    int fd_ = -1;
    uint32_t size_ = 0;
    uint8_t* addr_ = nullptr;
};
using mmap_inner_impl_t = mmap_posix;


}}}
#endif//__use_posix_mmap__