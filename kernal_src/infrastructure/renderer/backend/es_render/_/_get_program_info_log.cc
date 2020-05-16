
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_program_info_log(
    uint32_t program, int32_t buf_size, int32_t* length, char* v) {
    GLsizei len = 0;
    ::glGetProgramInfoLog((GLuint)program, (GLsizei)buf_size, &len, v);
    if (length) { *length = (int32_t)len; }
}