
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::map_buffer_range(
    uint32_t target, intptr_t offset, int32_t length, 
    uint32_t access, void** buffer_ptr) {
    if (!buffer_ptr) return;
    *buffer_ptr = ::glMapBufferRange((GLenum)target,
        (GLintptr)offset, (GLsizeiptr)length,
        (GLbitfield)access);
}