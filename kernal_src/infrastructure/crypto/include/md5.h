
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>

namespace cenarius { namespace infrastructure { namespace crypto {
    std::string md5(const char*  str);
	std::string md5(std::string& str);
}}}