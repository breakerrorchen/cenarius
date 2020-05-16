
#define __MD5_WRAPPER__
#include "md5.h"
#include "md5_i.h"

std::string cenarius::infrastructure::crypto::md5(const char* str) {
	std::string cxx_str(str);
	return md5(cxx_str);
}

std::string cenarius::infrastructure::crypto::md5(std::string& str) {
	return MD5(str).toStr();
}