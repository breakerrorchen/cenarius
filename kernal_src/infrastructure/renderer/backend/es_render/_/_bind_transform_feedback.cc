
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_transform_feedback(
    uint32_t target, uint32_t _id) {
    ::glBindTransformFeedback((GLenum)target, (GLuint)_id);
}