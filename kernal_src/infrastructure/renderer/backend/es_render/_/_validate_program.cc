
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::validate_program(uint32_t program) {
    ::glValidateProgram((GLuint)program);
}