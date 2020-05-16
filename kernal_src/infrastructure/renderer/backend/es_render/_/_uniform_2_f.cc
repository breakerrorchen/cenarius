

#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_2_f(
    int32_t index, float v0, float v1) {
    ::glUniform2f((GLint)index, (GLfloat)v0, (GLfloat)v1);
}