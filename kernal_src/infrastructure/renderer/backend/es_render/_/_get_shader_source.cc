
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_shader_source(
    uint32_t shader, uint32_t buf_size, uint32_t* length, char* source) {
    GLsizei len = 0;
    ::glGetShaderSource((GLuint)shader,(GLsizei)buf_size, &len, source);
    if (length) { *length = (uint32_t)len; }
}