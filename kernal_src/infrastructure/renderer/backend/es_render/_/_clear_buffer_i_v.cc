
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::clear_buffer_i_v(
    uint32_t buffer, int32_t drawbuffer, int32_t* value) {
    if (nullptr == value) return;
    if (buffer == GL_COLOR) {
        GLint data[4] = {0, 0, 0, 0};
        data[0] = value[0]; data[1] = value[1];
        data[2] = value[2]; data[3] = value[3];
        ::glClearBufferiv(
            (GLenum)buffer, (GLint)(drawbuffer), data);
    } else if (buffer == GL_STENCIL) {
        GLint data = value[0];
        ::glClearBufferiv(
            (GLenum)buffer, (GLint)(drawbuffer), &data);
    } else {
        ::glClearBufferiv(
            (GLenum)buffer, (GLint)(drawbuffer), nullptr);
    }
}