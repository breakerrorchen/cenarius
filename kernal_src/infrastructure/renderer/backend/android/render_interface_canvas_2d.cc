
#include "render_interface_canvas_2d.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_interface_canvas_2d::test() {
	auto _canvas = render_interface_canvas_2d::get();
	_canvas->drawColor(SK_ColorWHITE);
}

SkCanvas* render_interface_canvas_2d::get() {
    if (impl_2d_) {
        return impl_2d_->get_canvas();
    }
    return nullptr;
}