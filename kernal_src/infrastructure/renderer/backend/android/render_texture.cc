
#include "render_texture.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

render_texture::~render_texture() {
    if (0 != id_) {
        ::glDeleteTextures(1, &id_);
    }
}

int render_texture::w() const { return (int)w_; }
int render_texture::h() const { return (int)h_; }

bool render_texture::read_buffer(std::vector<uint8_t>& buffer) {
    if (0 == id_ && w_ > 0 && h_ > 0) return false;
    GLint frame_buffer_binding = 0;
    ::glGetIntegerv(GL_FRAMEBUFFER_BINDING, &frame_buffer_binding);
    GLuint fbo = 0;
    ::glGenFramebuffers(1, &fbo);
    ::glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    ::glFramebufferTexture2D(GL_FRAMEBUFFER, 
        GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, id_, 0);
    buffer.resize(w_ * h_ * sizeof(uint32_t));
    ::glReadPixels(0, 0, w_, h_, GL_RGBA, GL_UNSIGNED_BYTE, &buffer[0]);
    ::glBindFramebuffer(GL_FRAMEBUFFER, frame_buffer_binding);
    ::glDeleteFramebuffers(1, &fbo);
    return true;
}