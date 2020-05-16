
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_3_f(
    int32_t index, float v0, float v1, float v2) {
    ::glUniform3f((GLint)index,
        (GLfloat)v0, (GLfloat)v1, (GLfloat)v2);
}