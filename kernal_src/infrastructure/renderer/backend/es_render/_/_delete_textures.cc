
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_textures(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLuint> buffers; buffers.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                buffers[i] = arr[i];
            }
            ::glDeleteTextures((GLsizei)n, &(buffers[0]));
        } else {
            GLuint buffers[32] = { 0 };
            for (int32_t i = 0; i < n; ++i) {
                buffers[i] = arr[i];
            }
            ::glDeleteTextures((GLsizei)n, &(buffers[0]));
        }
    }
}