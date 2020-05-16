
#include "content.h"
using namespace cenarius;
using namespace kernal;
using namespace asynchronous;
using namespace scheduler;
using namespace isolate;
using namespace interpreter;

/**
 * JavaScript解释器需要全局初始化，通过Static来做初始化
 * */
class content_initializer final {
public:
    content_initializer()  { js_initializer::start();   }
    ~content_initializer() { js_initializer::dispose(); }
};
static content_initializer _g_initializer;

/**
 * 启动初始化，初始化JS虚拟机和解释器
 * */
content::content(std::shared_ptr<content_context> _context)
    : content_context_(_context), vm_(), actuator_(vm_) {
    if (!content_context_) { 
        assert(false); std::abort(); 
    }
    related_thread_ = related_thread::obtain();
    assert(related_thread_);
    if (related_thread_) {
        auto& r = related_thread_;
        r->committer_        = _context->committer_;
        r->reactor_timer_    = _context->reactor_timer_;
        r->care_info_        = _context->care_info_;
        r->render_connector_ = _context->render_connector_;
        r->buffer_center_    = _context->buffer_center_;
        
        // 构造
        related_thread_->construct();

        // ！！！！同步行为
        // 这里有一个需要注意的点，在这个时间点同步获取显卡的参数
        // 后续可以直接在js线程中获取显卡固定的参数，这样性能最高
        struct __task__ {
            std::shared_ptr<care_render_connector> render_connector_;
            std::shared_ptr<render_attitude>       render_attitude_;
            void run(barrel_buffer*) {
                assert(render_connector_ && render_attitude_);
                assert(render_connector_->canvas_center_);
                render_connector_->canvas_center_
                    ->get_hardware_attitude(render_attitude_.get());
            }
        };
        command_transmitter transmitter(r->buffer_center_);
        auto task = transmitter.alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->render_connector_ = r->render_connector_;
            task->render_attitude_  = r->render_attitude_ ;
        }
        transmitter.force_commit(true, true);
    }
}

void content::eval(const char* source_code) {
    js_release_scope __release_scope__(vm_);
    actuator_.get_context().eval(source_code, nullptr);
}
