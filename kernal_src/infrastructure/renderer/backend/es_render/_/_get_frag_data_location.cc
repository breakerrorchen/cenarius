
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_frag_data_location(
    uint32_t program, const char* name, int32_t* ret) {
    if (nullptr == ret) return;
    *ret = (int32_t)::glGetFragDataLocation(
        (GLuint)program, name);
}