
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cmath>

namespace cenarius { namespace infrastructure { namespace css_pattern {

// // style
// enum class css_font_style: uint32_t {
//     _normal = 0x0001, _italic= 0x0002, _oblique= 0x0004,
// };

// // variant
// enum class css_font_variant: uint32_t {
//     _normal = 0x0008, _small_caps = 0x0010,
// };

// // weight
// enum class css_font_weigth: uint32_t {
//     _lighter        = 0x0020, 
//     _thin           = 0x0040, 
//     _extra_light    = 0x0080,
//     _light          = 0x0100, 
//     _normal         = 0x0200,  
//     _medium         = 0x0400, 
//     _semi_bold      = 0x0800,
//     _bold           = 0x1000,
//     _bolder         = 0x2000,
//     _extre_bold     = 0x4000,
//     _black          = 0x8000,
// };

// desc
struct css_font_desc final { float size_ = 12.f; std::string name_; };

// parser
// 1.2pt "Fira Sans", sans-serif
// there are restrictions on font recognition, 
// font thickness is not supported, only px / pt is supported, 
// only the first one is used for multiple font names.
// No font fallback mechanism
class css_parser_font final {
public:
    static bool parse(const std::string&, css_font_desc&);
};


}}}