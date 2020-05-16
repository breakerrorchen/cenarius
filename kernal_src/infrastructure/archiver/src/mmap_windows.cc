
#if defined(WIN32) || defined(_WIN32)
#include "mmap_windows.h"
using namespace cenarius;
using namespace infrastructure;
using namespace archiver;

mmap_windows::mmap_windows() {
    ;
}
mmap_windows::~mmap_windows() { close(); }

bool mmap_windows::open(const char* file) {
    if (INVALID_HANDLE_VALUE == h_file_ || !file) {
        return false;
    }

    h_file_ = ::CreateFileA(
        file, GENERIC_READ, FILE_SHARE_READ,
        nullptr, OPEN_EXISTING, 
        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (INVALID_HANDLE_VALUE == h_file_) {
        return false;
    }
    size_ = ::GetFileSize(h_file_, nullptr);
    
    h_mapping_ = ::CreateFileMapping(h_file_, 
        nullptr, PAGE_READONLY, 0, 0, nullptr);
    if (INVALID_HANDLE_VALUE == h_mapping_) {
        ::CloseHandle(h_file_);
        return false;
    }

    addr_ = (uint8_t*)::MapViewOfFile(
        h_mapping_, FILE_MAP_READ, 0, 0, 0);
    return true;
}

bool mmap_windows::close() {
    if (addr_) {
        ::UnmapViewOfFile(addr_);
        addr_ = nullptr;
    }

    if (INVALID_HANDLE_VALUE != h_mapping_) {
        ::CloseHandle(h_mapping_);
        h_mapping_ = INVALID_HANDLE_VALUE;
    }

    if (INVALID_HANDLE_VALUE != h_file_) {
        ::CloseHandle(h_file_);
        h_file_ = INVALID_HANDLE_VALUE;
    }
    return true;
}

bool mmap_windows::is_available() {
    return INVALID_HANDLE_VALUE != h_mapping_;
}

bool mmap_windows::get_size(uint32_t* size) {
    if (nullptr != size) {
        *size = size_;
    } 
    return true;
}

bool mmap_windows::get_addr(uint8_t** addr) {
    if (nullptr != addr) {
        *addr = addr_;
    }
    return true;
}
#endif