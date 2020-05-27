
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::unmap_buffer(uint32_t target, bool* success) {
    if (nullptr != success) {
        *success = ::glUnmapBuffer((GLenum)target);
    }
}