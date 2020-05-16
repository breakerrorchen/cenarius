
#include "related_thread_net_sendback.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace infrastructure;
using namespace net;
using namespace isolate;

bool related_thread_net_sendback::post(std::function<void()> _task) {
    if (_task && committer_) {
        committer_->commit(_task);
        return true;
    }
    return false;
}