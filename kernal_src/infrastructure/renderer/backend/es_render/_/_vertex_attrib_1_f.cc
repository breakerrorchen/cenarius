
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::vertex_attrib_1_f(
    uint32_t index, float v) {
    GLfloat value = v;
    ::glVertexAttrib1fv((GLuint)index, &value);
}