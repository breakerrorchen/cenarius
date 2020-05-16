
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::copy_tex_image2d(uint32_t target, int32_t level,
    uint32_t internal_format, int32_t x, int32_t y, uint32_t width, 
    uint32_t height, int32_t border) {
    ::glCopyTexImage2D((GLenum)target, (GLint)level, (GLenum)internal_format, 
        (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height, (GLint)border);
}