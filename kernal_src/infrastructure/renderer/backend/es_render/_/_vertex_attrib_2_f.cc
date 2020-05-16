
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_2_f(
    uint32_t index, float v0, float v1) {
    GLfloat value[2] = {v0, v1};
    ::glVertexAttrib2fv((GLuint)index, &value[0]);
}