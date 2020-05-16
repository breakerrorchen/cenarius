
#pragma once
#include "canvas_render_2d.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class canvas_snapshot {
public:
    virtual ~canvas_snapshot() = default;
public:
    virtual sk_sp<SkImage> get_image() = 0;
};


}}}