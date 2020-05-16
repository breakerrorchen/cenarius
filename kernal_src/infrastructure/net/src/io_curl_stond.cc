
#include "io_curl_stond.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

curl_context_t* curl_context_t::create(poller* _poller, curl_socket_t sockfd) {
    auto context = new curl_context_t();
    context->sockfd_ = sockfd;
    uv_poll_init_socket(&(_poller->looper_), &(context->poll_handle_), sockfd);
    context->poller_ = _poller; context->poll_handle_.data = (void*)context;
    return context;
}

void curl_context_t::finalization(curl_context_t* context) {
    if (nullptr == context) return;
    uv_close_cb callback = [](uv_handle_t* handle) {
        if (handle && nullptr != handle->data) {
            delete (curl_context_t*)(handle->data);
            // handle->data 指向了curl_context_t
            // curl_context_t释放后，handle也被释放了
            // 所以下面这句会导致crash
            // handle->data = nullptr;
        }
    };
    uv_close((uv_handle_t*)&context->poll_handle_, callback);
}

int curl_common::check_multi_info(CURLM* curl_handle) {
    if (!curl_handle) return 0;
    int count = 0; CURLMsg* message = nullptr; int pending = 0;
    while (true) {
        message = curl_multi_info_read(curl_handle, &pending);
        if (nullptr == message) break;
        if (CURLMSG_DONE == message->msg) {
            auto handle = message->easy_handle;
            curl_multi_remove_handle(curl_handle, handle);
            void* base_ptr = nullptr;
            curl_easy_getinfo(handle, CURLINFO_PRIVATE, &base_ptr);
            if (nullptr != base_ptr) {
                auto task = ((http_task*)base_ptr);
                CURLcode code = message->data.result;
                task->on_finish(handle, code);
                task->force_release();
            }
            curl_easy_setopt(handle, CURLOPT_PRIVATE, nullptr);
            curl_easy_cleanup(handle);
        }
        ++count;
    }
    return count;
}

int curl_common::handle_socket(
    CURL* easy, curl_socket_t s, int action, void* userp, void* socketp) {
    if (nullptr == easy || nullptr == userp) return 0;
    auto* _poller = (poller*)userp; 

    using curl_perform_t = void(*)(uv_poll_t*, int, int);
    curl_perform_t curl_perform = [](uv_poll_t* req, int status, int events) {
        if (!req || !req->data) return;
        auto context = (curl_context_t*)(req->data);
        int running_handles;
        int flags = 0;
        if (status < 0)                      flags  = CURL_CSELECT_ERR;
        if (!status && events & UV_READABLE) flags |= CURL_CSELECT_IN;
        if (!status && events & UV_WRITABLE) flags |= CURL_CSELECT_OUT;
        auto curl_handle = context->poller_->curl_handle_;
        curl_multi_socket_action(
            curl_handle, context->sockfd_, flags, &running_handles);
        curl_common::check_multi_info(curl_handle);
    };

    auto curl_handle = _poller->curl_handle_;
    switch (action) {
        case CURL_POLL_REMOVE:
            if (nullptr != socketp) {
                auto context = (curl_context_t*)socketp;
                uv_poll_stop(&(context->poll_handle_));
                curl_context_t::finalization(context);
                curl_multi_assign(curl_handle, s, nullptr);
            }
            break;
        case CURL_POLL_INOUT: 
        case CURL_POLL_IN:
        case CURL_POLL_OUT:
            {
                int events = 0; curl_context_t* context = nullptr;
                if (socketp) {
                    context = reinterpret_cast<curl_context_t*>(socketp);
                } else {
                    context = curl_context_t::create(_poller, s);
                }
                curl_multi_assign(curl_handle, s, (void*)context);
                if(action != CURL_POLL_IN)  events |= UV_WRITABLE;
                if(action != CURL_POLL_OUT) events |= UV_READABLE;
                uv_poll_start(&context->poll_handle_, events, curl_perform);
            }
            break;

        default:
            assert(false && __FILE__);
    }
    return 0;
}

void curl_common::start_timeout(CURLM* multi, long timeout_ms, void* userp) {
    if (nullptr == multi || nullptr == userp) return;
    auto* _poller = reinterpret_cast<poller*>(userp);
    if (timeout_ms < 0) {
        uv_timer_stop(&_poller->timeout_);
    } else {
        if (timeout_ms == 0) timeout_ms = 1;
        uv_timer_start(&_poller->timeout_, [](uv_timer_t* timer) {
            if (nullptr == timer) return;
            auto _poller = reinterpret_cast<poller*>(timer->data);
            if (nullptr == _poller) return;
            int running_handles; 
            auto curl_handle = _poller->curl_handle_;
            curl_multi_socket_action(
                curl_handle, CURL_SOCKET_TIMEOUT, 0, &running_handles);
            check_multi_info(curl_handle); (void)running_handles; 
        }, timeout_ms, 0);
    }
}
