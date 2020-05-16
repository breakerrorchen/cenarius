
#include "env.h"
#define __cenarius_log_tag__ "cenarius_core"

// 为了跨平台需要
// 使用系统的日志接口来完成上层日志声明函数的实现
void cenarius::common_base::logger::log_error(const char* format, ...) {
    va_list ap; va_start(ap, format);
    __android_log_vprint(
        ANDROID_LOG_ERROR, __cenarius_log_tag__, format, ap);
    va_end(ap);
}

void cenarius::common_base::logger::log(const char* format, ...) {
    va_list ap; va_start(ap, format);
    __android_log_vprint(
        ANDROID_LOG_INFO, __cenarius_log_tag__, format, ap);
    va_end(ap);
}