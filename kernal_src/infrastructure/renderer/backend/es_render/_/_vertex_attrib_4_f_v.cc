
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_4_f_v(uint32_t index, float* v) {
    GLfloat value[4] = {v[0], v[1], v[2], v[3]};
    ::glVertexAttrib4fv((GLuint)index, &value[0]);
}