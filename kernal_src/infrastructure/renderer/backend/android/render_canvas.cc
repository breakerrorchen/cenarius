
#include "render_canvas.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

bool render_canvas::render_on_window() {
    return true;
}

bool render_canvas::bitblt_on_window() {
    if (0 == width_ || 0 == height_) return false;
    auto renderer = related_renderer_.lock();
    if (!renderer) return false;
    auto renderer_fb_id = renderer->framebuffer_.display_framebuffer();
    auto fb_id = related_framebuffer();
    if (0 == fb_id) return false;
    auto enable_scissor_test = ::glIsEnabled(GL_SCISSOR_TEST);
    if (enable_scissor_test) { ::glDisable(GL_SCISSOR_TEST); }
    GLint read_buffer = 0, draw_buffer = 0;
    ::glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_buffer);
    ::glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_buffer);
    ::glBindFramebuffer(GL_READ_FRAMEBUFFER, fb_id);
    ::glBindFramebuffer(GL_DRAW_FRAMEBUFFER, renderer_fb_id);
    ::glBlitFramebuffer(0, 0, width_, height_,
        0, 0, width_, height_, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    ::glBindFramebuffer(GL_READ_FRAMEBUFFER, (GLuint)read_buffer);
    ::glBindFramebuffer(GL_DRAW_FRAMEBUFFER, (GLuint)draw_buffer);
    if (enable_scissor_test) { ::glEnable(GL_SCISSOR_TEST); }
    return true;
}

std::shared_ptr<render_texture> render_canvas::snapshot() {
    if (0 == width_ || 0 == height_) return nullptr;
    auto fb_id = related_framebuffer();
    if (0 == fb_id) return nullptr;
    auto enable_scissor_test = ::glIsEnabled(GL_SCISSOR_TEST);
    ::glDisable(GL_SCISSOR_TEST);
    GLint read_buffer = 0, draw_buffer = 0;
    ::glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, &read_buffer);
    ::glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, &draw_buffer);
    GLint texture_binding_2d = 0;
    ::glGetIntegerv(GL_TEXTURE_2D, &texture_binding_2d);
    GLuint texture_id = 0; ::glGenTextures(1, &texture_id);
    ::glBindTexture(GL_TEXTURE_2D, texture_id);
    ::glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 
        width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    GLuint frame_buffer_id = 0;
    ::glGenFramebuffers(1, &frame_buffer_id);
    ::glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_id);
    ::glFramebufferTexture2D(GL_FRAMEBUFFER, 
        GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id, 0);
    ::glBindFramebuffer(GL_READ_FRAMEBUFFER, fb_id);
    ::glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frame_buffer_id);
    ::glBlitFramebuffer(0, 0, width_, height_, 0, 
        0, width_, height_, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    if (enable_scissor_test) { ::glEnable(GL_SCISSOR_TEST); }
    ::glBindTexture(GL_TEXTURE_2D, (GLuint)texture_binding_2d);
    ::glBindFramebuffer(GL_READ_FRAMEBUFFER, (GLuint)read_buffer);
    ::glBindFramebuffer(GL_DRAW_FRAMEBUFFER, (GLuint)draw_buffer);
    ::glDeleteFramebuffers(1, &frame_buffer_id);
    auto texture = std::make_shared<render_texture>();
    texture->id_ = texture_id;
    texture->w_ = width_; texture->h_ = height_;
    return texture;
}