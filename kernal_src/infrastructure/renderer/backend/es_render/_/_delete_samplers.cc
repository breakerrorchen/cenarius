
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_samplers(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> samplers; samplers.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                samplers[i] = arr[i];
            }
            ::glDeleteSamplers((GLsizei)n, &(samplers[0]));
        } else {
            GLuint samplers[32];
            for (int32_t i = 0; i < n; ++i) {
                samplers[i] = arr[i];
            }
            ::glDeleteSamplers((GLsizei)n, &(samplers[0]));
        }
    }
}