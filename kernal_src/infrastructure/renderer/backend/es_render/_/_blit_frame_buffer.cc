
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::blit_frame_buffer(
    int32_t src_x_0, int32_t src_y_0, int32_t src_x_1, int32_t src_y_1,
    int32_t dst_x_0, int32_t dst_y_0, int32_t dst_x_1, int32_t dst_y_1,
    uint32_t mask, uint32_t filter) {
    ::glBlitFramebuffer(src_x_0, src_y_0, src_x_1, src_y_1,
        dst_x_0, dst_y_0, dst_x_1, dst_y_1, (GLbitfield)mask,
        (GLenum)filter);
}