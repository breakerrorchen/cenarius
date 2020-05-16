
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::detach_shader(uint32_t program, uint32_t shader) {
    ::glDetachShader((GLuint)program, (GLuint)shader);
}