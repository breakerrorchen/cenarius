
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::copy_tex_sub_image2d(
    uint32_t target, int32_t level, int32_t x_offset, int32_t y_offset,
    int32_t x, int32_t y, uint32_t width, uint32_t height) {
    ::glCopyTexSubImage2D((GLenum)target, 
        (GLint)level, (GLint)x_offset, (GLint)y_offset, (GLint)x, 
        (GLint)y, (GLsizei)width, (GLsizei)height);
}