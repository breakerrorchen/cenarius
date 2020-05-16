
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::check_frame_buffer_status(
    uint32_t target, uint32_t* status) {
    if (nullptr != status) {
        *status = ::glCheckFramebufferStatus((GLenum)target);
    }
}