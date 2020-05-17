
#pragma once
#include "common/logger.h"
#include "common/base_header_inct.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "care.h"
#include "core_controller.h"
#include "command_renderer.h"
#include "care_render_connector.h"

namespace cenarius { namespace kernal { namespace cc {
using namespace asynchronous;
class coordiator final {
public:
    coordiator(std::shared_ptr<care>);
public:
    void start();
    void eval_script(std::string&, bool move_ = false);
    void pause();
    void size_changed(uint32_t, uint32_t);
    void resume();
    void finalization();

private:
    std::shared_ptr<barrel_buffer_center> buffer_center_;
    std::shared_ptr<care> care_;
    std::shared_ptr<core_controller> controller_;
    std::shared_ptr<command_renderer> renderer_;
    std::shared_ptr<care_render_connector> render_connector_;
};


}}}