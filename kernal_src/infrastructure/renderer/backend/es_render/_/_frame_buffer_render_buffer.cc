
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::frame_buffer_render_buffer(uint32_t target,
    uint32_t attachment, uint32_t renderbuffer_target, uint32_t renderbuffer) {
    ::glFramebufferRenderbuffer((GLenum)target,
        (GLenum)attachment, (GLenum)renderbuffer_target, (GLuint)renderbuffer);
}