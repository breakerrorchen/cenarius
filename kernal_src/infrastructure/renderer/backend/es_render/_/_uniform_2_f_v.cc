
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_2_f_v(
    int32_t index, uint32_t count, float* v) {
    ::glUniform2fv((GLint)index, (GLsizei)count, v);
}