
#pragma once
#include "render_care.h"
#include "render_context.h"
#include "renderer.h"
#include "render_canvas.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_canvas_2d final: public render_canvas {
public:
    render_canvas_2d(std::shared_ptr<renderer_combined>);
    render_canvas_2d(const render_canvas_2d&) = delete;
    render_canvas_2d(render_canvas_2d&&) = delete;
    render_canvas_2d& operator=(const render_canvas_2d&) = delete;
    render_canvas_2d& operator=(render_canvas_2d&&) = delete;
    ~render_canvas_2d();

public:
    inline SkCanvas* get_canvas() const {
        return sk_canvas_;
    }

public:
    // 设置当前渲染上下文
    // 只有在正确的设置下，才能保证当前的canvas渲染是正确安全的
    inline void make_current() override {
        if (render_context_) {
            render_context_->make_current();
        }
    }

public:
    void build(int, int, int aa = 0) override;
    // get the id of the corresponding fbo currently rendered
    GLuint related_framebuffer() override;
    // reconstruct the new canvas size, aa will be ignore
    bool reset_size(int, int, int aa = 0) override;

public:
    std::shared_ptr<render_context> render_context_;
    SkCanvas* sk_canvas_ = nullptr;
    sk_sp<GrContext> sk_context_; sk_sp<SkSurface> sk_surface_;
};


}}}