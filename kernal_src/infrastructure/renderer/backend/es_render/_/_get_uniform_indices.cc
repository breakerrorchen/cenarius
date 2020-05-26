
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_uniform_indices(
    uint32_t program, int32_t count, const char** names, 
    uint32_t* indices) {
    if (0 == count || !names || !indices) return;
    if (count > 32) {
        std::vector<GLuint> _0; _0.resize(count);
        ::glGetUniformIndices((GLuint)program,
            (GLsizei)count, names, &(_0[0]));
        for (int i = 0; i < count; ++i) {
            indices[i] = (uint32_t)_0[i];
        }
    } else {
        GLuint _0[32] = { 0 };
        ::glGetUniformIndices((GLuint)program,
            (GLsizei)count, names, &(_0[0]));
        for (int i = 0; i < count; ++i) {
            indices[i] = (uint32_t)_0[i];
        }
    }
}