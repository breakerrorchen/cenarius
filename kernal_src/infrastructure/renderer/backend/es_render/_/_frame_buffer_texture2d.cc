
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::frame_buffer_texture2d(uint32_t target,
    uint32_t attachment, uint32_t textarget, uint32_t texture, int32_t level) {
    ::glFramebufferTexture2D((GLenum)target,
        (GLenum)attachment, (GLenum)textarget, (GLuint)texture, (GLint)level);
}