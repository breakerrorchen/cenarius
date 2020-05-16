
#pragma once
#include "render_care.h"
#include "renderer.h"
#include "render_canvas_2d.h"
#include "canvas_render_2d.h"

namespace cenarius { namespace infrastructure { namespace renderer {
// 为了提供统一的跨平台的接口
// 这里通过android的平台去实现跨平台的接口
class render_interface_canvas_2d : public canvas_render_2d {
public:
	void test() override;

public:
    // 获取用以2d渲染的skia矢量接口
    SkCanvas* get() override;
public:
    // 内部实现
    std::shared_ptr<render_canvas_2d> impl_2d_;
};


}}}