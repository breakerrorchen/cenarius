
#include "care_render_connector.h"
#include "coordinator.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace cc;

coordiator::coordiator(std::shared_ptr<care> _care): care_(_care) {
    if (nullptr == care_) {
        throw std::invalid_argument("~");
    }
}

void coordiator::start() {
    // 内部线程启动，优先启动渲染线程在启动控制器线程
    // 由于控制器线程启动的时候就会有可能需要推送渲染线程的命令了
    // 所以需要在渲染线程确定已经启动的情况下再启动控制器线程
    auto connector = std::make_shared<care_render_connector>();
    buffer_center_ = std::make_shared<barrel_buffer_center>();
    renderer_ = std::make_shared<command_renderer>(
        buffer_center_, care_, connector);
    renderer_->start();

    // 启动控制器线程
    controller_ = std::make_shared<core_controller>(
        buffer_center_, care_, connector);
    controller_->start();
}

void coordiator::size_changed(uint32_t w, uint32_t h) {
    if (controller_) { controller_->resize(w, h); }
}

void coordiator::pause() {
    if (controller_) { controller_->pause(); }
}

void coordiator::resume() {
    if (controller_) { controller_->resume(); }
}

void coordiator::finalization() {
    /**
     * 整个卸载，只能等到控制器线程完全退出后再退出渲染线程
     * */
    if (controller_) { 
        controller_->stop(true); 
    }

    if (renderer_) { 
        renderer_->stop(true); 
    }
}