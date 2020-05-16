
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/renderer/include/canvas_center.h"
#include "infrastructure/renderer/include/render_attitude.h"
#include "kernal/asynchronous/command_buffer/barrel_buffer_center.h"
#include "kernal/asynchronous/command_buffer/transmitter.h"
#include "kernal/asynchronous/runnable/committer.h"
#include "kernal/basis_service/event_observer.h"
#include "kernal/bestead/puppet.h"
#include "kernal/bestead/alived_token.h"
#include "kernal/isolate/related_thread.h"
#include "kernal/cc/care_render_connector.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace interpreter;
using namespace service;
using namespace renderer;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;
class canvas {
public:
	canvas(): alived_watcher_(this) { }
	canvas(__sptr<related_thread>); // window related canvas
	canvas(__sptr<related_thread>, int, int);
	virtual ~canvas();

public:
	void w 	  		   (i_parameter&);
	void set_w		   (i_parameter&);
	void h    		   (i_parameter&);
	void set_h		   (i_parameter&);
	void get_context   (i_parameter&);
	void get_context_2d(i_parameter&);
	void get_context_3d(i_parameter&);

public:
	void get_size(int*, int*);

public:
	// js修改Canvas的大小的时候通过这个函数来调整
	void resize_check();
	// 接收到系统的vsync事件，
	// 只有window related canvas监听了系统vsync事件
	void on_vsync();

private:
	__sptr<command_transmitter> transmitter_;
	__sptr<canvas_center> canvas_center_;
	__sptr<care_render> care_render_;
	__sptr<render_attitude> render_attitude_;
	puppet<renderer::canvas> raw_canvas_;
	int w_ = 0, h_ = 0; bool need_resize_ = false;

private:
	// 用来记录曾经创建过的context
	js_object_holder _2d_context_;
	js_object_holder _3d_context_;

private:
	event_observer_watcher vsync_listener_;
	alived_watcher<canvas> alived_watcher_;

public:
    static void outlet(js_context&, js_object&);
};


}}}