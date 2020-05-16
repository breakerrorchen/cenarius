
#pragma once
#include <iostream>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <thread>

#include "uv.h"
#include "curl.h"
#include "io_committer.h"

namespace cenarius { namespace infrastructure { namespace net {
class http_client;
class http_downloader;
class http_cancelable;
class websocket;
class curl_common;
class curl_context_t;
class http_client;
class poller final : public io_committer {
    friend class http_client;
    friend class http_downloader;
    friend class http_cancelable;
    friend class websocket;
    friend class curl_common;
    friend class curl_context_t;
    friend class http_client;
public:
    poller();
    poller(const poller&) = delete;
    poller(poller&&) = delete;
    poller& operator=(const poller&) = delete;
    poller& operator=(poller&&) = delete;

public:
    /**
     * Notify and execute asynchronous tasks
     * */
    void post(std::function<void(poller*)>) override;

public:
    /**
     * Start an internal loop until an event is received or exited
     * This is a blocking function. Theoretically, 
     * it should run in a separate thread.
     * */
    void start();

    /**
     * If the internal event loop is started, 
     * this method can be used to exit the loop, 
     * mainly used for thread exit
     * */
    void stop(std::function<void()> task = nullptr);

private:
    void atomic_queue_lock(bool v);

protected:
    uv_loop_t looper_; uv_async_t async_; uv_timer_t timeout_;

protected:
    std::list<std::function<void(poller*)>> *in_, *out_;
    std::list<std::function<void(poller*)>> queue_[2];
    std::atomic_flag locker_ = ATOMIC_FLAG_INIT;

protected:
    CURLM* curl_handle_ = nullptr;
};


}}}