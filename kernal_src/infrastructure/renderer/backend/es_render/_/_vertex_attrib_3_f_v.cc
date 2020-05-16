
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_3_f_v(
    uint32_t index, float* v) {
    GLfloat value[3] = {v[0], v[1], v[2]};
    ::glVertexAttrib3fv((GLuint)index, &value[0]);
}