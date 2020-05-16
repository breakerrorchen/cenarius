// Copyright 2019 The Cenarius Authors. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the LICENSE file.
#pragma once

#include <assert.h>
#include <stdarg.h>
#include <typeindex>
#include <iostream>
#include <fstream>
#include <streambuf> 
#include <string>
#include <sstream>
#include <cctype>
#include <iterator>
#include <limits>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <memory>
#include <functional>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <future>
#include <algorithm>
#include <condition_variable>
#include <regex>

// log
#include "common/logger.h"

#if defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define __cenarius_build_for_os_ios_simulator__     1
#define __cenarius_build_for_posix__                1
#elif TARGET_OS_IPHONE
#define __cenarius_build_for_os_ios__               1
#define __cenarius_build_for_posix__                1
#elif TARGET_OS_MAC
#define __cenarius_build_for_os_osx__               1
#define __cenarius_build_for_posix__                1
#endif
#endif

#if defined(WIN32) || defined(_WIN32)
#define __cenarius_build_for_os_windows__           1
#endif

#if defined(__ANDROID__) || defined(ANDROID)
#define __cenarius_build_for_os_android__           1
#define __cenarius_build_for_posix__                1
#endif

#if defined(__linux__)
#define __cenarius_build_for_os_linux__             1
#define __cenarius_build_for_posix__                1
#endif

#if    defined(__LP64__)                            \
    || defined(__64BIT__)                           \
    || defined(_LP64)                               \
    || defined(__x86_64)                            \
    || defined(__x86_64__)                          \
    || defined(__amd64)                             \
    || defined(__amd64__)                           \
    || defined(__arm64)                             \
    || defined(__arm64__)                           \
    || defined(__sparc64__)                         \
    || defined(__PPC64__)                           \
    || defined(__ppc64__)                           \
    || defined(__powerpc64__)                       \
    || defined(_M_X64)                              \
    || defined(_M_AMD64)                            \
    || defined(_M_IA64)                             \
    || (defined(__WORDSIZE) && (__WORDSIZE == 64))  \
    || defined(TCC_TARGET_X86_64)
#define __cenarius_64bit_cpu__                      1
#else
#define __cenarius_32bit_cpu__                      1
#endif


#define __sptr                      std::shared_ptr
#define __wptr                      std::weak_ptr
#define __uptr                      std::unique_ptr
#define __instance                  std::make_shared
#define __if_break(op)              if (!!(op)) break;
#define __if_continue(op)           if (!!(op)) continue;
#define __if_return(op, ret)        if (!!(op)) return ret;
#define __if_return_void(op)        if (!!(op)) return;
#define __declare_name_2(l, r)      l##r
#define __declare_name_1(l, r)      __declare_name_2(l, r)
#define __declare_name(l)           __declare_name_1(l, __LINE__)
#define __declare_name_             __declare_name(_)
#define __scope_start               {
#define __scope_end                 } while(0); 


namespace cenarius { namespace common_base {
    class base_defer_inner final {
    public:
        virtual ~base_defer_inner() {
            if (defer_func_) {
            	defer_func_();
            }
        }
    public:
        std::function<void()> defer_func_;
    };
}}

#define __defer ::cenarius::common_base::base_defer_inner   \
    __declare_name_; __declare_name_.defer_func_ = [&]()

/**
 * eg.
 * __defer {
 *      do something ...
 * };
 **/

// version
// 
#define __cenarius_version__ cenarius_version_0_0_0_
