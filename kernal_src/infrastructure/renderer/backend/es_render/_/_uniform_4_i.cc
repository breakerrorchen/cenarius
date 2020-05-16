
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_4_i(
    int32_t index, int32_t v0, int32_t v1, int32_t v2, int32_t v3) {
    ::glUniform4i((GLint)index, (GLint)v0, (GLint)v1, (GLint)v2, (GLint)v3);
}