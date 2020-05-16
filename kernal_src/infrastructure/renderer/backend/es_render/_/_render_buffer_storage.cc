
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::render_buffer_storage(
    uint32_t target, uint32_t internal_format, uint32_t width, 
    uint32_t height) {
    ::glRenderbufferStorage((GLenum)target, 
        (GLenum)internal_format, (GLsizei)width, (GLsizei)height);
}