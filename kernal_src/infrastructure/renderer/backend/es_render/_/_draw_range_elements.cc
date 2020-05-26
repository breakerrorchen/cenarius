
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::draw_range_elements(
    uint32_t mode, uint32_t start, uint32_t end, 
    int32_t count, uint32_t type, const void* indices) {
    ::glDrawRangeElements((GLenum)mode,
        (GLuint)start, (GLuint)end, (GLsizei)count,
        (GLenum)type, indices);
}