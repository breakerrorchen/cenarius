
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <random>
#include <functional>
#include <thread>
#include "poller_thread.h"
#include "io_committer.h"

namespace cenarius { namespace infrastructure { namespace net {
class io_center final: public io_committer {
public:
    io_center();
    io_center(const io_center&) = delete;
    io_center(io_center&&) = delete;
    io_center& operator=(const io_center&) = delete;
    io_center& operator=(io_center&&) = delete;

public:
    /**
     * the singleton pattern can theoretically have only 
     * one implementation in a process
     * */
    static std::shared_ptr<io_center> get_instance();

public:
    void post(std::function<void(poller*)> task) override {
        if (task) { 
            io_center::try_post(task); 
        }
    }
    
    /**
     * notify and execute asynchronous tasks
     * */
    bool try_post(std::function<void(poller*)>);

public:
    std::shared_ptr<poller_thread> poller_thread_;
};


}}}