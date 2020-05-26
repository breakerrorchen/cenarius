
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_transform_feedback_varying(
    uint32_t program, uint32_t index, int32_t buffer_size, 
    int32_t* length, int32_t* size, uint32_t* type, char* name) {
    if (0 >= buffer_size || !name) return;
    GLsizei ret_len = 0, ret_size = 0; GLenum ret_type = 0;
    ::glGetTransformFeedbackVarying((GLuint)program,
        (GLuint)index, (GLsizei)buffer_size, &ret_len,
        &ret_size, &ret_type, name);
    if (length) *length = (int32_t) ret_len ;
    if (size)   *size   = (int32_t) ret_size;
    if (type)   *type   = (uint32_t)ret_type;
}