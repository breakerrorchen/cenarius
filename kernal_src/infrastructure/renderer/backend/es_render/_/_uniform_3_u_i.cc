
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_3_u_i(
    int32_t index, uint32_t v0, uint32_t v1, uint32_t v2) {
    ::glUniform3ui((GLint)index, 
        (GLuint)v0, (GLuint)v1, (GLuint)v2);
}