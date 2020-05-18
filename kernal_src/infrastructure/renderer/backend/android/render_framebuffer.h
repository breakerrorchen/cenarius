
#pragma once
#include "render_care.h"
#include "render_native_window.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_framebuffer final {
public:
    render_framebuffer(const render_native_window&);
    ~render_framebuffer();
public:
    bool reset(const render_native_window&);
    bool is_useable() const;
    bool make_current() const;

public:
    GLuint     display_framebuffer() const;
    EGLDisplay display() const;
	EGLSurface surface() const;
	EGLContext context() const;
	EGLConfig  surface_config() const;   
    
public:
	int w() const;
	int h() const;

private:
    EGLint w_ = 0, h_ = 0;
    EGLSurface surface_ = EGL_NO_SURFACE;
    EGLContext context_ = EGL_NO_CONTEXT;

private:
    render_native_window related_window_;
};


}}}