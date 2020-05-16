
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>
#include "canvas_render_2d.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_util_tools {
public:
	static sk_sp<SkTypeface> get_default_font();
};


}}}