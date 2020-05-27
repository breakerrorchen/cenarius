
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::frame_buffer_texture_layer(
    uint32_t target, uint32_t attachment, uint32_t texture,
    int32_t level, int32_t layer) {
    ::glFramebufferTextureLayer(
        (GLenum)target, (GLenum)attachment, 
        (GLuint)texture,(GLint)level, (GLint)layer);
}