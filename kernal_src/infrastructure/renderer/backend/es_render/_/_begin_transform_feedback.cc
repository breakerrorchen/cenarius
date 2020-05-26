
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::begin_transform_feedback(uint32_t mode) {
    ::glBeginTransformFeedback((GLenum)(mode));
}