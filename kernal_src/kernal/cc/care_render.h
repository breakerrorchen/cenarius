
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/renderer/include/canvas_center.h"

namespace cenarius { namespace kernal { namespace cc {
using namespace infrastructure;
using namespace renderer;
class care_render {
public:
    virtual ~care_render() = default;
public:
    /**
     * 渲染服务启动的时候调用
     * */
    virtual void on_start() = 0;

    /**
     * 上屏前
     * */
    virtual void pre_commit_drawable() = 0;

    /**
     * 上屏
     * */
    virtual void commit_drawable() = 0;

    /**
     * 上屏后
     * */
    virtual void after_commit_drawable() = 0;

    /**
     * 获取Canvas Center
     * */
    virtual std::shared_ptr<canvas_center> get_canvas_center() = 0;

    /**
     * 渲染服务退出的时候调用
     * */
    virtual void on_finish() = 0;
};


}}}