
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_query_object_u_i_v(
    uint32_t _id, uint32_t pname, uint32_t* params) {
    if (nullptr == params) return;
    GLuint ret_params = 0;
    ::glGetQueryObjectuiv(
        (GLuint)_id, (GLenum)pname, &ret_params);
    *params = (uint32_t)ret_params;
}