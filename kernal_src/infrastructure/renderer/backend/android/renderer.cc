
#include "renderer.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

renderer_combined::renderer_combined(const render_native_window& window)
    : framebuffer_(window) {
    if (framebuffer_.make_current()) {
        // 全局初始化opengl的参数和webgl默认的参数一样
        
        // 虚拟上下文和skia的上下文的初始化
        context_.capture(true);
        sk_interface_ = GrGLMakeNativeInterface();
        sk_context_ = GrContext::MakeGL(sk_interface_);
    } else {
        assert(false);
    }
}

renderer_combined::~renderer_combined() {
    // 所有依赖framebuffer_的对象都要在framebuffer_析构前析构
    sk_context_ = nullptr; sk_interface_ = nullptr;
}

bool renderer_combined::reset(const render_native_window& window) {
    return framebuffer_.reset(window);
}

std::shared_ptr<render_context> renderer_combined::new_context() {
    if (framebuffer_.is_useable()) {
        auto context = std::make_shared<render_context>();
        context->state_ = context_.state_;
        context->related_renderer_ = shared_from_this();
        return context;
    } else {
        return nullptr;
    }
}

std::shared_ptr<render_context> 
    renderer_combined::shared_2d_context(bool* first_created) {
    if (!shared_2d_context_) {
        if (first_created) *first_created = true ;
        shared_2d_context_ = new_context();
    } else {
        if (first_created) *first_created = false;
    }
    return shared_2d_context_;
}

void renderer_combined::make_defaut_context() {
    context_.make_current(false);
}

void renderer_combined::commit_drawable() {
	::eglSwapBuffers(framebuffer_.display(), framebuffer_.surface());
}