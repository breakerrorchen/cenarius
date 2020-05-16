
#include "css_parser_font.h"
using namespace cenarius;
using namespace infrastructure;
using namespace css_pattern;

bool cenarius::infrastructure::css_pattern::css_parser_font::parse(
    const std::string& str, css_font_desc& ret) {
    float size = 0; char name[128] = { 0 }; char ptx = 0;
	char* start = const_cast<char*>(str.c_str());
	while(*start != '\0' && !isdigit(*start)){ start++; }
	sscanf(start, "%fp%1[tx]%*[\"' ]%63[^\"']", &size, &ptx, name);
    if( ptx == 't' ) { size = std::ceilf(size* 4.0 / 3.0); }
    ret.name_ = name; ret.size_ = size;
    return true;
}