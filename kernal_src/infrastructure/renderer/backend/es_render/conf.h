
#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#if defined(__ANDROID__) || defined(ANDROID)
#include "backend/android/render_care.h"

#elif defined(__APPLE__)
#include <TargetConditionals.h>
#if TARGET_OS_MAC
#error > rendeer not support now!!
#elif TARGET_OS_IPHONE
#elif TARGET_IPHONE_SIMULATOR
#else
#error > rendeer not support now!!
#endif

#elif defined(WIN32) || defined(_WIN32)
#error > rendeer not support now!!
#elif defined(__linux__)
#error > rendeer not support now!!
#else
#error > rendeer not support now!!
#endif
