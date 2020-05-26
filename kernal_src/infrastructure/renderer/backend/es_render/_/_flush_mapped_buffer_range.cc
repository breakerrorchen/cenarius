
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::flush_mapped_buffer_range(
    uint32_t target, intptr_t offset, int32_t length) {
    ::glFlushMappedBufferRange((GLenum)target, 
        (GLintptr)offset, (GLsizeiptr)length);
}