
#include "backend/es_render/connector.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;

void render_connector::link_program(uint32_t index, shader_reflection* env) {
    ::glLinkProgram((GLuint)index); if (nullptr == env) return;
    GLint ret_params = GL_TRUE;
    ::glGetProgramiv((GLuint)index, GL_LINK_STATUS, &ret_params);
    env->is_success_  = (GL_TRUE == ret_params);
    env->is_linked_   = true;
    env->is_validate_ = false;
    
    if (!env->is_success_) {
        GLchar error_log[512] = {0}; GLint size = 512;
        ::glGetProgramInfoLog((GLuint)index, 512, &size, error_log);
        env->program_info_.append((char*)error_log, size);
        return;
    }
    const GLsizei buffer_size = 256; GLchar name_buffer[buffer_size] = {0};

    // active attribute variables for program
    ::glGetProgramiv((GLuint)index, GL_ACTIVE_ATTRIBUTES, &ret_params);
    if (ret_params > 0) {
        env->attribs_.resize((size_t)ret_params);
        GLsizei length = 0; GLint size = 0; GLenum type = 0;
        for (GLint i = 0; i < ret_params; ++i) {
           ::glGetActiveAttrib((GLuint)index, i, 
                buffer_size, &length, &size, &type, &name_buffer[0]);
            std::string attrib_name(&name_buffer[0], (size_t)length);
            GLint attrib_location_id = ::glGetAttribLocation(
                (GLuint)index, attrib_name.c_str());
            auto& item = env->attribs_[i];
            item.name_ = std::move(attrib_name);
            item.type_ = type; 
            item.size_ = size;
            item.location_index_ = attrib_location_id;
        }
    } else {
        env->attribs_.clear();
    }

    // active uniform variable in the program object specified by program
    ::glGetProgramiv((GLuint)index, GL_ACTIVE_UNIFORMS, &ret_params);
    if (ret_params > 0) {
        env->active_uniforms_.resize((size_t)ret_params);
        for (GLint i = 0; i < ret_params; ++i) {
            GLsizei name_length; GLint uniform_size; GLenum uniform_type;
            ::glGetActiveUniform(
                (GLuint)index, (GLuint)i, buffer_size, &name_length, 
                &uniform_size, &uniform_type, &name_buffer[0]);
            if (0 == name_length) continue;
            std::string uniform_name(&name_buffer[0], (size_t)name_length);
            GLint uniform_location_id =::glGetUniformLocation(
                (GLuint)index, uniform_name.c_str());
            if (uniform_location_id < 0) continue;

            auto& item = env->active_uniforms_[i];
            item.location_index_ = uniform_location_id;
            item.name_           = uniform_name;
            item.type_           = uniform_type;
            item.size_           = uniform_size;
            if (uniform_name[name_length - 1] == ']') {
                for (int i = name_length - 2; i >= 0; --i) {
                    if ('[' == uniform_name[i]) {
                        uniform_name.resize(i);
                        break;
                    }
                }
            }
            if (1 == uniform_size) continue;
            
            // 如果是数组和 arr[0] 和 arr 代表同一个数据
            // 这里存储的arr
            for (int index = 0; index < uniform_size; ++index) {
                std::string name(uniform_name);
                if (index != 0) {
                    std::stringstream ss(name);
                    ss << "[" << index << "]"; name = ss.str();
                }
                uniform_location_id = ::glGetUniformLocation(
                    (GLuint)index, name.c_str());
                if (uniform_location_id < 0) continue;
                shader_uniform uniform_item;
                uniform_item.name_           = std::move(name);
                uniform_item.type_           = uniform_type;
                uniform_item.size_           = 1;
                uniform_item.location_index_ = uniform_location_id;
                env->uniforms_.push_back(uniform_item);
            }
        }
    } else {
        env->uniforms_.clear(); env->active_uniforms_.clear();
    }
}