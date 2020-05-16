
#include "url_paramers.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

url_paramers::url_paramers(const char* url) {
    url_ = url;
    std::string::size_type m = url_.find("?");
    has_paramer_ = (url_.npos != m);
}

bool url_paramers::add(const char* k, const char* v) {
    if (!k || !v) return false;
    if (!has_paramer_) {
        url_ += "?"; has_paramer_ = true;
    } else {
        url_ += "&"; 
    }
    url_ += k; url_ += "="; url_ += v;
    return true;
}

std::string url_paramers::get() {
    return url_;
}