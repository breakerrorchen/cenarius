
#include "http_client.h"
#include "url_tools.h"
#include "url_paramers.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

http_client::http_client(const char* url)
    : http_client(std::string(url)) {
    ;
}

http_client::http_client(const std::string& url) {
    related_ = std::make_shared<http_client_related>();
    related_->url_ = url;
}

bool http_client::sendback(std::shared_ptr<io_sendback> sendback) {
    if (related_) {
        related_->sendback_ = sendback;
        return true;
    }
    return false;
}

void http_client::set_proxy(const char* proxy) {
    if (related_) {
        related_->proxy_ = proxy;
    }
}

void http_client::set_method(http_method method) {
    if (related_) {
        related_->method_ = method;
    }
}

void http_client::set_header(const char* k, const char* v) {
    if (related_) {
        if (k && v && strlen(k) > 0 && strlen(v) > 0) {
            related_->header_k_.push_back(std::string(k));
            related_->header_v_.push_back(std::string(v));
        }
    }
}

void http_client::set_parame(const char* k, const char* v) {
    if (related_) {
        if (k && v && strlen(k) > 0 && strlen(v) > 0) {
            related_->parame_k_.push_back(std::string(k));
            related_->parame_v_.push_back(std::string(v));
        }
    }
}

void http_client::timeout(uint32_t time_ms) {
    if (related_) {
        related_->timeout_ = time_ms;
    }
}

void http_client::on_header(
    std::function<void(std::shared_ptr<http_header>)> callback) {
    if (related_) {
        related_->on_header_ = callback;
    }
}

void http_client::on_content(
    std::function<void(std::string&, int code)> callback) {
    if (related_) {
        related_->on_content_ = callback;
    }
}

void http_client::on_cancel(std::function<void()> callback) {
    if (related_) {
        related_->on_cancel_ = callback;
    }
}

void http_client::on_error(std::function<void()> callback) {
    if (related_) {
        related_->on_error_ = callback;
    }
}

bool http_client::start(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_) { return false; }
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
            std::shared_ptr<http_client_related> related_;
            std::shared_ptr<http_cancelable> cancelable_;
            curl_slist* h_list_ = nullptr;
            std::string post_content_;
            std::string recv_content_;
            std::shared_ptr<http_header> headers_;
            ~task() {
                if (cancelable_) {
                    cancelable_->channel_handle_ = nullptr;
                }
                if (h_list_) { curl_slist_free_all(h_list_); }
            }

        public:
            // 收到Http的消息头，推送到sendback线程
            void on_header() {
                assert(related_);
                if (related_->sendback_) {
                    std::weak_ptr<http_client_related> ws_related = related_;
                    auto header = std::move(headers_);
                    related_->sendback_->post([ws_related, header]() mutable {
                        auto related = ws_related.lock();
                        if (related && related->on_header_) {
                            related->on_header_(header);
                        }
                    });
                }
            }

            // 当连接已经完成
            void on_finish(CURL* handle, const CURLcode& code) {
                assert(related_ && handle);
                long status;
                curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &status);
                if (related_->sendback_) {
                    std::weak_ptr<http_client_related> ws_related = related_;
                    related_->sendback_->post([ws_related, 
                        status, content{std::move(recv_content_)}]() mutable{
                        auto related = ws_related.lock();
                        if (related && related->on_content_) {
                            related->on_content_(content, status);
                        }
                    });
                }
            }

            // 当连接出现错误的时候回回调这个函数，比如url格式不对
            void on_error() {
                assert(related_);
                if (related_->sendback_) {
                    std::weak_ptr<http_client_related> ws_related = related_;
                    related_->sendback_->post([ws_related]() {
                        auto related = ws_related.lock();
                        if (related && related->on_error_) {
                            related->on_error_();
                        }
                    });
                }
            }

            // 当被主动取消的时候，会在取消后调用这个函数
            void on_cancel() {
                assert(related_);
                if (related_->sendback_) {
                    std::weak_ptr<http_client_related> ws_related = related_;
                    related_->sendback_->post([ws_related]() {
                        auto related = ws_related.lock();
                        if (related && related->on_cancel_) {
                            related->on_cancel_();
                        }
                    });
                }
            }
        };

        auto base_url = related->url_;
        auto task_ptr = new task(); task_ptr->cancelable_ = cancelable;
        auto base_ptr = dynamic_cast<http_task*>(task_ptr);
        task_ptr->h_list_ = h_list; task_ptr->related_ = related;

        // 参数设置
        assert(related->parame_k_.size() == related->parame_v_.size());
        if (related->method_ == http_method::__post__) {
            int size = related->parame_k_.size();
            if (size > 0) {
                auto& parame_k = related->parame_k_;
                auto& parame_v = related->parame_v_;
                auto& post_content =  task_ptr->post_content_;
                for (int i = 0; i < size; ++i) {
                    post_content += url_tools::encode(parame_k[i]).c_str();
                    post_content += "=";
                    post_content += url_tools::encode(parame_v[i]).c_str();
                    if (i < size - 1) {
                        post_content += "&";
                    }
                }
            } else {
               task_ptr->post_content_ = std::move(related->post_content_);
            }

            if (!task_ptr->post_content_.empty()) {
                auto size = task_ptr->post_content_.size();
                auto data = task_ptr->post_content_.data();
                curl_easy_setopt(channel_handle, CURLOPT_POSTFIELDSIZE, size);
                curl_easy_setopt(channel_handle, CURLOPT_POSTFIELDS,    data);
            }
        } else {
            int size = related->parame_k_.size();
            if (size > 0) {
                auto& parame_k = related->parame_k_;
                auto& parame_v = related->parame_v_;
                url_paramers paramers(base_url.c_str());
                for (int i = 0; i < size; ++i) {
                    auto k = url_tools::encode(parame_k[i]).c_str();
                    auto v = url_tools::encode(parame_v[i]).c_str();
                    paramers.add(k, v);
                }
                base_url = paramers.get();
            }
        }

        // 设置curl的参数
        curl_easy_setopt(channel_handle, CURLOPT_URL,         base_url.c_str());
        curl_easy_setopt(channel_handle, CURLOPT_USERAGENT,  "cenet-e");
        curl_easy_setopt(channel_handle, CURLOPT_NOPROGRESS,        1L);
        curl_easy_setopt(channel_handle, CURLOPT_NOSIGNAL,          1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_NODELAY,       1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_KEEPALIVE,     1L);
        curl_easy_setopt(channel_handle, CURLOPT_DNS_CACHE_TIMEOUT, 10);
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
        curl_easy_setopt(channel_handle, CURLOPT_HEADERDATA,  task_ptr);
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
            task_ptr->recv_content_.append(buffer, size* nmemb);
            return size * nmemb;
        };
        curl_easy_setopt(channel_handle, CURLOPT_WRITEFUNCTION, recv_buf);
        
        // start
        if (CURLM_OK == curl_multi_add_handle(_poller->curl_handle_, channel_handle)) {
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