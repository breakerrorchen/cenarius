
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/bestead/puppet.h"
#include "kernal/bestead/alived_token.h"
#include "../render_context_3d/_.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
using namespace asynchronous;
using namespace bestead;
enum class render_context_3d_shader_class {
	_none_, _vs_, _fs_,
};

enum class render_context_3d_shader_state {
	_none_, _deleted_, _compile_success_, _compile_fail_,
};

class render_context_3d_shader {
public:
    render_context_3d_shader();
    virtual ~render_context_3d_shader();
public:
    bool is_useable();
    bool dispose();

public:
    std::shared_ptr<alived_token<render_context_3d>> related_;
    enum __status__ { _nil_, _builded_, _deleted_ };
    __status__ status_ = _builded_;
    uint32_t* related_value_ = nullptr;
    std::shared_ptr<command_transmitter> transmitter_;
    
public:
    render_context_3d_shader_class class_ 
        = render_context_3d_shader_class::_none_;
    render_context_3d_shader_state state_ 
        = render_context_3d_shader_state::_none_;
    std::string compile_log_;
    js_value_holder shader_source_;
    
public:
    static void outlet(js_context&, js_object&);
};


}}}