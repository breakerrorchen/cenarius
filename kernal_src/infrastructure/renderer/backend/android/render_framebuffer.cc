
#include "render_framebuffer.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

render_framebuffer::render_framebuffer(const render_native_window& window)
    : related_window_(window)  {
    assert(window.window_);
    auto& raw_window = related_window_.window_;
    display_ = ::eglGetDisplay(EGL_DEFAULT_DISPLAY);
	::eglInitialize(display_, nullptr, nullptr);
    ::eglSwapInterval(display_, 0);
    EGLint attribs[] = {
        EGL_SURFACE_TYPE,   	EGL_WINDOW_BIT,
		EGL_RED_SIZE,       	8,
		EGL_GREEN_SIZE,     	8,
		EGL_BLUE_SIZE,      	8,
		EGL_ALPHA_SIZE,     	8,
#if defined(__target_framebuffer_with_depth_stencil__)
		EGL_DEPTH_SIZE,     	24,
		EGL_STENCIL_SIZE,   	8,
#endif 
        EGL_NONE
    };

    EGLint num_configs; EGLint format;
	::eglChooseConfig(display_, attribs, &config_, 1, &num_configs);
    ::eglGetConfigAttrib(display_, config_, EGL_NATIVE_VISUAL_ID, &format);
    ::ANativeWindow_setBuffersGeometry(raw_window, 0, 0, format);
    surface_ = ::eglCreateWindowSurface(display_, config_, raw_window, nullptr);
    ::eglQuerySurface(display_, surface_, EGL_WIDTH,  &w_);
    ::eglQuerySurface(display_, surface_, EGL_HEIGHT, &h_);
    EGLint context_attr[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    context_ = ::eglCreateContext(display_, config_, nullptr, context_attr);
}

render_framebuffer::~render_framebuffer() {
    if (EGL_NO_DISPLAY != display_) {
		::eglMakeCurrent(display_,
			EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		if (EGL_NO_CONTEXT != context_) {
			::eglDestroyContext(display_, context_);
		}
		if (EGL_NO_SURFACE != surface_) {
			::eglDestroySurface(display_, surface_);
		}
		::eglTerminate(display_);
	}

    display_ = EGL_NO_DISPLAY;
	context_ = EGL_NO_CONTEXT;
	surface_ = EGL_NO_SURFACE;
}

bool render_framebuffer::reset(const render_native_window& window) {
    if (EGL_NO_SURFACE != surface_) {
		::eglDestroySurface(display_, surface_);
		surface_ = EGL_NO_DISPLAY;
	}
    related_window_ = window;
    if (nullptr == related_window_.window_) {
		return false;
	}

    if (EGL_NO_SURFACE != surface_) {
        /**
		 * when reconstructing the Surface, you need to leave the current blank, 
		 * or some cell phones will appear on it.
		 * eglCreateWindowSurface: native_window_api_connect
		 * (win=0xab798928) failed (0xffffffea) (already connected to another API?)
		 * */
		::eglMakeCurrent(display_, 
            EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		::eglDestroySurface(display_, surface_);
    }
    surface_ = ::eglCreateWindowSurface(
		display_, config_, related_window_.window_, nullptr);
    if (EGL_NO_SURFACE == surface_) { 
    	return false; 
   	}
    ::eglQuerySurface(display_, surface_, EGL_WIDTH,  &w_);
	::eglQuerySurface(display_, surface_, EGL_HEIGHT, &h_);

    return render_framebuffer::is_useable();
}

bool render_framebuffer::is_useable() const {
    return EGL_NO_SURFACE != surface_ 
		&& EGL_NO_DISPLAY != display_
		&& EGL_NO_CONTEXT != context_;
}

bool render_framebuffer::make_current() const {
	if (!is_useable()) return false;
	::eglMakeCurrent(display_, surface_, surface_, context_);
	return true;
}

int render_framebuffer::w() const {
    return w_;
}

int render_framebuffer::h() const {
    return h_;
}

GLuint render_framebuffer::display_framebuffer() const {
    return 0;
}

EGLDisplay render_framebuffer::display() const {
	return display_;
}

EGLSurface render_framebuffer::surface() const {
	return surface_;
}

EGLContext render_framebuffer::context() const {
	return context_;
}

EGLConfig render_framebuffer::surface_config() const {
	return config_;
}