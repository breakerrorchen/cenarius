
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::shader_binary(
    int32_t count, const uint32_t* shaders, uint32_t format,
    const void* binary, int32_t length) {
    if (0 >= count || !shaders || !binary || 0 >= length) {
        return;
    }
    if (count > 32) {
        std::vector<GLuint> _0; _0.resize(count);
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLuint)shaders[i];
        }
        ::glShaderBinary((GLsizei)count, &(_0[0]),
            (GLenum)format, binary, (GLsizei)length);
    } else {
        GLuint _0[32] = { 0 };
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLuint)shaders[i];
        }
        ::glShaderBinary((GLsizei)count, &(_0[0]),
            (GLenum)format, binary, (GLsizei)length);
    }
}