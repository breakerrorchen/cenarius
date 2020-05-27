
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_4_u_i_v(
    int32_t index, uint32_t count, uint32_t* v) {
    ::glUniform4uiv((GLint)index, (GLsizei)count, v);
}