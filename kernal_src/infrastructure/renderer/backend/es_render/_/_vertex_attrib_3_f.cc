
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_3_f(
    uint32_t index, float v0, float v1, float v2) {
    GLfloat value[3] = {v0, v1, v2};
    ::glVertexAttrib3fv((GLuint)index, &value[0]);
}