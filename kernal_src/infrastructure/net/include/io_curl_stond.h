
#pragma once
#include "uv.h"
#include "curl.h"
#include "http_task.h"
#include "poller.h"

namespace cenarius { namespace infrastructure { namespace net {
class curl_context_t {
public:
    static curl_context_t* create(poller*, curl_socket_t);
    static void finalization(curl_context_t*);
public:
    poller* poller_ = nullptr;
    uv_poll_t poll_handle_; curl_socket_t sockfd_;
};

class curl_common final {
public:
    static int check_multi_info(CURLM*);
    static int handle_socket(CURL*, curl_socket_t, int, void*, void*);
    static void start_timeout(CURLM*, long, void*);
};


}}}