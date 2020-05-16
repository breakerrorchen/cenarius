
#pragma once
#include "common/base_header_inct.h"
#include "kernal/cc/care_communicate.h"

namespace cenarius { namespace platform {
using namespace kernal;
using namespace cc;
/**
 * 为上层提供可以和app通讯的接口
 * android这块主要通过JNI反射调用Java的代码
 * */
class care_communicate_i final : public care_communicate {
public:
    
};


}}