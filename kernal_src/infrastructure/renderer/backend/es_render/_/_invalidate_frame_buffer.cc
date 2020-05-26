
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::invalidate_frame_buffer(
    uint32_t target, int32_t size, const uint32_t* attachments) {
    if (0 >= size || !attachments) return;
    if (size > 32) {
        std::vector<GLenum> _0; _0.resize(size);
        for (int i = 0; i < size; ++i) {
            _0[i] = (GLenum)attachments[i];
        }
        ::glInvalidateFramebuffer(
            (GLenum)target, (GLsizei)size, &(_0[0]));
    } else {
        GLenum _0[32] = { 0 };
        for (int i = 0; i < size; ++i) {
            _0[i] = (GLenum)attachments[i];
        }
        ::glInvalidateFramebuffer(
            (GLenum)target, (GLsizei)size, &(_0[0]));
    }
}