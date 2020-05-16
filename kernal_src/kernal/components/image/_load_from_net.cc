
#include "kernal/basis_service/misc.h"
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace infrastructure;
using namespace interpreter;
using namespace renderer;
using namespace kernal;
using namespace service;
using namespace isolate;
using namespace bestead;
using namespace components;

void image::load_from_net(std::string& src) {
    raw_image_ = nullptr;
    auto thread_related = related_thread::obtain();
    assert(thread_related);
    assert(thread_related->net_io_committer_);
    assert(thread_related->net_io_sendback_);
    assert(thread_related->committer_);
    auto thread_committer = thread_related->committer_;
    auto weak_ptr = alived_watcher_.get();
    assert(weak_ptr);

    auto downloader_id = ++load_id_;
    http_downloader_ = std::make_shared<http_downloader>(src.c_str());
    http_downloader_->on_finish([weak_ptr, downloader_id, 
        thread_committer](bool success, std::string& buffer) {
        auto _this = weak_ptr->get();
        if (!_this) return;
        if (downloader_id != _this->load_id_) return;
        if (!success) {
            if (_this->on_error_.is_useable()) {
                js_release_scope release_scope(_this->on_error_);
                auto callback = (js_value)(_this->on_error_);
                if (callback.is_useable()) {
                    callback.function_invoke(
                        nullptr, nullptr, 0, nullptr);
                }
            }
        } else {
            // 推送到misc线程中解码
            misc::commit([weak_ptr, buffer{std::move(buffer)},
                thread_committer, downloader_id]() {
                auto data = SkData::MakeWithoutCopy(buffer.data(), buffer.size());
                auto image = SkImage::MakeFromEncoded(data);
                if (image) {
                    // make sure to resolve all lazy images.
                    image = image->makeRasterImage();
                }

                // 推送到JavaScript线程
                thread_committer->commit([weak_ptr, image, downloader_id]() {
                    auto _this = weak_ptr->get();
                    if (!_this) return;
                    if (downloader_id != _this->load_id_) return;
                    _this->raw_image_ = image;
                    if (image) {
                        if (_this->on_load_.is_useable()) {
                            js_release_scope __release_scope(_this->on_load_);
                            auto callback = (js_value)(_this->on_load_);
                            if (callback.is_useable()) {
                                callback.function_invoke(
                                    nullptr, nullptr, 0, nullptr);
                            }
                            (void)__release_scope;
                        }
                    } else {
                        if (_this->on_error_.is_useable()) {
                            js_release_scope __release_scope(_this->on_error_);
                            auto callback = (js_value)(_this->on_error_);
                            if (callback.is_useable()) {
                                callback.function_invoke(
                                    nullptr, nullptr, 0, nullptr);
                            }
                        }
                    }
                });
            });
        }
    });
    http_downloader_->save_mem(true);
    http_downloader_->sendback(thread_related->net_io_sendback_);
    http_downloader_->start(thread_related->net_io_committer_);
}