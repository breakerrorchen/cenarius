
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::pause_transform_feedback() {
    ::glPauseTransformFeedback();
}