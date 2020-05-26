
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::program_parameter_i(
    uint32_t program, uint32_t pname, int32_t value) {
    ::glProgramParameteri(
        (GLuint)program, (GLenum)pname, (GLint)value);
}