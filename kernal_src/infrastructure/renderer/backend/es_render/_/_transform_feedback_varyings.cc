
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::transform_feedback_varyings(
    uint32_t program, int32_t count,
    const char** varyings, uint32_t buffer_mode) {
    ::glTransformFeedbackVaryings((GLuint)program,
        (GLsizei)count, varyings, buffer_mode);
}