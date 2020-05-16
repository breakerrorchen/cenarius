
#pragma once
#include "render_care.h"

namespace cenarius { namespace infrastructure { namespace renderer {
template<typename cls> class render_canvas_indolent final {
public:
    template<typename...args_t>
    render_canvas_indolent(args_t&&... args) {
        inner_data_ = std::make_shared<cls>(
            std::forward<args_t>(args)...);
        ;
    }

public:
    inline std::shared_ptr<cls> get() {
        if (inner_data_ && (inner_data_->width_ != w_ 
                || inner_data_->height_ != h_)) {
            inner_data_->reset_size(w_, h_, aa_);
        }
        return inner_data_;
    }

public:
    inline bool reset_size(int w, int h, int aa = 0) {
        w_ = w; h_ = h; aa_ = aa;
        return true;
    }

private:
    int w_ = 0, h_ = 0, aa_ = 0; std::shared_ptr<cls> inner_data_;
};


}}}