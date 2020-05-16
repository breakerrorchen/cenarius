
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_pointer(
    uint32_t index, int32_t size, uint32_t type, bool normalized,
    uint32_t stride, const void* offset) {
    ::glVertexAttribPointer((GLuint)index, (GLint)size, (GLenum)type,
        (GLboolean)normalized, (GLsizei)stride, (GLvoid*)offset);
}