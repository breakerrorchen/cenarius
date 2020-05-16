
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/bestead/puppet.h"
#include "kernal/bestead/alived_token.h"
#include "../render_context_3d/_.h"
#include "../render_context_3d_shader/_.h"

namespace cenarius { namespace kernal { namespace components {
using namespace interpreter;
using namespace asynchronous;
using namespace bestead;
using namespace interpreter;
class render_context_3d_program {
public:
    render_context_3d_program();
    virtual ~render_context_3d_program();
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
    js_value_holder vs_shader_;
    render_context_3d_shader* vs_raw_shader_ = nullptr;
    js_value_holder fs_shader_;
    render_context_3d_shader* fs_raw_shader_ = nullptr;
public:
    shader_reflection reflection_;

public:
    static void outlet(js_context&, js_object&);
};


}}}