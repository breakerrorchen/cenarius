
#include "common/logger.h"
#include "render_interface_canvas_center.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_attitude_init(render_attitude& attitude) {
    GLint a_bits = 8, r_bits = 8, b_bits = 8, g_bits = 8, d_bits = 8, s_bits = 8;
    ::glGetIntegerv(GL_ALPHA_BITS,  &a_bits); attitude.alpha_bits_  = (uint32_t)a_bits;
    ::glGetIntegerv(GL_BLUE_BITS,   &b_bits); attitude.blue_bits_   = (uint32_t)b_bits;
    ::glGetIntegerv(GL_RED_BITS,    &r_bits); attitude.red_bits_    = (uint32_t)r_bits;
    ::glGetIntegerv(GL_GREEN_BITS,  &g_bits); attitude.green_bits_  = (uint32_t)g_bits;
    ::glGetIntegerv(GL_DEPTH_BITS,  &d_bits); attitude.depth_bits_  = (uint32_t)d_bits;
    ::glGetIntegerv(GL_STENCIL_BITS,&s_bits); attitude.stencil_bits_= (uint32_t)s_bits;

    GLint max_3d_texture_size = 256;
    ::glGetIntegerv(GL_MAX_3D_TEXTURE_SIZE, &max_3d_texture_size);
    attitude.max_3d_texture_size_ = max_3d_texture_size;
    GLint max_array_texture_layers = 256;
    ::glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, &max_array_texture_layers);
    attitude.max_array_texture_layers_ = max_array_texture_layers;
    GLint aliased_line_width_range[2] = {0, 0};
    ::glGetIntegerv(GL_ALIASED_LINE_WIDTH_RANGE, aliased_line_width_range);
    attitude.aliased_line_width_range_[0] = aliased_line_width_range[0];
    attitude.aliased_line_width_range_[1] = aliased_line_width_range[1];
    GLint aliased_point_size_range[2] = {0, 0};
    ::glGetIntegerv(GL_ALIASED_POINT_SIZE_RANGE, aliased_point_size_range);
    attitude.aliased_point_size_range_[0] = aliased_point_size_range[0];
    attitude.aliased_point_size_range_[1] = aliased_point_size_range[1];
    GLint max_combined_texture_image_units = 0;
    ::glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
        &max_combined_texture_image_units);
    attitude.max_combined_texture_image_units_ = max_combined_texture_image_units;
    GLint max_cube_map_texture_size = 2048;
    ::glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, &max_cube_map_texture_size);
    attitude.max_cube_map_texture_size_ = max_cube_map_texture_size;
    GLint max_fragment_uniform_vectors = 224;
    ::glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, &max_fragment_uniform_vectors);
    attitude.max_fragment_uniform_vectors_ = max_fragment_uniform_vectors;
    GLint max_texture_image_units = 16;
    ::glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &max_texture_image_units);
    attitude.max_texture_image_units_ = max_texture_image_units;
    GLint texture_max_size = 0;
    ::glGetIntegerv(GL_MAX_TEXTURE_SIZE, &texture_max_size);
    attitude.max_texture_size_ = texture_max_size; 
    GLint renderbuffer_max_size = 0;
    ::glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &renderbuffer_max_size);
    attitude.max_renderbuffer_size_ = renderbuffer_max_size; 
    GLint max_varying_vectors = 15;
    ::glGetIntegerv(GL_MAX_VARYING_VECTORS, &max_varying_vectors);
    attitude.max_varying_vectors_ = max_varying_vectors;
    GLint max_vertex_attribs = 16;
    ::glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max_vertex_attribs);
    attitude.max_vertex_attribs_ = max_vertex_attribs;
    GLint max_vertex_texture_image_units = 16;
    ::glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &max_vertex_texture_image_units);
    attitude.max_vertex_texture_image_units_ = max_vertex_texture_image_units;
    GLint max_vertex_uniform_vectors = 256;
    ::glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, &max_vertex_uniform_vectors);
    attitude.max_vertex_uniform_vectors_ = max_vertex_uniform_vectors;
    GLint viewport_max_size[2] = {0, 0};
    ::glGetIntegerv(GL_MAX_VIEWPORT_DIMS, viewport_max_size);
    attitude.max_viewport_size_[0] = viewport_max_size[0]; 
    attitude.max_viewport_size_[1] = viewport_max_size[1];
    GLint subpixel_bits = 4;
    ::glGetIntegerv(GL_SUBPIXEL_BITS, &subpixel_bits);
    attitude.subpixel_bits_ = subpixel_bits;
    GLint range[2] = {0, 0}, precision = 0;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_LOW_FLOAT, range, &precision);
    auto& vs_l_f = attitude.vs_l_f_;
    vs_l_f.range_min_ = range[0]; vs_l_f.range_max_ = range[1]; vs_l_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_MEDIUM_FLOAT, range, &precision);
    auto& vs_m_f = attitude.vs_m_f_;
    vs_m_f.range_min_ = range[0]; vs_m_f.range_max_ = range[1]; vs_m_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_HIGH_FLOAT, range, &precision);
    auto& vs_h_f = attitude.vs_h_f_;
    vs_h_f.range_min_ = range[0]; vs_h_f.range_max_ = range[1]; vs_h_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_LOW_INT, range, &precision);
    auto& vs_l_i = attitude.vs_l_i_;
    vs_l_i.range_min_ = range[0]; vs_l_i.range_max_ = range[1]; vs_l_i.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_MEDIUM_INT, range, &precision);
    auto& vs_m_i = attitude.vs_m_i_;
    vs_m_i.range_min_ = range[0]; vs_m_i.range_max_ = range[1]; vs_m_i.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_VERTEX_SHADER, GL_HIGH_INT, range, &precision);
    auto& vs_h_i = attitude.vs_h_i_;
    vs_h_i.range_min_ = range[0]; vs_h_i.range_max_ = range[1]; vs_h_i.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_LOW_FLOAT, range, &precision);
    auto& fs_l_f = attitude.fs_l_f_;
    fs_l_f.range_min_ = range[0]; fs_l_f.range_max_ = range[1]; fs_l_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_MEDIUM_FLOAT, range, &precision);
    auto& fs_m_f = attitude.fs_m_f_;
    fs_m_f.range_min_ = range[0]; fs_m_f.range_max_ = range[1]; fs_m_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_HIGH_FLOAT, range, &precision);
    auto& fs_h_f = attitude.fs_h_f_;
    fs_h_f.range_min_ = range[0]; fs_h_f.range_max_ = range[1]; fs_h_f.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_LOW_INT, range, &precision);
    auto& fs_l_i = attitude.fs_l_i_;
    fs_l_i.range_min_ = range[0]; fs_l_i.range_max_ = range[1]; fs_l_i.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_MEDIUM_INT, range, &precision);
    auto& fs_m_i = attitude.fs_m_i_;
    fs_m_i.range_min_ = range[0]; fs_m_i.range_max_ = range[1]; fs_m_i.range_max_ = precision;
    ::glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_HIGH_INT, range, &precision);
    auto& fs_h_i = attitude.fs_h_i_;
    fs_h_i.range_min_ = range[0]; fs_h_i.range_max_ = range[1]; fs_h_i.range_max_ = precision;
}

render_interface_canvas_center::render_interface_canvas_center() {
    render_attitude_init(render_attitude_);
}

void render_interface_canvas_center::get_hardware_attitude(
    render_attitude* ret) {
    if (nullptr != ret) {
        *ret = render_attitude_;
    }
}

std::shared_ptr<canvas> render_interface_canvas_center::related_window() {
    if (!renderer_combined_) return nullptr;
    if (window_canvas_) {
        return std::dynamic_pointer_cast<canvas>(window_canvas_);
    }
    auto w = renderer_combined_->get_window_width() ;
    auto h = renderer_combined_->get_window_height();
    window_canvas_ = std::make_shared<render_interface_canvas>();
    window_canvas_->width_ = w; window_canvas_->height_ = h;
    window_canvas_->is_related_window_ = true;
    window_canvas_->canvas_center_ = shared_from_this();
    return std::dynamic_pointer_cast<canvas>(window_canvas_);
}

std::shared_ptr<canvas> render_interface_canvas_center::create() {
    if (!renderer_combined_) return nullptr;
    auto w = renderer_combined_->get_window_width ();
    auto h = renderer_combined_->get_window_height();
    return render_interface_canvas_center::create(w, h);
}

std::shared_ptr<canvas> render_interface_canvas_center::create(
    uint32_t width, uint32_t height) {
    if (!renderer_combined_) return nullptr;
    if (width >= 40960 || height >= 40960) return nullptr;
    auto _canvas = std::make_shared<render_interface_canvas>();
    _canvas->width_ = width; _canvas->height_ = height;
    _canvas->canvas_center_ = shared_from_this();
    return std::dynamic_pointer_cast<canvas>(_canvas);
}

void render_interface_canvas_center::commit_drawable() {
    if (window_canvas_) {
        window_canvas_->bitblt_on_window();
    }
    
    // 交换硬件前后frame
    if (renderer_combined_) {
        renderer_combined_->commit_drawable();
    }
}