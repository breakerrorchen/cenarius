
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_shader(uint32_t v) {
    ::glDeleteShader((GLuint)v);
}