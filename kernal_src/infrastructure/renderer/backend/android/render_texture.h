
#pragma once
#include "render_care.h"

namespace cenarius { namespace infrastructure { namespace renderer {
class render_canvas;
class render_texture final {
    friend class render_canvas;
public:
    ~render_texture();
public:
	int w() const;
	int h() const;

public:
    // read data from graphics card, rgba8 data format,
    // it is not necessary in theory to copy data from 
    // the graphics card
    bool read_buffer(std::vector<uint8_t>&);

private:
    GLuint id_ = 0; uint32_t w_ = 0, h_ = 0;
};


}}}