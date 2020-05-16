
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace service;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

/**
 * 测试代码
 * */
#define __code(code) #code
const char* _code = __code(

var canvas = cenarius.graphics.window_canvas();
var gl = canvas.getContext("webgl");
gl.clearColor(1, 1, 0, 1);
gl.clear(gl.COLOR_BUFFER_BIT);

// var _2d = canvas.getContext("2d");
// _2d.rotate(0.4);
// _2d.fillText("guodong陈国栋", 400, 400);
// var ctx = _2d;
// var s = new Image();
// s.src = "https://www.easyicon.net/api/resizeApi.php?id=1258052&size=128";
// s.onload = function() {
//     console.log("on load ");

    
//     ctx.drawImage(s, 200, 200, 40, 40);
    
// };
// s.onerror = function() {
//     console.log("on error ");
// };
// ctx.fillRect(10, 10, 150, 100);




);

/**
 * 启动后初始化解释器和设置global对象
 * JSCode中全局变量会挂接到global对象上面
 * */
void content::on_create() {
	// 安装全局的通知服务
	event_observer::setup_and_set_current();
	// 启动js虚拟机
    js_release_scope __release_scope__(vm_);
    auto context = actuator_.get_context();
    auto global_object = context.get_global_object();
    global_object["global"] = global_object;
    extension_ = extension_embeder::create(actuator_);
    extension_->build(global_object);
    
    eval(_code);
}