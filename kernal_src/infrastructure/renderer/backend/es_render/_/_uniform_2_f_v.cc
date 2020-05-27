
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_2_f_v(
    int32_t index, uint32_t count, float* v) {
    if (nullptr == v || 0 == count) return;
    auto ele_count = count * 2;
    if (ele_count > 32) {
        std::vector<GLfloat> _0; _0.resize(ele_count);
        for (int i = 0; i < ele_count; ++i) {
            _0[i] = (GLfloat)v[i];
        }
        ::glUniform2fv((GLint)index, (GLsizei)count, &(_0[0]));
    } else {
        GLfloat _0[32];
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLfloat)v[i];
        }
        ::glUniform2fv((GLint)index, (GLsizei)count, &(_0[0]));
    }
}