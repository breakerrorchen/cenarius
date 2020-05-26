
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_buffer_parameter_i64_v(
    uint32_t target, uint32_t value, int64_t* data) {
    if (nullptr == data) return;
    GLint64 ret_value = 0;
    ::glGetBufferParameteri64v((GLenum)target,
        (GLenum)value, &ret_value);
    *data = (int64_t)ret_value;
}