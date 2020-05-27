
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::clear_buffer_f_i(uint32_t buffer, 
    int32_t drawbuffer, float depth, int32_t stencil) {
    ::glClearBufferfi((GLenum)buffer, 
        (GLint)(drawbuffer), depth, stencil);
}