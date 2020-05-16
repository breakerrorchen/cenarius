
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"
#include "render_context_attrib_pointer.h"
#include "render_constants.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
class render_context_3d_buffer;
class render_context_3d_framebuffer;
class render_context_3d_renderbuffer;
class render_context_3d_texture;
class render_context_3d_program;
class render_context_3d_context_local {
public:
    /**
     * The WebGLRenderingContext.enable() method of the 
     * WebGL API enables specific WebGL capabilities for this context.
     */
    bool enable_blend_                      = true;
    bool enable_cull_face_                  = true;
    bool enable_depth_test_                 = true;
    bool enable_dither_                     = true;
    bool enable_polygon_offset_fill_        = true;
    bool enable_sample_alpha_to_coverage_   = true;
    bool enable_coverage_                   = true;
    bool enable_scissor_test_               = true;
    bool enable_stencil_test_               = true;

    /**
     * The WebGLRenderingContext.sampleCoverage() method of the WebGL 
     * API specifies multi-sample coverage parameters for anti-aliasing effects.
     */
    float sample_coverage_value_ = 1.0f; bool sample_coverage_invert_ = false;

    /**
     * The WebGLRenderingContext.pixelStorei() 
     * method of the WebGL API specifies the pixel storage modes.
     */
    uint32_t pack_alignment_ = 4, unpack_alignment_ = 4; // 1,2,4,8
    bool unpack_premu_alpha_webgl_ = false;
    bool unpack_filp_y_webgl_      = false; 

    /**
     * The WebGLRenderingContext.lineWidth() 
     * method of the WebGL API sets the line width of rasterized lines.
     */
    float line_width_ = 1.0f;

    /**
     * The WebGLRenderingContext.polygonOffset() method of the 
     * WebGL API specifies the scale factors and units to calculate depth values.
     *
     * The offset is added before the depth test is 
     * performed and before the value is written into the depth buffer.
     */
    float polygon_offset_factor_ = 0, polygon_offset_units_ = 0;

    /**
     * The WebGLRenderingContext.stencilFunc() method of the 
     * WebGL API sets the front and back function and reference value for stencil testing.
     *
     * Stencilling enables and disables drawing on a per-pixel basis. 
     * It is typically used in multipass rendering to achieve special effects.
     */
    uint32_t front_face_stencil_func_       = DWL_ALWAYS;
    int front_face_stencil_func_ref_        = 0;
    uint32_t front_face_stencil_func_mask_  = 1;
    uint32_t back_face_stencil_func_        = DWL_ALWAYS;
    int back_face_stencil_func_ref_         = 0;
    uint32_t back_face_stencil_func_mask_   = 1;

    /**
     * The WebGLRenderingContext.stencilMask() method of the WebGL API controls enabling 
     * and disabling of both the front and back writing of individual bits in the stencil planes.
     *
     * The WebGLRenderingContext.stencilMaskSeparate() 
     * method can set front and back stencil writemasks to different values.
     */
    uint32_t stencil_write_mask_ = 1, stencil_back_write_mask_ = 1;

    /**
     * The WebGLRenderingContext.stencilOp() method of the 
     * WebGL API sets both the front and back-facing stencil test actions.
     */
    uint32_t front_stencil_op_fail_     = DWL_KEEP;
    uint32_t front_stencil_op_z_fail_   = DWL_KEEP;
    uint32_t front_stencil_op_z_pass_   = DWL_KEEP;
    uint32_t back_stencil_op_fail_      = DWL_KEEP;
    uint32_t back_stencil_op_z_fail_    = DWL_KEEP;
    uint32_t back_stencil_op_z_pass_    = DWL_KEEP;

    /**
     * The WebGLRenderingContext.blendColor() method of the WebGL API is 
     * used to set the source and destination blending factors.
     */
    float blend_color_[4] = {0, 0, 0, 0};

    /**
     * This specifies what color values to use when calling the clear() method. 
     * The values are clamped between 0 and 1
     */
    float clear_color_[4] = {0, 0, 0, 0};

    /**
     * This specifies what color values to use when calling the clear() method. 
     * The values are clamped between 0 and 1
     */
    float clear_depth_value_ = 1.0f;

    /**
     * This specifies what stencil value to use when calling the clear() method.
     */
    float clear_stencil_value_ = 0;

    /**
     * The WebGLRenderingContext.activeTexture() method of the WebGL API specifies 
     * which texture unit to make active.
     * The texture unit to make active. 
     * The value is a gl.TEXTUREI where I is within the range from 
     * 0 to gl.MAX_COMBINED_TEXTURE_IMAGE_UNITS - 1
     */
    uint32_t ative_texture_ = DWL_TEXTURE0;

    /**
     * The blend equation determines how a new pixel is 
     * combined with a pixel already in the WebGLFramebuffer.
     */
    uint32_t blend_equation_rgb_mode_   = DWL_FUNC_ADD;
    uint32_t blend_equation_alpha_mode_ = DWL_FUNC_ADD;
    uint32_t blend_func_src_rgb_        = DWL_ONE;
    uint32_t blend_func_src_alpha_      = DWL_ONE;
    uint32_t blend_func_dst_rgb_        = DWL_ZERO;
    uint32_t blend_func_dst_alpha_      = DWL_ONE;

    /**
     * The WebGLRenderingContext.colorMask() method of the WebGL API sets which color 
     * components to enable or to disable when drawing or rendering to a WebGLFramebuffer.
     */
    bool color_write_mask_[4] = {true, true, true, true};

    /**
     * The WebGLRenderingContext.cullFace() method of the WebGL API specifies 
     * whether or not front- and/or back-facing polygons can be culled.
     */
    uint32_t cull_face_mode_ = DWL_BACK;

    /**
     * The WebGLRenderingContext.frontFace() method of the WebGL API specifies 
     * whether polygons are front- or back-facing by setting a winding orientation.
     */
    uint32_t front_face_ = DWL_CCW;

    /**
     * The WebGLRenderingContext.depthFunc() method of the WebGL API specifies a function 
     * that compares incoming pixel depth to the current depth buffer value.
     */
    uint32_t depth_func_ = DWL_LESS;

    /**
     * The WebGLRenderingContext.depthMask() method of the WebGL API sets 
     * whether writing into the depth buffer is enabled or disabled.
     */
    bool depth_mask_ = true;

    /**
     * GENERATE_MIPMAP_HINT: Quality of filtering when 
     * generating mipmap images with WebGLRenderingContext.generateMipmap().
     */
    uint32_t generate_mipmap_hint_ = DWL_DONT_CARE;

    /**
     * The WebGLRenderingContext.depthRange() method of the WebGL API specifies the depth 
     * range mapping from normalized device coordinates to window or viewport coordinates.
     */
    float depth_range_[2] = {0.0f, 1.0f};

    /**
     * The WebGLRenderingContext.bindBuffer() method of the WebGL API binds a given 
     * WebGLBuffer to a target.
     * must have the same life cycle
     */
    js_value_holder arraybuffer_bind_;
    render_context_3d_buffer* raw_arraybuffer_bind_ = nullptr;
    js_value_holder element_arraybuffer_bind_;
    render_context_3d_buffer* raw_element_arraybuffer_bind_ = nullptr;

    /**
     * The WebGLRenderingContext.bindFramebuffer() method of the WebGL API 
     * binds a given WebGLFramebuffer to a target.
     * must have the same life cycle
     */
    js_value_holder framebuffer_bind_;
    render_context_3d_framebuffer* raw_framebuffer_bind_ = nullptr;

    /**
     * The WebGLRenderingContext.bindRenderbuffer() method of the WebGL API 
     * binds a given WebGLRenderbuffer to a target, which must be gl.RENDERBUFFER.
     * must have the same life cycle
     */
    js_value_holder renderbuffer_bind_;
    render_context_3d_renderbuffer* raw_renderbuffer_bind_ = nullptr;

    /**
     * The WebGLRenderingContext.bindTexture() method of the WebGL API 
     * binds a given WebGLTexture to a target (binding point).
     * must have the same life cycle
     */
    js_value_holder texture_2d_bind_;
    render_context_3d_texture* raw_texture_2d_bind_ = nullptr;
    js_value_holder texture_cube_bind_;
    render_context_3d_texture* raw_texture_cube_bind_ = nullptr;

    /**
     * The WebGLRenderingContext.useProgram() method of the WebGL API 
     * sets the specified WebGLProgram as part of the current rendering state.
     * must have the same life cycle
     */
    js_value_holder current_program_;
    render_context_3d_program* raw_current_program_ = nullptr;

    /**
     * In WebGL, values that apply to a specific vertex are stored in attributes. 
     * These are only available to the JavaScript code and the vertex shader. 
     * Attributes are referenced by an index number into the list of attributes 
     * maintained by the GPU. Some vertex attribute indices may have predefined 
     * purposes, depending on the platform and/or the GPU. Others are assigned 
     * by the WebGL layer when you create the attributes.
     *
     * Either way, since attributes cannot be used unless enabled, and are 
     * disabled by default, you need to call enableVertexAttribArray() to enable 
     * individual attributes so that they can be used. Once that's been done, 
     * other methods can be used to access the attribute, 
     * including vertexAttribPointer(), vertexAttrib*(), and getVertexAttrib().
     */
    render_context_attrib_pointer attrib_pointer_[64];

    /**
     * The WebGLRenderingContext.scissor() method of the WebGL API sets a scissor box, 
     * which limits the drawing to a specified rectangle.
     */
    int scissor_[4] = {0, 0, -1, -1};

    /**
     * The WebGLRenderingContext.viewport() method of the WebGL API sets the viewport, 
     * which specifies the affine transformation of x and y 
     * from normalized device coordinates to window coordinates.
     */
    int viewport_[4] = {0, 0, -1, -1};
};


}}}