
#include "common/cxx_str_tools.h"
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace common_base;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace kernal;
using namespace isolate;
using namespace bestead;
using namespace components;

void image::src(js_parameter& parameter) {
    parameter.set_return((js_value)src_);
}

void image::set_src(js_parameter& parameter) {
    auto thread_related = related_thread::obtain();
    assert(thread_related && thread_related->net_io_committer_);
    if (http_downloader_) {
        http_downloader_->cancel(thread_related->net_io_committer_);
        http_downloader_ = nullptr;
    }
    if (parameter.get_argument_count() != 1) return;
    auto src = parameter.get_argument_at(0).to_string();

    static int i = 0;
    // start with http:// or https://
    if (str_tools::start_with_no_case(src, "http://") ||
        str_tools::start_with_no_case(src, "https://")) {
        load_from_net(src);
    }
    // start with ora://
    else if (str_tools::start_with_no_case(src, "ora://")) {
        load_from_ora(src);
    }
    // start with other
    else {
        load_from_loc(src);
    }
}