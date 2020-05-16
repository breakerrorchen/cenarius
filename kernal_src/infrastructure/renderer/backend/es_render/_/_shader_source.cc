
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::shader_source(
    uint32_t shader, const char* src, int32_t len) {
    GLint length = len;
    ::glShaderSource((GLuint)shader,
        1, (const GLchar* const*)&src, &length);
}