
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_program_i_v(
    uint32_t program, uint32_t pname, int32_t* params) {
    GLint value = 0;
    ::glGetProgramiv((GLuint)program, (GLenum)pname, &value);
    if (params) { *params = (int32_t)value; }
}