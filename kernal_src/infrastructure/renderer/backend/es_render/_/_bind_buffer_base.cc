
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_buffer_base(
    uint32_t target, uint32_t index, uint32_t buffer) {
    ::glBindBufferBase((GLenum)(target), 
        (GLuint)index, (GLuint)buffer);
}