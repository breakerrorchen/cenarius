
#pragma once
#include "render_care.h"
#include "render_context.h"
#include "renderer.h"
#include "render_canvas.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_canvas_3d final: public render_canvas {
public:
    render_canvas_3d(std::shared_ptr<renderer_combined>);
    render_canvas_3d(const render_canvas_3d&) = delete;
    render_canvas_3d(render_canvas_3d&&) = delete;
    render_canvas_3d& operator=(const render_canvas_3d&) = delete;
    render_canvas_3d& operator=(render_canvas_3d&&) = delete;
    ~render_canvas_3d();

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
    // reconstruct the new canvas size
    bool reset_size(int, int, int aa = 0) override;

public:
    std::shared_ptr<render_context> render_context_;
    GLuint frame_buffer_ = 0, render_buffer_ = 0, depth_ = 0;
};


}}}