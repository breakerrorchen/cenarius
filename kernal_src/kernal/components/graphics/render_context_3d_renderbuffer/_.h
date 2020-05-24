
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
class render_context_3d_renderbuffer {
public:
    render_context_3d_renderbuffer();
    virtual ~render_context_3d_renderbuffer();
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
    uint32_t internal_format_ = DWL_NONE; 
    uint32_t w_ = 0, h_ = 0;

public:
    static void outlet(js_context&, js_object&);
};


}}}