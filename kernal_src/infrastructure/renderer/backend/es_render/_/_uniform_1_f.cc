
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_1_f(int32_t index, float v) {
    ::glUniform1f((GLint)index, (GLfloat)v);
}