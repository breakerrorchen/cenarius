
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::fence_sync(uint32_t condition, uint32_t flags) {
    ::glFenceSync((GLenum)(condition), (GLbitfield)flags);
}