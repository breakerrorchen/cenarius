
#pragma once
#include "common/base_header_inct.h"
#include "constant.h"

namespace cenarius { namespace kernal { namespace bestead {
class thread_userfor final {
public:
    // get the globally unique thread id
    static uint32_t thread_id();

    // Used by the business party to ensure the correctness of the thread
    // Used to determine if a thread is needed
    static bool check_usefor(thread_usefor_constant);

    // Generally used to mark the specific 
    // use of the thread when the thread is started
    static void mark(thread_usefor_constant);
};


}}}