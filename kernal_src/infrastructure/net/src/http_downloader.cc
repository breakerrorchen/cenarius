
#include "http_downloader.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

http_downloader::http_downloader(const char* url) 
    : http_downloader(std::string(url)) {
    ;
}

http_downloader::http_downloader(const std::string& url) {
    related_ = std::make_shared<http_downloader_related>();
    related_->url_ = url;
}

bool http_downloader::sendback(std::shared_ptr<io_sendback> sendback) {
    if (related_) {
        related_->sendback_ = sendback;
        return true;
    }
    return false;
}

void http_downloader::set_proxy(const char* proxy) {
    if (related_) {
        related_->proxy_ = proxy;
    }
}

void http_downloader::set_method(http_method method) {
    if (related_) {
        related_->method_ = method;
    }
}

void http_downloader::set_header(const char* k, const char* v) {
    if (related_) {
        if (k && v && strlen(k) > 0 && strlen(v) > 0) {
            related_->header_k_.push_back(std::string(k));
            related_->header_v_.push_back(std::string(v));
        }
    }
}

void http_downloader::timeout(uint32_t time_ms) {
    if (related_) {
        related_->timeout_ = time_ms;
    }
}

bool http_downloader::save_mem(bool save_mem) {
    if (related_) {
        related_->savemem_ = save_mem;
        return true;
    }
    return false;
}

bool http_downloader::save_file(const char* file) {
    if (related_) {
        auto& savefile = related_->savefile_;
        if (savefile.good()) {
            savefile.close();
        }
        savefile.open(file, std::ofstream::out|std::ofstream::trunc);
        return savefile.good();
    }
    return false;
}

bool http_downloader::start(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_ || !related_->savefile_.good()) { 
        return false; 
    }
    auto related = related_;
    auto cancelable = std::make_shared<http_cancelable>();
    committer->post([related, cancelable](poller* _poller) mutable {
        assert(_poller && _poller->curl_handle_);
        CURL* channel_handle = curl_easy_init();
        if (nullptr == channel_handle) { return; }

        char* method = nullptr;
        switch (related->method_) {
        case http_method::__options__:
            method = "OPTIONS"; break;
        case http_method::__get__:
            method = "GET";     break;
        case http_method::__head__:
            method = "HEAD";    break;
        case http_method::__post__:
            method = "POST";    break;
        case http_method::__put__:
            method = "PUT";     break;
        case http_method::__delete__:
            method = "DELETE";  break;
        case http_method::__trace__:
            method = "TRACE";   break;
        case http_method::__connect__:
            method = "CONNECT"; break;
        }

        struct curl_slist* h_list = nullptr;
        if (!related->header_k_.empty()) {
            std::string field;
            for (size_t i = 0; i < related->header_k_.size(); ++i) {
                field += related->header_k_[i];
                field += ": ";
                field += related->header_v_[i];
            }
            h_list = curl_slist_append(h_list, field.c_str());
        }
        
        struct task: public http_task {
            bool is_start_download_     = false;
            bool is_cancel_             = false;
            bool is_download_completed_ = false;
            std::string recv_mem_;
            std::shared_ptr<http_downloader_related> related_;
            curl_slist* h_list_ = nullptr;
            std::shared_ptr<http_header> headers_;
            std::shared_ptr<http_cancelable> cancelable_;
            ~task() {
                if (cancelable_) {
                    cancelable_->channel_handle_ = nullptr;
                }
                if (h_list_) { curl_slist_free_all(h_list_); }
                if (related_->savefile_.good()) {
                    related_->savefile_.close();
                }
            }

        public:
            void on_header() {
                assert(related_);
                if (related_->sendback_) {
                    std::weak_ptr<http_downloader_related> ws_related = related_;
                    auto header = std::move(headers_);
                    related_->sendback_->post([ws_related, header]() mutable {
                        auto related = ws_related.lock();
                        if (related && related->on_header_) {
                            related->on_header_(header);
                        }
                    });
                }
            }

            void on_recv_data(void* buffer, size_t size) {
                if (is_cancel_) return;
                if (related_->savefile_.good() && size > 0) {
                    related_->savefile_.write((char*)buffer, size);
                }

                if (related_->savemem_) {
                    recv_mem_.append((char*)buffer, size);
                }
            }

            void on_progress(double total, double now) {
                assert(related_);
                if (!is_start_download_) {
                    is_start_download_ = true;
                }

                if (is_cancel_) {
                    if (related_->savefile_.good()) {
                        related_->savefile_.close();
                    }
                    return;
                }

                if (now >= total) {
                    is_download_completed_ = true;
                    if (related_->savefile_.good()) {
                        related_->savefile_.close();
                    }
                }
                std::weak_ptr<http_downloader_related> ws_related = related_;
                related_->sendback_->post([ws_related, total, now]() mutable {
                    auto related = ws_related.lock();
                    if (related && related->on_progress_) {
                        related->on_progress_(
                            (int)total, (int)now, (float)(now/total + 0.001));
                    }
                });
            }

            void on_finish(const CURL* handle, const CURLcode& code) {
                assert(related_);
                std::weak_ptr<http_downloader_related> ws_related = related_;
                bool success = is_download_completed_;
                related_->sendback_->post([ws_related, 
                    success, buffer{std::move(recv_mem_)}]() mutable {
                    auto related = ws_related.lock();
                    if (related && related->on_finish_) {
                        related->on_finish_(success, buffer);
                    }
                });
            };

            void on_cancel() {
                assert(related_); is_cancel_ = true;
                std::weak_ptr<http_downloader_related> ws_related = related_;
                related_->sendback_->post([ws_related]() mutable {
                    auto related = ws_related.lock();
                    if (related && related->on_cancel_) {
                        related->on_cancel_();
                    }
                });
            }

            void on_error() {
                assert(related_);
                std::weak_ptr<http_downloader_related> ws_related = related_;
                related_->sendback_->post([ws_related]() mutable {
                    auto related = ws_related.lock();
                    if (related && related->on_error_) {
                        related->on_error_();
                    }
                });
            }
        };

        auto base_url = related->url_.c_str();
        auto task_ptr = new task(); task_ptr->cancelable_ = cancelable;
        auto base_ptr = dynamic_cast<http_task*>(task_ptr);
        task_ptr->h_list_ = h_list; task_ptr->related_ = related;
        curl_easy_setopt(channel_handle, CURLOPT_URL,         base_url);
        curl_easy_setopt(channel_handle, CURLOPT_USERAGENT,  "cenet-e");
        curl_easy_setopt(channel_handle, CURLOPT_NOPROGRESS,        0L);
        curl_easy_setopt(channel_handle, CURLOPT_NOSIGNAL,          1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_NODELAY,       1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_KEEPALIVE,     1L);
        curl_easy_setopt(channel_handle, CURLOPT_DNS_CACHE_TIMEOUT, 60) * 5; // dns cache 5 min
        curl_easy_setopt(channel_handle, CURLOPT_CONNECTTIMEOUT,    10);
        curl_easy_setopt(channel_handle, CURLOPT_SSL_VERIFYPEER,    0L);
        curl_easy_setopt(channel_handle, CURLOPT_SSL_VERIFYHOST,    0L);
        curl_easy_setopt(channel_handle, CURLOPT_LOW_SPEED_LIMIT,    1);
        curl_easy_setopt(channel_handle, CURLOPT_LOW_SPEED_TIME,    60);
        curl_easy_setopt(channel_handle, CURLOPT_FOLLOWLOCATION,    1L);
        curl_easy_setopt(channel_handle, CURLOPT_MAXREDIRS,          5);
        curl_easy_setopt(channel_handle, CURLOPT_CUSTOMREQUEST, method);
        curl_easy_setopt(channel_handle, CURLOPT_HTTPHEADER,    h_list);
        curl_easy_setopt(channel_handle, CURLOPT_PRIVATE,     base_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_WRITEDATA,   task_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_PROGRESSDATA,task_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
        if (!related->proxy_.empty()) {
            curl_easy_setopt(channel_handle, CURLOPT_PROXY, related->proxy_.c_str());
        }

        // on recv header
        using recv_head_cb = size_t(*)(const char*, size_t, size_t, void*);
        recv_head_cb recv_head = [](
            const char* buffer, size_t count, size_t nmemb, void* userdata) ->size_t {
            auto task_ptr = reinterpret_cast<task*>(userdata);
            if (!task_ptr) { return 0; } int bytes_count = count * nmemb;
            if (count < 2) return bytes_count;
            if (2 == count && memcmp(buffer, "\r\n", 2) == 0) {
                task_ptr->on_header();
                return bytes_count;
            }
            if (!task_ptr->headers_) {
                task_ptr->headers_ = std::make_shared<http_header>();
            }
            std::string line(buffer, bytes_count - 2);
            task_ptr->headers_->add(line);
            return bytes_count;
        };

        // on recv content
        using recv_buffer_cb = size_t(*)(char*, size_t, size_t, void*);
        recv_buffer_cb recv_buf = [](
            char* buffer, size_t size, size_t nmemb, void* userdata) ->size_t {
            auto task_ptr = reinterpret_cast<task*>(userdata);
            if (!task_ptr) { return 0; }
            task_ptr->on_recv_data(buffer, size * nmemb);
            return size * nmemb;
        };
        curl_easy_setopt(channel_handle, CURLOPT_WRITEFUNCTION, recv_buf);

        // on progress
        using recv_progress_cb = int(*)(void*, double, double, double, double);
        recv_progress_cb on_progress = [](
            void* userdata, double total, double now, double, double) ->int {
            auto task_ptr = reinterpret_cast<task*>(userdata);
            if (!task_ptr) { return -1; }
            task_ptr->on_progress(total, now);
            return 0;
        };
        curl_easy_setopt(channel_handle, CURLOPT_PROGRESSFUNCTION, on_progress);

        // start
        if (CURLM_OK == curl_multi_add_handle(
                _poller->curl_handle_, channel_handle)) {
            cancelable->is_cancle_ = false;
            cancelable->channel_handle_ = channel_handle;
        } else {
            task_ptr->on_error();
            curl_easy_setopt(channel_handle, CURLOPT_PRIVATE, nullptr);
            curl_easy_cleanup(channel_handle); 
            task_ptr->force_release();
        }
    });
    cancelable_ = cancelable;
    return true;
}

void http_downloader::cancel(std::shared_ptr<io_committer> committer) {
    if (cancelable_ && committer) {
        cancelable_->cancel(committer);
        cancelable_ = nullptr;
    }
}

void http_downloader::on_header(
    std::function<void(std::shared_ptr<http_header>)> callback) {
    if (related_) {
        related_->on_header_ = callback;
    }
}

void http_downloader::on_progress(
    std::function<void(int, int, float)> callback) {
    if (related_) {
        related_->on_progress_ = callback;
    }
}

void http_downloader::on_cancel(std::function<void()> callback) {
    if (related_) {
        related_->on_cancel_ = callback;
    }
}

void http_downloader::on_error(std::function<void()> callback) {
    if (related_) {
        related_->on_error_ = callback;
    }
}

void http_downloader::on_finish(
    std::function<void(bool, std::string&)> callback) {
    if (related_) {
        related_->on_finish_ = callback;
    }
}