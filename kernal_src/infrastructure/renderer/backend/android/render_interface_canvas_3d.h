
#pragma once
#include "render_care.h"
#include "renderer.h"
#include "render_canvas_3d.h"
#include "canvas_render_3d.h"

namespace cenarius { namespace infrastructure { namespace renderer {
// 为了提供统一的跨平台的接口
// 这里通过android的平台去实现跨平台的接口
class render_interface_canvas_3d : public canvas_render_3d {
public:
    // 内部实现
    std::shared_ptr<render_canvas_3d> impl_3d_;
};


}}}