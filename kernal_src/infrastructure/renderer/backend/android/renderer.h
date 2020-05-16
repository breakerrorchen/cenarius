
#pragma once
#include "render_care.h"
#include "render_framebuffer.h"
#include "render_context.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_canvas;
class render_interface_canvas;
class render_canvas_2d;
class render_canvas_3d;
class renderer_combined final
    : public std::enable_shared_from_this<renderer_combined> {
    friend class render_canvas   ;
    friend class render_interface_canvas;
    friend class render_context  ;
    friend class render_canvas_2d;
    friend class render_canvas_3d;
public:
    renderer_combined(const render_native_window&);
    bool reset(const render_native_window&);
    std::shared_ptr<render_context> new_context();
    std::shared_ptr<render_context> shared_2d_context(
        bool* first_created = nullptr);

public:
    // 获取当前系统窗口的宽度
    inline int get_window_width() const {
        return framebuffer_.w();
    }

    // 获取当前系统窗口的高度
    inline int get_window_height() const {
        return framebuffer_.h();
    }

public:
    // 提交给系统显示，就是简单的提交eglSwapBuffers
    void commit_drawable();
    // 安装默认的context
    void make_defaut_context();

private:
    render_framebuffer framebuffer_;
    render_context context_;
    std::shared_ptr<render_context> current_context_;
    std::shared_ptr<render_context> shared_2d_context_;
    sk_sp<GrContext> sk_context_;
    sk_sp<const GrGLInterface> sk_interface_;
};


}}}