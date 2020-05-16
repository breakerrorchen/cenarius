
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::viewport(
    int32_t x, int32_t y, uint32_t w, uint32_t h) {
    ::glViewport((GLint)x, (GLint)y, (GLsizei)w, (GLsizei)h);
}