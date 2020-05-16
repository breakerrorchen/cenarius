
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_uniform_location(
    uint32_t program, const char* name, int32_t* location) {
    int i = ::glGetUniformLocation((GLuint)program, name);
    if (location) { *location = (int32_t)i; }
}