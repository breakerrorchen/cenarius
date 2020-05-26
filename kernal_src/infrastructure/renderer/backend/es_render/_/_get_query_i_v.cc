
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_query_i_v(
    uint32_t target, uint32_t pname, int32_t* params) {
    if (nullptr == params) return;
    GLint ret_params = 0;
    ::glGetQueryiv(
        (GLenum)target, (GLenum)pname, &ret_params);
    *params = (int32_t)ret_params;
}