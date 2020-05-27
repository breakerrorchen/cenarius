
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_1_u_i(int32_t index, uint32_t v) {
    ::glUniform1ui((GLint)index, (GLuint)v);
}