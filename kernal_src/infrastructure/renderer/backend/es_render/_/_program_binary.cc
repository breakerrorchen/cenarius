
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::program_binary(uint32_t program, 
    uint32_t format, void* binary, int32_t length) {
    if (0 >= length || !binary) return;
    ::glProgramBinary((GLuint)program, 
        (GLenum)format, binary, (GLsizei)length);
}