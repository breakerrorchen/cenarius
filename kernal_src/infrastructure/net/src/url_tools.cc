
#include "url_tools.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

inline unsigned char to_hex(unsigned char x) { 
    return  x > 9 ? x + 55 : x + 48; 
}
 
inline unsigned char from_hex(unsigned char x) { 
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    else assert(0);
    return y;
}

std::string url_tools::encode(const std::string& str) {
    std::string str_temp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        auto c = str[i];
        if (c >= 33 && c <= 126)
            str_temp += c;
        else if (c == ' ')
            str_temp += "+";
        else {
            str_temp += '%';
            str_temp += to_hex((unsigned char)c >> 4);
            str_temp += to_hex((unsigned char)c % 16);
        }
    }
    return str_temp;
}

std::string url_tools::decode(const std::string& str) {
    std::string str_temp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++) {
        if (str[i] == '+') str_temp += ' ';
        else if (str[i] == '%') {
            assert(i + 2 < length);
            unsigned char high = from_hex((unsigned char)str[++i]);
            unsigned char low  = from_hex((unsigned char)str[++i]);
            str_temp += high*16 + low;
        }
        else str_temp += str[i];
    }
    return str_temp;
}