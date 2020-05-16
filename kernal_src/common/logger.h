
#pragma once
#include "base_header_inct.h"

#define __show_debug_log__
#define __log_error(...)                                        \
    ::cenarius::common_base::logger::log_error(__VA_ARGS__);
#ifdef  __show_debug_log__
#define __log(...)                                              \
    ::cenarius::common_base::logger::log(__VA_ARGS__);
#else
#define __log(...)
#endif//__show_debug_log__

namespace cenarius { namespace common_base { 
class logger final {
public:
    // Log Error printing function
    // Each platform is implemented separately
    static void log_error(const char* format, ...);

    // Log printing function
    // Each platform is implemented separately
    static void log(const char* format, ...);
};


}}
