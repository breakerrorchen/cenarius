
#include "../render_context_3d_program/_.h"
#include "../render_context_3d_uniform_location/_.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

/**
 * Syntax
 *      any gl.getUniform(program, location);
 *
 * program
 *      A WebGLProgram containing the uniform attribute.
 *
 * location
 *      A WebGLUniformLocation object 
 *      containing the location of the uniform attribute to get.
 * 
 * Return value
 *      WebGL 1 only
 *      boolean	            GLBoolean
 *      int                 GLint
 *      float               GLfloat
 *      vec2                Float32Array (with 2 elements)
 *      ivec2               Int32Array (with 2 elements)
 *      bvec2	            Array of GLBoolean (with 2 elements)
 *      vec3                Float32Array (with 3 elements)
 *      ivec3	            Int32Array (with 3 elements)
 *      bvec3               Array of GLBoolean (with 3 elements)
 *      vec4                Float32Array (with 4 elements)
 *      ivec4	            Int32Array (with 4 elements)
 *      bvec4	            Array of GLBoolean (with 4 elements)
 *      mat2                Float32Array (with 4 elements)
 *      mat3                Float32Array (with 9 elements)
 *      mat4	            Float32Array (with 16 elements)
 *      sampler2D           GLint
 *      samplerCube         GLint
 * 
 *      Additionally available in WebGL 2
 *      uint	            GLuint
 *      uvec2	            Uint32Array (with 2 elements)
 *      uvec3	            Uint32Array (with 3 elements)
 *      uvec4	            Uint32Array (with 4 elements)
 *      mat2x3	            Float32Array (with 6 elements)
 *      mat2x4	            Float32Array (with 8 elements)
 *      mat3x2	            Float32Array (with 6 elements)
 *      mat3x4  	        Float32Array (with 12 elements)
 *      mat4x2	            Float32Array (with 8 elements)
 *      mat4x3	            Float32Array (with 12 elements)
 *      any sampler type	GLint
 */
void render_context_3d::get_uniform(js_parameter& _parameter) {
    
}