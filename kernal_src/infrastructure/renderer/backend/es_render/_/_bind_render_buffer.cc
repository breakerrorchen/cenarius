
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_render_buffer(uint32_t target, uint32_t buffer) {
    ::glBindRenderbuffer((GLenum)target, (GLuint)buffer);
}

void render_connector::bind_render_buffer(uint32_t buffer) {
    ::glBindRenderbuffer(GL_RENDERBUFFER, (GLuint)buffer);
}