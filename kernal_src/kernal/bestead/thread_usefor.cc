
#include "thread_usefor.h"
#include "kernal/asynchronous/syncer/spinlocker_watcher.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace bestead;

static thread_local uint32_t _thread_id = 0;
static uint32_t _thread_id_counter = 0;
static spinlocker _locker;
static thread_local auto _thread_usefor = thread_usefor_constant::none;

uint32_t thread_userfor::thread_id() {
    if (0 == _thread_id) { 
        spinlocker_watcher watcher(_locker);
        _thread_id = ++_thread_id_counter;
    }
    return _thread_id;
}

bool thread_userfor::check_usefor(thread_usefor_constant usefor) {
    return _thread_usefor == usefor;
}

void thread_userfor::mark(thread_usefor_constant usefor) {
    _thread_usefor = usefor;
}




