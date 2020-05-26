
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_internal_format_i_v(
    uint32_t target, uint32_t internalformat, uint32_t pname, 
    int32_t buffer_size, int32_t* params) {
    if (nullptr == params || 0 == buffer_size) return;
    if (buffer_size > 32) {
        std::vector<GLint> buffer; buffer.resize(buffer_size);
        ::glGetInternalformativ((GLenum)target,
            (GLenum)internalformat, (GLenum)pname,
            (GLsizei)buffer_size, &(buffer[0]));
        for (int i = 0; i < buffer_size; ++i) {
            params[i] = (int32_t)buffer[i];
        }
    } else {
        GLint buffer[32] = { 0 };
        ::glGetInternalformativ((GLenum)target,
            (GLenum)internalformat, (GLenum)pname,
            (GLsizei)buffer_size, &(buffer[0]));
        for (int i = 0; i < buffer_size; ++i) {
            params[i] = (int32_t)buffer[i];
        }
    }
}