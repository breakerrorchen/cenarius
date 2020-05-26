
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::delete_sync(render_syncer* syncer) {
    auto ptr = dynamic_cast<render_syncer_impl*>(syncer);
    if (!ptr) return;
    ::glDeleteSync(ptr->raw_syncer_);
}