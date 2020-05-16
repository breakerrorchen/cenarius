
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>

namespace cenarius { namespace infrastructure { namespace css_pattern {
class css_parser_color final {
public:
    // rgba
    static bool parse(const std::string&, uint32_t&);
    // string => rgba
    static bool parse(const std::string&, 
        uint8_t&, uint8_t&, uint8_t&, uint8_t&);
};


}}} // end > cenarius.infrastructure.css_pattern