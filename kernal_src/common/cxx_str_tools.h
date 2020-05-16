
#pragma once
#include "base_header_inct.h"

namespace cenarius { namespace common_base { namespace str_tools {
void trim                (std::string&);
void trim_copy           (const std::string&, std::string&);
void r_trim              (std::string&);
void r_trim_copy         (const std::string&, std::string&);
void l_trim              (std::string&);
void l_trim_copy         (const std::string&, std::string&);
void to_lower            (std::string&);
void to_lower_copy       (const std::string&, std::string&);
void to_upper            (std::string&);
void to_upper_copy       (const std::string&, std::string&);
bool equal               (const std::string&, const std::string&);
bool equal               (const std::string&, const char*);
bool equal_no_case       (const std::string&, const std::string&);
bool equal_no_case       (const std::string&, const char*);
bool start_with          (const std::string&, const std::string&);
bool start_with          (const std::string&, const char*);
bool start_with_no_case  (const std::string&, const std::string&);
bool start_with_no_case  (const std::string&, const char*);
bool start_with          (const std::string&, const char);
bool end_with            (const std::string&, const std::string&);
bool end_with            (const std::string&, const char*);
bool end_with_no_case    (const std::string&, const std::string&);
bool end_with_no_case    (const std::string&, const char*);
bool end_with            (const std::string&, const char);


}}}