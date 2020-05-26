
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_uniform_block_index(
    uint32_t program, const char* name, uint32_t* index) {
    if (nullptr == index) return;
    *index = (uint32_t)::glGetUniformBlockIndex(
        (GLuint)program, name);
}