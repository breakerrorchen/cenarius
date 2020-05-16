
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace isolate;
using namespace components;

void timer::outlet(js_context& _context, js_object& _object) {
    // 动画定时器
    _object["requestAnimationFrame"] = js_value::create(
        _context, _I_BIND_FUNCTION(timer::anima_request));
    _object["cancelAnimationFrame"]  = js_value::create(
        _context, _I_BIND_FUNCTION(timer::anima_cancel));
    // 普通定时器
    _object["setTimeout"]     = js_value::create(
        _context, _I_BIND_FUNCTION(timer::set_timeout));
    _object["setInterval"]    = js_value::create(
        _context, _I_BIND_FUNCTION(timer::set_interval));
    _object["clearTimeout"]   = js_value::create(
        _context, _I_BIND_FUNCTION(timer::clear_timeout));
    _object["clearInterval"]  = js_value::create(
        _context, _I_BIND_FUNCTION(timer::clear_interval));
}