
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::render_buffer_storage_ms(
    uint32_t target, int32_t samples, uint32_t format, 
    int32_t w, int32_t h) {
    ::glRenderbufferStorageMultisample(
        (GLenum)target, (GLsizei)samples, 
        (GLenum)format, (GLsizei)w, (GLsizei)h);
}