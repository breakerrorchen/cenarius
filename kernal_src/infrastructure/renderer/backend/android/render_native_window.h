
#pragma once
#include "render_care.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_framebuffer;
class render_native_window final {
    friend class render_framebuffer;
public:
    render_native_window() = default;
    render_native_window(ANativeWindow*, float);
    render_native_window(const render_native_window&);
    render_native_window(render_native_window&&);
    render_native_window& operator=(const render_native_window&);
    render_native_window& operator=(render_native_window&&);
    ~render_native_window();

public:
    float w()     const;
    float h()     const;
    float scale() const;

private:
    ANativeWindow* window_ = nullptr; float scale_ = 1.0f;
};


}}}