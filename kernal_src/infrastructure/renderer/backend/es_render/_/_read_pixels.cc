
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::read_pixels(
    int32_t x, int32_t y, uint32_t width, uint32_t height,
    uint32_t format, uint32_t type, void* data) {
    // 从本地内存向GPU的传输（UNPACK）
    GLint alignment = 0;
    ::glGetIntegerv(GL_PACK_ALIGNMENT, &alignment);
    if (1 != alignment) {
        ::glPixelStorei(GL_PACK_ALIGNMENT, 1);
    }
    ::glReadPixels((GLint)x, (GLint)y, (GLsizei)width,
        (GLsizei)height, (GLenum)format, (GLenum)type, data);
    if (1 != alignment) {
        ::glPixelStorei(GL_PACK_ALIGNMENT, alignment);
    }
}