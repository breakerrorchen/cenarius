
#pragma once
#include <assert.h>
#include <stdio.h>

namespace cenarius { namespace infrastructure { namespace crypto {
    uint32_t crc32(uint32_t, const void*, int);
}}}