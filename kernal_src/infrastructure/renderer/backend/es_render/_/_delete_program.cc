
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_program(int32_t v) {
    ::glDeleteProgram((GLuint)v);
}