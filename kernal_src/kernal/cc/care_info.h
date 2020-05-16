
#pragma once
#include "common/base_header_inct.h"

namespace cenarius { namespace kernal { namespace cc {
/**
 * controller线程中使用
 * 用来在启动的时候从底层传递参数给控制器线程的启动参数
 * */
class care_info {
public:
    virtual ~care_info() = default;

public:
    uint32_t screen_w_ = 0;         // 屏幕的宽度
    uint32_t screen_h_ = 0;         // 屏幕的高度
    uint32_t window_w_ = 0;         // 当前窗口宽度
    uint32_t window_h_ = 0;         // 当前窗口高度
    float pixel_ratio_ = 1;         // 设备像素比

public:
    uint32_t    system_type_;       // 系统类型 0=>未知，1=>android 2=> iOS
    std::string device_brand_;      // 设备品牌
    std::string device_model_;      // 设备型号
    std::string workspace_;         // 渲染引擎的工作路径
    std::string system_temp_;       // 系统的cache目录
};


}}}