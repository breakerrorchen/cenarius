
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::tex_storage2d(
    uint32_t target, int32_t levels, 
    uint32_t internal_informat, int32_t width, 
    int32_t height) {
    ::glTexStorage2D((GLenum)target, (GLsizei)levels,
        (GLenum)internal_informat, (GLsizei)width,
        (GLsizei)height);
}