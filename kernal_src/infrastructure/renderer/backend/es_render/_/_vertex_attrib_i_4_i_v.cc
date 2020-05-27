
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_i_4_i_v(uint32_t index, int32_t* v) {
    GLint value[4] = {v[0], v[1], v[2], v[3]};
    ::glVertexAttribI4iv((GLuint)index, &(value[0]));
}