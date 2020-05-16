
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_attrib_location(uint32_t program, 
    uint32_t index, const char* name) {
    ::glBindAttribLocation((GLuint)program, (GLuint)index, name);
}