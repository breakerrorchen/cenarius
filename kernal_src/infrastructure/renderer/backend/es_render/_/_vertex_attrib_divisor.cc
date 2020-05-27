
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_divisor(
    uint32_t _index, uint32_t divisor) {
    ::glVertexAttribDivisor(
        (GLuint)_index, (GLuint)divisor);
}