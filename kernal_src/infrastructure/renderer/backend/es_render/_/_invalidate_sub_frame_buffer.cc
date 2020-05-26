
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::invalidate_sub_frame_buffer(
    uint32_t target, int32_t size, const uint32_t* attachments,
    int32_t x, int32_t y, int32_t width, int32_t height) {
    if (0 >= size || !attachments) return;
    if (size > 32) {
        std::vector<GLenum> _0; _0.resize(size);
        for (int i = 0; i < size; ++i) {
            _0[i] = (GLenum)attachments[i];
        }
        ::glInvalidateSubFramebuffer(
            (GLenum)target, (GLsizei)size, &(_0[0]),
            (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    } else {
        GLenum _0[32] = { 0 };
        for (int i = 0; i < size; ++i) {
            _0[i] = (GLenum)attachments[i];
        }
        ::glInvalidateSubFramebuffer(
            (GLenum)target, (GLsizei)size, &(_0[0]),
            (GLint)x, (GLint)y, (GLsizei)width, (GLsizei)height);
    }
}