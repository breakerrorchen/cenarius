
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::buffer_data(
    uint32_t target, intptr_t size, const void* data, uint32_t usage) {
    ::glBufferData((GLenum)target, (GLsizeiptr)size, data, (GLenum)usage);
}