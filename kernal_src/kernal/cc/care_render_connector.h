
#pragma once
#include "common/base_header_inct.h"
#include "care_render.h"

namespace cenarius { namespace kernal { namespace cc {
class care_render_connector final {
public:
    /**
     * 控制器线程和渲染线程用来数据同步的关联器
     * 关联器的数据只能在渲染线程中操作
     * 
     * ！！！！
     * 这里这么设计主要为了线程的并行性，
     * 这个connector对象有一个特殊要求，这个对象只能在
     * 渲染线程中操作，但是控制器线程需要持有这些对象在
     * 必要的时机推送到控制器线程进行操作。
     * 
     * 所以在渲染器线程和控制器线程线程共同持有这个对象
     * 渲染器线程在启动后予以赋值，后续控制器的就可以通过
     * 这个对象发送到渲染器线程中就可以操作了。
     * */
    std::shared_ptr<care_render  > render_;
    std::shared_ptr<canvas_center> canvas_center_;
};


}}}