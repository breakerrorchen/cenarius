
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_program_binary(
    uint32_t program, int32_t buffer_size, int32_t* length, 
    uint32_t* binary_format, void* binary) {
    if (0 >= buffer_size || !binary) return;
    GLsizei ret_len = 0; GLenum format;
    ::glGetProgramBinary((GLuint)program,
        (GLsizei)buffer_size, &ret_len, &format, binary);
    if (length) { *length = (int32_t)ret_len; }
    if (binary_format)  {
        *binary_format = (uint32_t)format;
    }
}