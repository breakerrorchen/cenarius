
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>
#include "canvas.h"
#include "render_attitude.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class canvas_center {
public:
    virtual ~canvas_center() = default;
public:
    // 获取渲染的硬件参数
    virtual void get_hardware_attitude(render_attitude*)       = 0;

    // 获得和屏幕关联的cavnas，默认会上屏
    virtual std::shared_ptr<canvas> related_window()           = 0;
    // 创建一个和当前屏幕一样大的离屏的cavans
    virtual std::shared_ptr<canvas> create()                   = 0;
    // 指定大小的canvas
    virtual std::shared_ptr<canvas> create(uint32_t, uint32_t) = 0;
    
public:
    // 把屏幕相关的canvas绘制到屏幕上面
    virtual void commit_drawable() = 0;
};


}}}