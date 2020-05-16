
#include "related_thread.h"
#include "related_thread_net_sendback.h"
using namespace cenarius;
using namespace kernal;
using namespace isolate;

void related_thread::construct() {
    render_attitude_ = std::make_shared<render_attitude>();
    anima_timer_ = std::make_shared<batch_timer_container>();
    
    // 创建网络服务
    net_io_center_ = std::make_shared<net::io_center>();
    net_io_committer_ = std::dynamic_pointer_cast<
        net::io_committer>(net_io_center_);
    assert(net_io_center_ && net_io_committer_);
    assert(committer_);
    auto send_back = std::make_shared<related_thread_net_sendback>();
    send_back->committer_ = committer_;
    net_io_sendback_ = std::dynamic_pointer_cast<
        net::io_sendback>(send_back);
    assert(net_io_sendback_);
}

thread_local std::shared_ptr<related_thread> _tl_related;
std::shared_ptr<related_thread> related_thread::obtain() {
    if (!_tl_related) {
        _tl_related = std::make_shared<related_thread>();
    }
    return _tl_related;
}

void related_thread::dispose() {
    if (nullptr != _tl_related) { _tl_related = nullptr; }
}

