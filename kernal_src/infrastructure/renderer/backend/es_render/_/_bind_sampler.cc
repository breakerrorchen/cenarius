
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::bind_sampler(
    uint32_t texture_id, uint32_t sampler) {
    ::glBindSampler((GLuint)texture_id, (GLuint)sampler);
}