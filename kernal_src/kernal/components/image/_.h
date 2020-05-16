
#pragma once
#include "common/base_header_inct.h"
#include "infrastructure/interpreter/include/interpreter.h"
#include "infrastructure/renderer/include/canvas.h"
#include "infrastructure/net/include/http_downloader.h"
#include "kernal/bestead/alived_token.h"

namespace cenarius { namespace kernal { namespace components {
using namespace infrastructure;
using namespace net;
using namespace interpreter;
using namespace bestead;
using namespace renderer;
class image {
public:
    image() :alived_watcher_(this) {
        ;
    }

public:
	void src         (js_parameter&);
    void set_src     (js_parameter&);
    void width       (js_parameter&);
    void height      (js_parameter&);
    void on_load     (js_parameter&);
    void set_on_load (js_parameter&);
    void on_error    (js_parameter&);
    void set_on_error(js_parameter&);

public:
    inline sk_sp<SkImage> get_raw_image() const {
        return raw_image_;
    }

public:
    void load_from_loc(std::string&);
    void load_from_ora(std::string&);
    void load_from_net(std::string&);

private:
    js_value_holder src_     ;
    js_value_holder on_load_ ;
    js_value_holder on_error_;

private:
    /**
     * 用来监控当前对象的生命周期
     * 线程不安全，必须保证在同一个线程中执行
     * */
    alived_watcher<image> alived_watcher_;
    // skia image
    sk_sp<SkImage> raw_image_;
    // 用来区分不同的加载任务
    uint32_t load_id_ = 0;
    // 当前的下载任务，新的任务需要cancel上一个
    std::shared_ptr<http_downloader> http_downloader_;

public:
    static void outlet(js_context&, js_object&);
};


}}}