
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_active_uniform_block_name(
    uint32_t program, uint32_t index, int32_t buffer_size,
    int32_t* length, char* buffer) {
    if (!buffer || 0 == buffer_size) return;
    GLsizei size = 0;
    ::glGetActiveUniformBlockName(
        (GLuint)program, (GLuint)index, 
        (GLsizei)buffer_size, &size, (GLchar*)buffer);
    if (length) { *length = (int32_t)size; }
}