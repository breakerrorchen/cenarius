
#pragma once
#include "io_center.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_header final {
public:
    std::vector<std::string> k_, v_;
public:
    inline void add(std::string& line) {
        if (!line.empty()) {
            auto position = line.find(": ");
            if (position != line.npos) {
                k_.emplace_back(line.substr(0, position) );
                v_.emplace_back(line.substr(position + 2));
            }
        }
    }
};


}}}