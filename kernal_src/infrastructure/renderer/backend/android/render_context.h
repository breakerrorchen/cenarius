
#pragma once
#include "render_care.h"
#include "render_context_state.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class renderer_combined;
class render_context final
    : public std::enable_shared_from_this<render_context> {
    friend class renderer_combined;
public:
    void capture(bool with_restore = false);
    void make_current(bool _switch = true);
public:
    context_state state_;
    std::weak_ptr<renderer_combined> related_renderer_;
};


}}}