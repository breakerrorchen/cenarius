
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_active_uniform_block_i_v(
    uint32_t program, uint32_t index, uint32_t pname,
    int32_t* params) {
    if (!params) return;
    GLint ret = 0;
    ::glGetActiveUniformBlockiv((GLuint)program,
        (GLuint)index, (GLenum)pname, &ret);
    *params = (int32_t)ret;
}