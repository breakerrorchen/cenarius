
#include "backend/es_render/connector.h"
#include "render_syncer_impl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::is_sync(render_syncer* syncer, bool* ret) {
    if (!ret) return;
    if (!syncer) { *ret = true; return; }
    auto ptr = dynamic_cast<render_syncer_impl*>(syncer);
    if (!ptr)    { *ret = true; return; }
    *ret = ::glIsSync(ptr->raw_syncer_);
}