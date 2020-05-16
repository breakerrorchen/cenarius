
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_sub_image2d(
    uint32_t target, int32_t level, int32_t x_offset,
    int32_t y_offset, uint32_t width, uint32_t height,
    uint32_t format, uint32_t type, const void* v) {
    ::glTexSubImage2D((GLenum)target, (GLint)level, 
        (GLint)x_offset, (GLint)y_offset, (GLsizei)width, 
        (GLsizei)height, (GLenum)format, (GLenum)type, v);
    ;
}