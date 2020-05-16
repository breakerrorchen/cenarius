
#pragma once
#include "render_care.h"
#include "renderer.h"
#include "canvas.h"
#include "render_interface_canvas_2d.h"
#include "render_interface_canvas_3d.h"

namespace cenarius { namespace infrastructure { namespace renderer {
// 为了提供统一的跨平台的接口
// 这里通过android的平台去实现跨平台的接口
class render_interface_canvas_center;
class render_interface_canvas : public canvas {
public:
    void make_current() override;
    std::shared_ptr<canvas_render_2d> render_2d() override;
    std::shared_ptr<canvas_render_3d> render_3d() override;
    uint32_t get_w() override;
    uint32_t get_h() override;
    bool is_window_related() override;
    bool resize(uint32_t, uint32_t) override;
    std::shared_ptr<canvas_snapshot> snapshot() override;

public:
    // 把当前的canvas粘贴到屏幕上面
    bool bitblt_on_window();

public:
    uint32_t width_ = 0, height_ = 0;
    std::shared_ptr<render_interface_canvas_2d> _2d;
    std::shared_ptr<render_interface_canvas_3d> _3d;

    // 和屏幕绑定的canvas
    bool is_related_window_ = false;

public:
    std::weak_ptr<render_interface_canvas_center> canvas_center_;
};


}}}