
#include "common/logger.h"
#include "render_canvas_3d.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

render_canvas_3d::render_canvas_3d(
    std::shared_ptr<renderer_combined> _renderer) {
    assert(_renderer);
    related_renderer_ = _renderer;
}

render_canvas_3d::~render_canvas_3d() {
    if (0 != frame_buffer_) {
        ::glDeleteFramebuffers(1, &frame_buffer_);
    }
    reset_size(0, 0);
}

void render_canvas_3d::build(int w, int h, int aa) {
    if (!render_context_) {
        auto renderer = related_renderer_.lock();
        if (renderer) {
            render_context_ = renderer->new_context();
        }
        assert(render_context_);
    }
    render_canvas_3d::reset_size(w, h, aa);
    render_context_->state_.framebuffer_binding_ = render_buffer_;
    render_context_->state_.viewport_   [0] = 0;
    render_context_->state_.viewport_   [1] = 0;
    render_context_->state_.viewport_   [2] = width_;
    render_context_->state_.viewport_   [3] = height_; 
    render_context_->state_.scissor_box_[0] = 0;
    render_context_->state_.scissor_box_[1] = 0;
    render_context_->state_.scissor_box_[2] = width_;
    render_context_->state_.scissor_box_[3] = height_;
}

GLuint render_canvas_3d::related_framebuffer() {
    return frame_buffer_;
}

bool render_canvas_3d::reset_size(int w, int h, int aa) {
    if (w == width_ || h == height_) return true;
    if (0 != render_buffer_) { 
        ::glDeleteRenderbuffers(1, &render_buffer_);
    }
    if (0 != depth_) { 
        ::glDeleteRenderbuffers(1, &depth_); 
    }
    width_ = height_ = 0; 
    frame_buffer_ = render_buffer_ = depth_ = 0;
    if (0 >= w || 0 >= h) return true;
    width_ = w; height_ = h; GLint max_samples = 0;
    ::glGetIntegerv(GL_MAX_SAMPLES, &max_samples);
    if (aa > max_samples) aa = max_samples; 
    if (aa <= 0) aa = 1;

    GLint read_buffer = 0, draw_buffer = 0, render_buffer = 0;
    ::glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_buffer  );
    ::glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_buffer  );
    ::glGetIntegerv(GL_RENDERBUFFER_BINDING,     &render_buffer);
    ::glGenRenderbuffers(1, &render_buffer_);
    ::glBindRenderbuffer(GL_RENDERBUFFER, render_buffer_);
    ::glRenderbufferStorageMultisample(
        GL_RENDERBUFFER, aa, GL_RGBA8, width_,  height_);
    ::glGenRenderbuffers(1, &depth_);
    ::glBindRenderbuffer(GL_RENDERBUFFER, depth_);
    ::glRenderbufferStorageMultisample(
        GL_RENDERBUFFER, aa, GL_DEPTH24_STENCIL8, width_, height_);
    if (0 == frame_buffer_) { 
        ::glGenFramebuffers(1, &frame_buffer_);
    }
    ::glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_);
    ::glFramebufferRenderbuffer(
        GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, render_buffer_);
    ::glFramebufferRenderbuffer(
        GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,  GL_RENDERBUFFER, depth_);
    ::glFramebufferRenderbuffer(
        GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT,GL_RENDERBUFFER, depth_);
    ::glBindFramebuffer(GL_RENDERBUFFER, render_buffer);
    ::glBindFramebuffer(GL_READ_FRAMEBUFFER, (GLuint)read_buffer);
    ::glBindFramebuffer(GL_DRAW_FRAMEBUFFER, (GLuint)draw_buffer);
    ::glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)frame_buffer_);

    return true;
}