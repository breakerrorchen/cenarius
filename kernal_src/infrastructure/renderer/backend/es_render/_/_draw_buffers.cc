
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::draw_buffers(int32_t n, const uint32_t* arr) {
    if (n > 0 && nullptr != arr) {
        if (n > 32) {
            std::vector<GLenum> _enum; _enum.resize(n);
            for (int32_t i = 0; i < n; ++i) {
                _enum[i] = (GLenum)arr[i];
            }
            ::glDrawBuffers((GLsizei)n, &(_enum[0]));
        } else {
            GLenum _enum[32];
            for (int32_t i = 0; i < n; ++i) {
                _enum[i] = (GLenum)arr[i];
            }
            ::glDrawBuffers((GLsizei)n, &(_enum[0]));
        }
    }
}