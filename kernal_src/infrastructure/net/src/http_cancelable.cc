
#include "http_cancelable.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

bool http_cancelable::cancel(std::shared_ptr<io_committer> committer) {
    if (is_cancle_ || !committer) return false;
    auto _this = shared_from_this();
    committer->post([_this](poller* _poller) mutable {
        if (!_this->channel_handle_) return;
        auto& curl_handle = _poller->curl_handle_;
        assert(curl_handle);
        auto channel_handle = _this->channel_handle_;
        void* base_ptr = nullptr;
        curl_easy_getinfo(channel_handle, CURLINFO_PRIVATE, &base_ptr);
        if (nullptr != base_ptr) {
            auto task = ((http_task*)base_ptr);
            task->on_cancel(curl_handle);
            task->force_release();
        }
        curl_multi_remove_handle(curl_handle, channel_handle);
        curl_easy_cleanup(channel_handle);
        _this->channel_handle_ = nullptr;
    });
    is_cancle_ = true;
    return true;
}