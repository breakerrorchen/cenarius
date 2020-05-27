
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_matrix_2x3_f_v(
    int32_t index, uint32_t count, bool transpose, float* v) {
    ::glUniformMatrix2x3fv((GLint)index, (GLsizei)count, (GLboolean)transpose, v);
}