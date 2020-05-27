
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::wait_sync(
    render_syncer* syncer, uint32_t flags, uint64_t timeout) {
    if (!syncer) return;
    auto ptr = dynamic_cast<render_syncer_impl*>(syncer);
    if (!ptr)    return;
    ::glWaitSync(ptr->raw_syncer_, 
        (GLbitfield)flags, (GLuint64)timeout);
}