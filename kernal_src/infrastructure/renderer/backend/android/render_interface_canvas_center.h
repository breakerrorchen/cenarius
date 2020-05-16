
#pragma once
#include "render_care.h"
#include "renderer.h"
#include "canvas_center.h"
#include "render_interface_canvas.h"

namespace cenarius { namespace infrastructure { namespace renderer {
// 为了提供统一的跨平台的接口
// 这里通过android的平台去实现跨平台的接口
class render_interface_canvas_center : public canvas_center
    , public std::enable_shared_from_this<render_interface_canvas_center> {
public:
    render_interface_canvas_center();
public:
    //// 获取渲染的硬件参数
    void get_hardware_attitude(render_attitude*)       override;
    // 获得和屏幕关联的cavnas，默认会上屏
    std::shared_ptr<canvas> related_window()           override;
    // 创建一个和当前屏幕一样大的离屏的cavans
    std::shared_ptr<canvas> create()                   override;
    // 指定大小的canvas
    std::shared_ptr<canvas> create(uint32_t, uint32_t) override;

public:
    // 把屏幕相关的canvas绘制到屏幕上面,
    // 并且swapbuffers
    void commit_drawable() override;

public:
    // 底层渲染
    std::shared_ptr<renderer_combined> renderer_combined_;
    // 上屏幕的Canvas
    std::shared_ptr<render_interface_canvas> window_canvas_;

private:
    // 启动后立刻获取系统默认参数
    render_attitude render_attitude_;
};


}}}