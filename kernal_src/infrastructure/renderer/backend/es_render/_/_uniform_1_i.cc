
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_1_i(int32_t index, int32_t v) {
    ::glUniform1i((GLint)index, (GLint)v);
}