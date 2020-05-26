
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::clear_buffer_u_i_v(
    uint32_t buffer, int32_t drawbuffer, uint32_t* value) {
    if (nullptr == value) return;
    if (buffer == GL_COLOR) {
        GLuint data[4] = {0, 0, 0, 0};
        data[0] = value[0]; data[1] = value[1];
        data[2] = value[2]; data[3] = value[3];
        ::glClearBufferuiv(
            (GLenum)buffer, (GLint)(drawbuffer), data);
    } else {
        ::glClearBufferuiv(
            (GLenum)buffer, (GLint)(drawbuffer), nullptr);
    }
}