
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_block_binding(
    uint32_t program, uint32_t index, uint32_t binding) {
    ::glUniformBlockBinding(
        (GLuint)program, (GLuint)index, (GLuint)binding);
}