
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_sub_image3d(
    uint32_t target, int32_t level, int32_t x_offset,
    int32_t y_offset, int32_t z_offset, 
    int32_t width, int32_t height, int32_t depth,
    uint32_t format, uint32_t type, const void* v) {
    ::glTexSubImage3D((GLenum)target, (GLint)level, 
        (GLint)x_offset, (GLint)y_offset, (GLint)z_offset,
        (GLsizei)width, (GLsizei)height, (GLsizei)depth,
        (GLenum)format, (GLenum)type, v);
    ;
}