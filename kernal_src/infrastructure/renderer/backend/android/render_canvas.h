
#pragma once
#include "render_care.h"
#include "render_context.h"
#include "renderer.h"
#include "render_texture.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_canvas {
public:
    virtual ~render_canvas() = default;
public:
    virtual void   build(int, int, int aa = 0) = 0;
    virtual void   make_current() = 0;
    virtual GLuint related_framebuffer() = 0;
    virtual bool   reset_size(int, int, int aa = 0) = 0;

public:
    bool render_on_window();
    bool bitblt_on_window();

public:
    std::shared_ptr<render_texture> snapshot();

public:
    std::weak_ptr<renderer_combined> related_renderer_;
    uint32_t width_ = 0, height_ = 0, left_ = 0, top_ = 0;
};


}}}