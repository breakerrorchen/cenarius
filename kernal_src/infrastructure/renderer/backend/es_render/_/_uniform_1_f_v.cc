
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_1_f_v(
    int32_t index, uint32_t count, float* v) {
    if (nullptr == v || 0 == count) return;
    if (count > 32) {
        std::vector<GLfloat> _0; _0.resize(count);
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLfloat)v[i];
        }
        ::glUniform1fv((GLint)index, (GLsizei)count, &(_0[0]));
    } else {
        GLfloat _0[32];
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLfloat)v[i];
        }
        ::glUniform1fv((GLint)index, (GLsizei)count, &(_0[0]));
    }
}