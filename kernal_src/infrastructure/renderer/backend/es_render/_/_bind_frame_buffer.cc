
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_frame_buffer(uint32_t target, uint32_t buffer) {
    if (0 != buffer) {
        ::glBindFramebuffer((GLenum)target, (GLuint)buffer);
    } else {
        ::glBindFramebuffer((GLenum)target, (GLuint)related_frambuffer_id_);
    }
}

void render_connector::bind_frame_buffer(uint32_t buffer) {
    if (0 != buffer) {
        ::glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)buffer);
    } else {
        ::glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)related_frambuffer_id_);
    }
}