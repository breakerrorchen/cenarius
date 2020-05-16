
#include "common/logger.h"
#include "render_interface_canvas_center.h"
#include "render_interface_canvas.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_interface_canvas::make_current() {
    if (_3d && _3d->impl_3d_) {
        _3d->impl_3d_->make_current();
    }

    if (_2d && _2d->impl_2d_) {
        _2d->impl_2d_->make_current();
    }
}

std::shared_ptr<canvas_render_2d> render_interface_canvas::render_2d() {
    if (_3d) return nullptr;
    if (_2d) {
        return std::dynamic_pointer_cast<canvas_render_2d>(_2d);
    }
    auto center = canvas_center_.lock();
    if (!center || !center->renderer_combined_) {
        return nullptr;
    }
    _2d = std::make_shared<render_interface_canvas_2d>();
    _2d->impl_2d_ = std::make_shared<render_canvas_2d>(
        center->renderer_combined_);
    _2d->impl_2d_->build(width_, height_);
    _2d->sk_context_ = center->renderer_combined_->sk_context_;
    return std::dynamic_pointer_cast<canvas_render_2d>(_2d);
}

std::shared_ptr<canvas_render_3d> render_interface_canvas::render_3d() {
    if (_2d) return nullptr;
    if (_3d) {
        return std::dynamic_pointer_cast<canvas_render_3d>(_3d);
    }
    auto center = canvas_center_.lock();
    if (!center || !center->renderer_combined_) {
        return nullptr;
    }
    _3d = std::make_shared<render_interface_canvas_3d>();
    _3d->impl_3d_ = std::make_shared<render_canvas_3d>(
        center->renderer_combined_);
    _3d->impl_3d_->build(width_, height_);
    _3d->related_frambuffer_id_ = _3d->impl_3d_->frame_buffer_;
    return std::dynamic_pointer_cast<canvas_render_3d>(_3d);
}

uint32_t render_interface_canvas::get_w() {
    return width_;
}

uint32_t render_interface_canvas::get_h() {
    return height_;
}

bool render_interface_canvas::is_window_related() {
    return is_related_window_;
}

bool render_interface_canvas::resize(uint32_t w, uint32_t h) {
    if (w != width_ && h != height_) {
        if (w >= 40960 || h >= 49060) {
            return false;
        }
        width_ = w; height_ = h;

        // 如果是2d渲染就重置2d渲染画布
        if (_2d && _2d->impl_2d_) {
            _2d->impl_2d_->reset_size(w, h);
        }

        // 如果是3d渲染就重置3d渲染画布
        if (_3d && _3d->impl_3d_) {
            _3d->impl_3d_->reset_size(w, h);
        }
    }
    return true;
}

std::shared_ptr<canvas_snapshot> render_interface_canvas::snapshot() {
    std::shared_ptr<render_texture> _texture;
    if (_2d && _2d->impl_2d_) {
        _texture = _2d->impl_2d_->snapshot();
    } else if (_3d && _3d->impl_3d_) {
        _texture = _3d->impl_3d_->snapshot();
    }
    if (!_texture) return nullptr;
    
    return nullptr;
}

bool render_interface_canvas::bitblt_on_window() {
    if (_2d && _2d->impl_2d_) {
        return _2d->impl_2d_->bitblt_on_window();
    }
    
    if (_3d && _3d->impl_3d_) {
        return _3d->impl_3d_->bitblt_on_window();
    }
    return false;
}