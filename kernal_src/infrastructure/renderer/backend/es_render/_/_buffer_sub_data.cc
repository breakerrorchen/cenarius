
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::buffer_sub_data(uint32_t target, 
    intptr_t offset, intptr_t size, const void* data) {
    ::glBufferSubData((GLenum)target, 
        (GLintptr)offset, (GLsizeiptr)size, data);
}