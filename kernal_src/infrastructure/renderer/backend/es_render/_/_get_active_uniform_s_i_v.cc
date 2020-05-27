
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_active_uniform_s_i_v(
    uint32_t program, int32_t count, const uint32_t* indices,
    uint32_t pname, int32_t* params) {
    if (0 == count || !indices || !params) return;
    if (count > 32) {
        std::vector<GLuint> _0; std::vector<GLint> _1;
        _0.resize(count); _1.resize(count);
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLuint)indices[i];
        }
        ::glGetActiveUniformsiv(
            (GLuint)program, (GLsizei)count, &(_0[0]), 
            (GLenum)pname, &(_1[0]));
        for (int i = 0; i < count; ++i) {
            params[i] = (int32_t)_1[i];
        }
    } else {
        GLuint _0[32]; GLint _1[32];
        for (int i = 0; i < count; ++i) {
            _0[i] = (GLuint)indices[i];
        }
        ::glGetActiveUniformsiv(
            (GLuint)program, (GLsizei)count, &(_0[0]), 
            (GLenum)pname, &(_1[0]));
        for (int i = 0; i < count; ++i) {
            params[i] = (int32_t)_1[i];
        }
    }
}