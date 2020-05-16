
#if defined(__APPLE__) || defined(__ANDROID__) \
    || defined(ANDROID) || defined(__linux__) 
#include "mmap_posix.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

mmap_posix::mmap_posix() {
    ;
}

mmap_posix::~mmap_posix() { close(); }

bool mmap_posix::open(const char* file) {
    if (-1 != fd_ || !file) {
        return false;
    }
    fd_ = ::open(file, O_RDONLY);
    if (-1 == fd_) { return false; }

    struct stat _s;
    if (-1 == ::fstat(fd_, &_s)) {
        ::close(fd_); fd_ = -1;
        return false;
    }
    size_ = (uint32_t)_s.st_size;
    addr_ = (uint8_t*)::mmap(nullptr, 
        size_, PROT_READ, MAP_PRIVATE, fd_, 0);
    if (nullptr == addr_) {
        size_ = 0; addr_ = nullptr;
        ::close(fd_); fd_ = -1;
        return false;
    }
    return true;
}

bool mmap_posix::close() {
    if (nullptr != addr_) {
        ::munmap(addr_, size_);
    }
    if (-1 != fd_) { ::close(fd_); }
    size_ = 0; addr_ = nullptr; fd_ = -1;
    return true;
}

bool mmap_posix::is_available() {
    return size_ > 0 && addr_;
}

bool mmap_posix::get_size(uint32_t* size) {
    if (nullptr != size) {
        *size = size_;
    }
    return true;
}

bool mmap_posix::get_addr(uint8_t** addr) {
    if (nullptr != addr) {
        *addr = addr_;
    }
    return true;
}
#endif