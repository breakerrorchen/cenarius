
#include "render_framebuffer.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

static EGLDisplay g_display_ = EGL_NO_DISPLAY;
static EGLConfig  g_config_  = nullptr;
render_framebuffer::render_framebuffer(const render_native_window& window)
    : related_window_(window)  {
	// display只需要构建一次
	static std::once_flag _display_init_once_;
	std::call_once(_display_init_once_, [&]() {
		EGLint num_configs;
		g_display_ = ::eglGetDisplay(EGL_DEFAULT_DISPLAY);
		::eglInitialize(g_display_, nullptr, nullptr);
		::eglSwapInterval(g_display_, EGL_MAX_SWAP_INTERVAL);
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
		::eglChooseConfig(g_display_, attribs, &g_config_, 1, &num_configs);
	});

	assert(window.window_);
	auto& raw_window = related_window_.window_;
	// EGLint format;
    // ::eglGetConfigAttrib(
	//	g_display_, g_config_, EGL_NATIVE_VISUAL_ID, &format);
    //::ANativeWindow_setBuffersGeometry(raw_window, 0, 0, format);
    surface_ = ::eglCreateWindowSurface(
		g_display_, g_config_, raw_window, nullptr);
    ::eglQuerySurface(g_display_, surface_, EGL_WIDTH,  &w_);
    ::eglQuerySurface(g_display_, surface_, EGL_HEIGHT, &h_);
    EGLint context_attr[] = {
		EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE
	};
    context_ = ::eglCreateContext(
		g_display_, g_config_, nullptr, context_attr);
	assert(EGL_NO_CONTEXT != context_);
}

render_framebuffer::~render_framebuffer() {
    if (EGL_NO_DISPLAY != g_display_) {
		::eglMakeCurrent(g_display_,
			EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		if (EGL_NO_CONTEXT != context_) {
			::eglDestroyContext(g_display_, context_);
		}
		if (EGL_NO_SURFACE != surface_) {
			::eglDestroySurface(g_display_, surface_);
		}
		//::eglTerminate(g_display_);
	}
	context_ = EGL_NO_CONTEXT; surface_ = EGL_NO_SURFACE;
}

bool render_framebuffer::reset(const render_native_window& window) {
    if (EGL_NO_SURFACE != surface_) {
		::eglDestroySurface(g_display_, surface_);
		surface_ = EGL_NO_DISPLAY;
	}
    related_window_ = window; 
	assert(related_window_.window_);

    if (EGL_NO_SURFACE != surface_) {
        /**
		 * when reconstructing the Surface, you need to leave the current blank, 
		 * or some cell phones will appear on it.
		 * eglCreateWindowSurface: native_window_api_connect
		 * (win=0xab798928) failed (0xffffffea) (already connected to another API?)
		 * */
		::eglMakeCurrent(g_display_, 
            EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		::eglDestroySurface(g_display_, surface_);
    }
    surface_ = ::eglCreateWindowSurface(
		g_display_, g_config_, related_window_.window_, nullptr);
	assert(EGL_NO_SURFACE != surface_);
	assert(EGL_NO_CONTEXT != context_);
    ::eglQuerySurface(g_display_, surface_, EGL_WIDTH,  &w_);
	::eglQuerySurface(g_display_, surface_, EGL_HEIGHT, &h_);
	::eglMakeCurrent (g_display_, surface_, surface_, context_);

    return render_framebuffer::is_useable();
}

bool render_framebuffer::is_useable() const {
    return EGL_NO_SURFACE != surface_ 
		&& EGL_NO_CONTEXT != context_;
}

bool render_framebuffer::make_current() const {
	if (!is_useable()) return false;
	::eglMakeCurrent(g_display_, surface_, surface_, context_);
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
	return g_display_;
}

EGLSurface render_framebuffer::surface() const {
	return surface_;
}

EGLContext render_framebuffer::context() const {
	return context_;
}

EGLConfig render_framebuffer::surface_config() const {
	return g_config_;
}