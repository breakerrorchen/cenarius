
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::compile_shader(uint32_t shader) {
    ::glCompileShader((GLuint)shader);
}