
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::get_sync_i_v(render_syncer* syncer, 
    uint32_t pname, int32_t buffer_size, int32_t* length, 
    int32_t* values) {
    auto ptr = dynamic_cast<render_syncer_impl*>(syncer);
    if (0 >= buffer_size || !values || !ptr) return;
    if (buffer_size > 32) {
        std::vector<GLint> _0; _0.resize(buffer_size);
        GLsizei ret_len = 0;
        ::glGetSynciv(ptr->raw_syncer_, (GLenum)pname,
            (GLsizei)buffer_size, &ret_len, &(_0[0]));
        for (int i = 0; i < buffer_size; ++i) {
            values[i] = (int32_t)_0[i];
        }
        if (length) { *length = (int32_t)ret_len; }
    } else {
        GLint _0[32] = { 0 }; GLsizei ret_len = 0;
        ::glGetSynciv(ptr->raw_syncer_, (GLenum)pname,
            (GLsizei)buffer_size, &ret_len, &(_0[0]));
        for (int i = 0; i < buffer_size; ++i) {
            values[i] = (int32_t)_0[i];
        }
        if (length) { *length = (int32_t)ret_len; }
    }
}