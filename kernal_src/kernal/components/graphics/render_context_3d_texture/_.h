
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
class render_context_3d_texture {
public:
    render_context_3d_texture();
    virtual ~render_context_3d_texture();
public:
    bool is_useable();
    bool dispose();

public:
    uint32_t mag_filter_ = DWL_LINEAR;
	uint32_t min_filter_ = DWL_NEAREST_MIPMAP_LINEAR;
	uint32_t wrap_s_	 = DWL_REPEAT;
	uint32_t wrap_t_ 	 = DWL_REPEAT;

public:
    std::shared_ptr<alived_token<render_context_3d>> related_;
    enum __status__ { _nil_, _builded_, _deleted_ };
    __status__ status_ = _builded_;
    uint32_t* related_value_ = nullptr;
    std::shared_ptr<command_transmitter> transmitter_;
public:
    static void outlet(js_context&, js_object&);
};


}}}