
#include "io_center.h"
#include "curl.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

io_center::io_center() {
    poller_thread_ = std::make_shared<poller_thread>();
    poller_thread_->start();
    poller_thread_->post([](poller* _pooler) {
        curl_global_init(CURL_GLOBAL_ALL);
    });
}

io_center::~io_center() {
    if (poller_thread_) {
        poller_thread_->stop([]() {
        }, true);
    }
}

std::shared_ptr<io_center> io_center::get_instance() {
    static std::shared_ptr<io_center> _g_instance;
    static std::once_flag _once;
    std::call_once(_once, [&]() {
        auto ptr = new(std::nothrow) io_center();
        _g_instance = std::shared_ptr<io_center>(ptr);
    });
    return _g_instance;
}

bool io_center::try_post(std::function<void(poller*)> task) {
    if (poller_thread_ && task) {
        return poller_thread_->try_post(task);
    }
    return false;
}