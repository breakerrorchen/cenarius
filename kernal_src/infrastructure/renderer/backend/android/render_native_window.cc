
#include "render_native_window.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

render_native_window::render_native_window(
    ANativeWindow* window, float scale) {
    window_ = window; scale_ = scale;
    if (window_) {
        ::ANativeWindow_acquire(window_);
    }
}

render_native_window::render_native_window(
    const render_native_window& from) {
    operator=(from);
}

render_native_window::render_native_window(
    render_native_window&& from) {
    operator=(std::move(from));
}

render_native_window& render_native_window::operator=(
    const render_native_window& from) {
    if (this != &from) {
        if (window_) {
            ::ANativeWindow_release(window_); window_ = nullptr;
        }
        window_ = from.window_; scale_ = from.scale_;
        if (window_) {
            ::ANativeWindow_acquire(window_);
        }
    }
    return *this;
}

render_native_window& render_native_window::operator=(
    render_native_window&& from) {
    if (this != &from) {
        if (window_) {
            ::ANativeWindow_release(window_); window_ = nullptr;
        }
        window_ = from.window_; scale_ = from.scale_;
        from.window_ = nullptr; from.scale_ = 1.0f;
    }
    return *this;
}

render_native_window::~render_native_window() {
    if (window_) {
        ::ANativeWindow_release(window_);
    }
}

float render_native_window::w() const {
    if (window_) {
        return ::ANativeWindow_getWidth(window_);
    }
    return 0;
}

float render_native_window::h() const {
    if (window_) {
        return ::ANativeWindow_getHeight(window_);
    }
    return 0;
}

float render_native_window::scale() const { return scale_; }