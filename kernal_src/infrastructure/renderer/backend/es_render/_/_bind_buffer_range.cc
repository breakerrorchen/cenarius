
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_buffer_range(
    uint32_t target, uint32_t index, uint32_t buffer,
    intptr_t offset, uint32_t size) {
    ::glBindBufferRange((GLenum)(target), 
        (GLuint)index, (GLuint)buffer, (GLintptr)offset, 
        (GLsizeiptr)size);
}