
#include "cxx_str_tools.h"

void cenarius::common_base::str_tools::trim(std::string& str) {
    auto len = str.length(); size_t l_offset = 0, r_offset = len - 1;
    for (; l_offset < len; ++l_offset) {
        if (' ' != str[l_offset]) {
            break;
        }
    }

    for (; r_offset > l_offset; --r_offset) {
        if (' ' != str[r_offset]) {
            break;
        }
    }

    if (r_offset > l_offset && (l_offset > 0 || r_offset < len - 1)) {
        std::string _str;
        _str.append(
            str.c_str() + l_offset, r_offset - l_offset + 1);
        str = std::move(_str);
    }
}

void cenarius::common_base::str_tools::trim_copy(
    const std::string& str, std::string& ret) {
    auto _copy = str;
    cenarius::common_base::str_tools::trim(_copy);
    ret = std::move(_copy);
}

void cenarius::common_base::str_tools::r_trim(std::string& str) {
    std::string _str;
    auto len = str.length(); size_t offset = len - 1;
    for (; offset >= 0; --offset) {
        if (' ' != str[offset]) {
            break;
        }
    }
    if (offset > 0) {
        _str.append(str.c_str(), len - offset);
    }
    str = std::move(_str);
}

void cenarius::common_base::str_tools::r_trim_copy(
    const std::string& str, std::string& ret) {
    auto _copy = str;
    cenarius::common_base::str_tools::r_trim(_copy);
    ret = std::move(_copy);
}

void cenarius::common_base::str_tools::l_trim(std::string& str) {
    std::string _str;
    auto len = str.length(); size_t offset = 0;
    for (; offset < len; ++offset) {
        if (' ' != str[offset]) {
            break;
        }
    }
    if (len > offset) {
        _str.append(str.c_str() + offset, len - offset);
    }
    str = std::move(_str);
}

void cenarius::common_base::str_tools::l_trim_copy(
    const std::string& str, std::string& ret) {
    auto _copy = str;
    cenarius::common_base::str_tools::l_trim(_copy);
    ret = std::move(_copy);
}

void cenarius::common_base::str_tools::to_lower(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void cenarius::common_base::str_tools::to_lower_copy(
    const std::string& str, std::string& ret) {
    auto _copy = str;
    cenarius::common_base::str_tools::to_lower(_copy);
    ret = std::move(_copy);
}

void cenarius::common_base::str_tools::to_upper(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void cenarius::common_base::str_tools::to_upper_copy(
    const std::string& str, std::string& ret) {
    auto _copy = str;
    cenarius::common_base::str_tools::to_upper(_copy);
    ret = std::move(_copy);
}

bool cenarius::common_base::str_tools::equal(
    const std::string& l, const std::string& r) {
    return l == r;
}

bool cenarius::common_base::str_tools::equal(
    const std::string& l, const char* r) {
    if (nullptr == r) return false;
    int l_len = l.length(), r_len = strlen(r);
    if (l_len != r_len) return false;
    for (int i = 0; i < l_len; ++i) {
        if (l[i] != r[i]) return false;
    }
    return true;
}

bool cenarius::common_base::str_tools::equal_no_case(
    const std::string& l, const std::string& r) {
    int l_len = l.length(), r_len = r.length();
    for (int i = 0; i < l_len; ++i) {
        auto _0 = l[i]; auto _1 = r[i];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    }
    return true;
}

bool cenarius::common_base::str_tools::equal_no_case(
    const std::string& l, const char* r) {
    if (nullptr == r) return false;
    int l_len = l.length(), r_len = strlen(r);
    if (l_len != r_len) return false;
    for (int i = 0; i < l_len; ++i) {
        auto _0 = l[i]; auto _1 = r[i];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    }
    return true;
}

bool cenarius::common_base::str_tools::start_with(
    const std::string& str, const std::string& prefix) {
    return std::mismatch(prefix.begin(), 
        prefix.end(), str.begin()).first == prefix.end();
}

bool cenarius::common_base::str_tools::start_with(
    const std::string& str, const char* prefix) {
    if (nullptr == prefix) return false;
    int str_len = str.length(), prefix_len = strlen(prefix);
    if (prefix_len > str_len) return false;
    for (int i = 0; i < prefix_len; ++i) {
        if (str[i] != prefix[i]) return false;
    }
    return true;
}

bool cenarius::common_base::str_tools::start_with_no_case(
    const std::string& str, const std::string& prefix) {
    int str_len = str.length(), prefix_len = prefix.length();
    if (prefix_len > str_len) return false;
    for (int i = 0; i < prefix_len; ++i) {
        auto _0 = str[i]; auto _1 = prefix[i];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    } 
    return true;
}

bool cenarius::common_base::str_tools::start_with_no_case(
    const std::string& str, const char* prefix) {
    if (nullptr == prefix) return false;
    int str_len = str.length(), prefix_len = strlen(prefix);
    if (prefix_len > str_len) return false;
    for (int i = 0; i < prefix_len; ++i) {
        auto _0 = str[i]; auto _1 = prefix[i];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    } 
    return true;
}

bool cenarius::common_base::str_tools::start_with(
    const std::string& str, const char ch) {
    return !str.empty() && str.front() == ch;
}

bool cenarius::common_base::str_tools::end_with(
    const std::string& str, const std::string& subffix) {
    return std::mismatch(subffix.rbegin(), 
        subffix.rend(), str.rbegin()).first == subffix.rend();
}

bool cenarius::common_base::str_tools::end_with(
    const std::string& str, const char* subffix) {
    if (nullptr == subffix) return false;
    int str_len = str.length(), suffix_len = strlen(subffix);
    if (suffix_len > str_len) return false;
    for (int i = 0; i < suffix_len; ++i) {
        if (str[str_len - i - 1] 
                != subffix[suffix_len - i - 1]) {
            return false;
        }
    }
    return true;
}

bool cenarius::common_base::str_tools::end_with_no_case(
    const std::string& str, const std::string& subffix) {
    int str_len = str.length(), suffix_len = subffix.length();
    if (suffix_len > str_len) return false;
    for (int i = 0; i < suffix_len; ++i) {
        auto _0 = str[str_len - i - 1];
        auto _1 = subffix[suffix_len - i - 1];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    }
    return true;
}

bool cenarius::common_base::str_tools::end_with_no_case(
    const std::string& str, const char* subffix) {
    if (nullptr == subffix) return false;
    int str_len = str.length(), suffix_len = strlen(subffix);
    if (suffix_len > str_len) return false;
    for (int i = 0; i < suffix_len; ++i) {
        auto _0 = str[str_len - i - 1];
        auto _1 = subffix[suffix_len - i - 1];
        if (_0 == _1) continue;
        if (std::islower(_0)) { _0 -= 32; }
        if (std::islower(_0)) { _1 -= 32; }
        if (_0 != _1) {
            return false;
        }
    }
    return false;
}

bool cenarius::common_base::str_tools::end_with(
    const std::string& str, const char ch) {
    return !str.empty() && str.back() == ch;
}