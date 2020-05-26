
#pragma once
#include "backend/es_render/syncer.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_syncer_impl: public render_syncer {
public:
    GLsync raw_syncer_;
public:
    static inline std::shared_ptr<render_syncer> build() {
        auto _i = std::make_shared<render_syncer_impl>();
        return std::dynamic_pointer_cast<render_syncer>(_i);
    }
};


}}}