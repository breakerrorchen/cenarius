
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>
#include "canvas_render_2d.h"
#include "canvas_render_3d.h"
#include "canvas_snapshot.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class canvas {
public:
    virtual ~canvas() = default;

public:
    // 设置当前渲染
    virtual void make_current() = 0;
    
    // 获取不同的渲染上下文
    // 这里的操作会自动缓存到canvas内部，
    // 每个cavans的渲染上下文只能是一种
    virtual std::shared_ptr<canvas_render_2d> render_2d() = 0;
    virtual std::shared_ptr<canvas_render_3d> render_3d() = 0;

public:
    virtual std::shared_ptr<canvas_snapshot> snapshot() = 0;

public:
    // 获取画布的尺寸
    virtual uint32_t get_w() = 0;
    virtual uint32_t get_h() = 0;

public:
    // 判断当前画布是不是会作为上屏的画布
    virtual bool is_window_related() = 0;

public:
    // 修改画布的大小
    virtual bool resize(uint32_t, uint32_t) = 0;
};


}}}