
#include "committer_current.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;

static thread_local std::shared_ptr<
	cenarius::kernal::asynchronous::runnable_committer> _g_runnable_committer;
void cenarius::kernal::asynchronous::runnable_committer_current::attach(
	std::shared_ptr<cenarius::kernal::asynchronous::runnable_committer> v) {
    _g_runnable_committer = v;
}

std::shared_ptr<cenarius::kernal::asynchronous::runnable_committer> 
    cenarius::kernal::asynchronous::runnable_committer_current::obtain() {
    return _g_runnable_committer;
}

bool cenarius::kernal::asynchronous::runnable_committer_current::commit(
    std::function<void()> task) {
    if (!task || !_g_runnable_committer) return false;
    _g_runnable_committer->commit(task);
    return true;
}