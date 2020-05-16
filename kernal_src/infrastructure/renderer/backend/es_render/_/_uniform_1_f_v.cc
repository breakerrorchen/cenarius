
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_1_f_v(
    int32_t index, uint32_t count, float* v) {
    ::glUniform1fv((GLint)index, (GLsizei)count, v);
}