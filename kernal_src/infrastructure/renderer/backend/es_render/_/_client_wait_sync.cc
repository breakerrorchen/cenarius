
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::client_wait_sync(render_syncer* syncer, 
    uint32_t flags, uint64_t timeout, uint32_t* ret) {
    auto ptr = dynamic_cast<render_syncer_impl*>(syncer);
    if (!ptr || !ret) return;
    *ret = (uint32_t)::glClientWaitSync(
        ptr->raw_syncer_, (GLbitfield)flags, (GLuint64)timeout);
}