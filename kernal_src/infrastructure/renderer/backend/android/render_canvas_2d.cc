
#include "render_canvas_2d.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

render_canvas_2d::render_canvas_2d(
    std::shared_ptr<renderer_combined> _renderer) {
    assert(_renderer);
    related_renderer_ = _renderer; 
    sk_context_ = _renderer->sk_context_;
}

render_canvas_2d::~render_canvas_2d() {
    ;
}

void render_canvas_2d::build(int w, int h, int) {
    bool first_created = false;
    if (!render_context_) {
        auto renderer = related_renderer_.lock();
        if (renderer) {
            render_context_ = renderer
                ->shared_2d_context(&first_created);
        }
        assert(render_context_);
    }
    render_context_->make_current();
    render_canvas_2d::reset_size(w, h, 0);
    if (first_created) {
        render_context_->capture();
    }
}

GLuint render_canvas_2d::related_framebuffer() {
    if (!sk_surface_) return 0;
    auto target = sk_surface_->getBackendRenderTarget(
        SkSurface::kFlushRead_BackendHandleAccess);
    GrGLFramebufferInfo frame_buffer_info;
    target.getGLFramebufferInfo(&frame_buffer_info);
    return frame_buffer_info.fFBOID;
}

bool render_canvas_2d::reset_size(int w, int h, int) {
    sk_surface_ = nullptr; sk_canvas_ = nullptr; width_ = height_ = 0;
    if (0 == w || 0 == h) return false;
    width_ = w; height_ = h;
    auto info = SkImageInfo::MakeN32(w, h, kPremul_SkAlphaType, nullptr);
    sk_surface_ = SkSurface::MakeRenderTarget(sk_context_.get(), 
        SkBudgeted::kNo, info, 0, kBottomLeft_GrSurfaceOrigin, nullptr);
    if (sk_surface_) {
        sk_canvas_ = sk_surface_->getCanvas();
    }
    return sk_canvas_ && sk_surface_;
}