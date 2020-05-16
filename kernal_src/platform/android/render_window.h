
#pragma once
#include "common/base_header_inct.h"
#include "env.h"

namespace cenarius { namespace platform {
class render_window final {
public:
    render_window& operator=(const render_window&) = delete;
    render_window(const render_window&) = delete;
    render_window(ANativeWindow* window, float scale)
        : raw_window_(window), scale_(scale) {
        assert(raw_window_);
        // 这里的window是通过ANativeWindow_fromSurface获取的
        // ANativeWindow_fromSurface会增加引用计数
        if (raw_window_) {
            ::ANativeWindow_acquire(raw_window_);
        }
    }
    
    // 主要用来维护系统的NativeWindow的生命周期
    // 需要在终结的时候结束NativeWindow
    ~render_window() {
        if (nullptr != raw_window_) {
            ::ANativeWindow_release(raw_window_);
        }
    }

public:
    inline ANativeWindow* get() const { return raw_window_; }
    inline float window_scale() const { return scale_;      }
private:
    ANativeWindow* raw_window_ = nullptr; float scale_ = 1.0f;
};


}}