
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_4_f(
    uint32_t index, float v0, float v1, float v2, float v3) {
    GLfloat value[4] = {v0, v1, v2, v3};
    ::glVertexAttrib4fv((GLuint)index, &value[0]);
}