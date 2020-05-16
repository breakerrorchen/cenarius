
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_1_f_v(uint32_t index, float* v) {
    GLfloat value = v[0];
    ::glVertexAttrib1fv((GLuint)index, &value);
}