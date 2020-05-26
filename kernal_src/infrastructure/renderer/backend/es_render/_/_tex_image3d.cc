
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_image3d(
    uint32_t target, int32_t level, int32_t internal_format,
    int32_t width, int32_t height, int32_t depth,
    int32_t border, uint32_t format, uint32_t type, 
    const void* v) {
    ::glTexImage3D((GLenum)target, 
        (GLint)level, (GLint)internal_format,
        (GLsizei)width, (GLsizei)height, (GLsizei)depth,
        (GLint)border, (GLenum )format, (GLenum)type, v);
    ;
}