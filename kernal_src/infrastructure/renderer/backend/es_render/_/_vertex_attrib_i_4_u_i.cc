
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_i_4_u_i(uint32_t index, 
    uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) {
    ::glVertexAttribI4i((GLuint)index, 
        (GLint)v0, (GLint)v1, (GLint)v2, (GLint)v3);
}