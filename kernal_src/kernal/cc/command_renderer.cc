
#include "command_renderer.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace cc;

command_renderer::command_renderer(
    std::shared_ptr<barrel_buffer_center> buffer_center,
    std::shared_ptr<care> _care,
    std::shared_ptr<care_render_connector> connector)
    : care_(_care), buffer_center_(buffer_center)
    , render_connector_(connector) {
    assert(care_ && buffer_center_ && connector);
    if (!_care || !buffer_center || !connector) {
        throw std::invalid_argument("~");
    }
}

void command_renderer::start() {
    auto _protected_this = shared_from_this();
    syncer_condition syncer;
    auto thread = std::thread([_protected_this, &syncer]() {
        _protected_this->render_command_consume(syncer);
    });
    // 同步通知外部等待线程初始化完成
    syncer.wait(); render_thread_.swap(thread);
}

void command_renderer::stop(bool sync) {
    should_exit_.store(true);
    if (buffer_center_) {
        buffer_center_->wakeup_consumer();
    }

    if (sync) {
        render_thread_.join();
    } else {
        render_thread_.detach();
    }
}

void command_renderer::render_command_consume(
    syncer_condition& _condition) {
    assert(buffer_center_ && render_connector_);
    auto _render_care = care_->render();
    assert(_render_care);

    // 通知底层渲染要开始啦
    _render_care->on_start();

    // 设置connector
    render_connector_->render_ = _render_care;
    render_connector_->canvas_center_ 
        = _render_care->get_canvas_center();
    
    // 通知外部线程已经准备好了
    _condition.completed_notify();  

    // 开启消费循环
    while (true) {
        buffer_center_->batch_execute(true);
        if (should_exit_.load()) {
            break;
        }
    }
    // 确保所有命令一定被消费了
    buffer_center_->batch_execute(false);

    // 清理connector
    render_connector_->render_ = nullptr;
    render_connector_->canvas_center_ = nullptr;

    // 通知底层渲染结束了
    _render_care->on_finish();
}
