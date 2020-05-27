
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::uniform_4_i_v(
    int32_t index, uint32_t count, int32_t* v) {
    if (nullptr == v || 0 == count) return;
    auto ele_count = count * 4;
    if (ele_count > 32) {
        std::vector<GLint> _0; _0.resize(ele_count);
        for (int i = 0; i < ele_count; ++i) {
            _0[i] = (GLint)v[i];
        }
        ::glUniform4iv((GLint)index, (GLsizei)count, &(_0[0]));
    } else {
        GLint _0[32];
        for (int i = 0; i < ele_count; ++i) {
            _0[i] = (GLint)v[i];
        }
        ::glUniform4iv((GLint)index, (GLsizei)count, &(_0[0]));
    }
}