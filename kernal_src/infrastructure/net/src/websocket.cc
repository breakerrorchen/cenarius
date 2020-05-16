
#include "websocket.h"
#include "websocket_channel.h"
#include "mbedtls/base64.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

websocket::websocket(const char* url)
    : websocket(std::string(url)) {
    ;
}

websocket::websocket(const std::string& url) {
    related_ = std::make_shared<websocket_related>();
    related_->url_ = url;
}

bool websocket::sendback(std::shared_ptr<io_sendback> sendback) {
    if (related_) {
        related_->sendback_ = sendback;
        return true;
    }
    return false;
}

void websocket::set_proxy(const char* proxy) {
    if (related_) {
        related_->proxy_ = proxy;
    }
}

void websocket::set_header(const char* k, const char* v) {
    if (related_) {
        if (k && v && strlen(k) > 0 && strlen(v) > 0) {
            related_->header_k_.push_back(std::string(k));
            related_->header_v_.push_back(std::string(v));
        }
    }
}

void websocket::set_protocol(const char* _protocol) {
    if (related_) {
        related_->protocol_ = _protocol;
    }
}

void websocket::timeout(uint32_t time_ms) {
    if (related_) {
        related_->timeout_ = time_ms;
    }
}

void websocket::on_header(
    std::function<void(std::shared_ptr<http_header>)> callback) {
    if (related_) {
        related_->on_header_ = callback;
    }
}

void websocket::on_connect(std::function<void()> callback) {
    if (related_) {
        related_->on_connect_ = callback;
    }
}

void websocket::on_recv_text(
    std::function<void(std::string&)> callback) {
    if (related_) {
        related_->on_recv_text_ = callback;
    }
}

void websocket::on_recv_data(
    std::function<void(std::string&)> callback) {
    if (related_) {
        related_->on_recv_data_ = callback;
    }
}

void websocket::on_recv_ping(std::function<void()> callback) {
    if (related_) {
        related_->on_ping_ = callback;
    }
}

void websocket::on_recv_pong(std::function<void()> callback) {
    if (related_) {
        related_->on_pong_ = callback;
    }
}

void websocket::on_close(std::function<void()> callback) {
    if (related_) {
        related_->on_close_ = callback;
    }
}

void websocket::on_error(std::function<void()> callback) {
    if (related_) {
        related_->on_error_ = callback;
    }
}

/*
 * WebSocket is a framed protocol in the format:
 *
 *    0                   1                   2                   3
 *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *   +-+-+-+-+-------+-+-------------+-------------------------------+
 *   |F|R|R|R| opcode|M| Payload len |    Extended payload length    |
 *   |I|S|S|S|  (4)  |A|     (7)     |             (16/64)           |
 *   |N|V|V|V|       |S|             |   (if payload len==126/127)   |
 *   | |1|2|3|       |K|             |                               |
 *   +-+-+-+-+-------+-+-------------+ - - - - - - - - - - - - - - - +
 *   |     Extended payload length continued, if payload len == 127  |
 *   + - - - - - - - - - - - - - - - +-------------------------------+
 *   |                               |Masking-key, if MASK set to 1  |
 *   +-------------------------------+-------------------------------+
 *   | Masking-key (continued)       |          Payload Data         |
 *   +-------------------------------- - - - - - - - - - - - - - - - +
 *   :                     Payload Data continued ...                :
 *   + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
 *   |                     Payload Data continued ...                |
 *   +---------------------------------------------------------------+
 *
 * See https://tools.ietf.org/html/rfc6455#section-5.2
 */
bool websocket::start(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_) { return false; }
    auto related = related_;
    related->related_client_ = shared_from_this();
    state_ = websocket_state::__connecting__;
    committer->post([related](poller* _poller) mutable {
        assert(_poller && _poller->curl_handle_);
        CURL* channel_handle = curl_easy_init();
        if (nullptr == channel_handle) { 
            return; 
        }

        struct curl_slist* h_list = nullptr;
        if (!related->header_k_.empty()) {
            for (size_t i = 0; i < related->header_k_.size(); ++i) {
                auto& k = related->header_k_[i];
                if ("Expect"                 == k) continue;
                if ("Transfer-Encoding"      == k) continue;
                if ("Connection"             == k) continue;
                if ("Upgrade"                == k) continue;
                if ("Sec-WebSocket-Version"  == k) continue;
                if ("Sec-WebSocket-Protocol" == k) continue;
                if ("Sec-WebSocket-Key"      == k) continue;
                std::string field;
                field += related->header_k_[i];
                field += ": "; 
                field += related->header_v_[i];
                h_list = curl_slist_append(h_list, field.c_str());
            }
        }

        // Sec-WebSocket-Key
        std::default_random_engine random_generator;
        std::uniform_int_distribution<int> distribution(0, 36);
        char randow_buf[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char random_str[17] = { 0 };
        for (int i = 0; i < 16; ++i) {
            random_str[i] = randow_buf[distribution(random_generator)];
        }
        size_t base64_str_len = 0; std::string base64_str;
        ::mbedtls_base64_encode(nullptr, 0, 
            &base64_str_len, (unsigned char *)random_str, 16);
        base64_str.resize(base64_str_len);
        std::string ws_key;
        ws_key += "Sec-WebSocket-Key: "; ws_key += "SGVsbG8sIHdvcmxkIQ==";
        h_list = curl_slist_append(h_list, ws_key.c_str());

        // websocket header
        h_list = curl_slist_append(h_list, "Sec-WebSocket-Version: 13");
        h_list = curl_slist_append(h_list, "Expect: 101");
        h_list = curl_slist_append(h_list, "Transfer-Encoding:");
        h_list = curl_slist_append(h_list, "Connection: Upgrade");
        h_list = curl_slist_append(h_list, "Upgrade: websocket");
        if (!related->protocol_.empty()) {
            std::string ws_protocol;
            ws_protocol += "Sec-WebSocket-Protocol: ";
            ws_protocol += related->protocol_;
            h_list = curl_slist_append(h_list, ws_protocol.c_str());
        }

        // wss:// => https://  ws:// => http://
#define WS_HDR      "ws://"
#define HTTP_HDR    "http://"
#define WSS_HDR     "wss://"
#define HTTPS_HDR   "https://"
        std::string http_url; auto base_url = related->url_.c_str();
        if (strncmp(base_url, WS_HDR, strlen(WS_HDR)) == 0) {
            http_url += HTTP_HDR;
            http_url += base_url + strlen(WS_HDR);
        } else if (strncmp(base_url, WSS_HDR, strlen(WSS_HDR)) == 0) {
            http_url += HTTPS_HDR;
            http_url += base_url + strlen(WSS_HDR);
        }
        auto task_ptr = new websocket_channel();
        auto base_ptr = dynamic_cast<http_task*>(task_ptr);
        task_ptr->curl_handle_ = _poller->curl_handle_;
        task_ptr->handle_ = channel_handle;
        task_ptr->h_list_ = h_list; task_ptr->related_ = related;
        curl_easy_setopt(channel_handle, CURLOPT_URL, http_url.c_str());
        curl_easy_setopt(channel_handle, CURLOPT_USERAGENT,  "cenet-e");
        curl_easy_setopt(channel_handle, CURLOPT_NOPROGRESS,        1L);
        curl_easy_setopt(channel_handle, CURLOPT_NOSIGNAL,          1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_NODELAY,       1L);
        curl_easy_setopt(channel_handle, CURLOPT_TCP_KEEPALIVE,     1L);
        curl_easy_setopt(channel_handle, CURLOPT_DNS_CACHE_TIMEOUT, 60 * 5);
        curl_easy_setopt(channel_handle, CURLOPT_CONNECTTIMEOUT,    10);
        curl_easy_setopt(channel_handle, CURLOPT_SSL_VERIFYPEER,    0L);
        curl_easy_setopt(channel_handle, CURLOPT_SSL_VERIFYHOST,    0L);
        curl_easy_setopt(channel_handle, CURLOPT_LOW_SPEED_LIMIT,    1);
        curl_easy_setopt(channel_handle, CURLOPT_LOW_SPEED_TIME,    60);
        curl_easy_setopt(channel_handle, CURLOPT_FOLLOWLOCATION,    1L);
        curl_easy_setopt(channel_handle, CURLOPT_MAXREDIRS,          5);
        curl_easy_setopt(channel_handle, CURLOPT_CUSTOMREQUEST,  "GET");
        curl_easy_setopt(channel_handle, CURLOPT_HTTPHEADER,    h_list);
        curl_easy_setopt(channel_handle, CURLOPT_PRIVATE,     base_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_READDATA,    task_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_WRITEDATA,   task_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_HEADERDATA,  task_ptr);
        curl_easy_setopt(channel_handle, CURLOPT_UPLOAD,            1L);
        curl_easy_setopt(channel_handle, CURLOPT_HTTP_VERSION,CURL_HTTP_VERSION_1_1);
        if (!related->proxy_.empty()) {
            curl_easy_setopt(channel_handle, CURLOPT_PROXY, related->proxy_.c_str());
        }

        // on recv header
        using recv_head_cb = size_t(*)(const char*, size_t, size_t, void*);
        recv_head_cb recv_head = [](
            const char* buffer, size_t count, size_t nmemb, void* userdata) ->size_t {
            auto channel = (websocket_channel*)(userdata);
            assert(channel);
            auto bytes_count = count * nmemb;
            if (bytes_count == 2 && memcmp(buffer, "\r\n", 2) == 0) {
                // 完成对header的接收操作
                channel->on_header();

                // 判断协议升级是不是成功了
                long status;
                curl_easy_getinfo(channel->handle_, CURLINFO_RESPONSE_CODE, &status);
                if (101 == status) {
                    // 服务器已经接受Websocket的链接
                    channel->on_connect();
                } else {
                    // 发现HTTP的Code不是101
                    // 连接失败通知连接失败，并删除自己
                    channel->on_error(); channel->force_release();
                    curl_multi_remove_handle(channel->curl_handle_, channel->handle_);
                    curl_easy_cleanup(channel->handle_);
                }
            } else if (bytes_count > 2) {
                if (!channel->headers_) {
                    channel->headers_ = std::make_shared<http_header>();
                }
                std::string line(buffer, bytes_count - 2);
                channel->headers_->add(line);
            }
            return bytes_count;
        };
        curl_easy_setopt(channel_handle, CURLOPT_HEADERFUNCTION, recv_head);

        // on recv
        using recv_buffer_cb = size_t(*)(char*, size_t, size_t, void*);
        recv_buffer_cb recv_buf = [](
            char* buffer, size_t size, size_t nmemb, void* userdata) ->size_t {
            auto channel = (websocket_channel*)(userdata);
            assert(channel);
            if (!channel->is_upgrade_success_) return 0;
            channel->on_recv_buffer(buffer, size * nmemb);
            return size * nmemb;
        };
        curl_easy_setopt(channel_handle, CURLOPT_WRITEFUNCTION, recv_buf);

        // on send
        using read_buffer_cb = size_t(*)(char*, size_t, size_t, void*);
        recv_buffer_cb read_buf = [](
            char* buffer, size_t size, size_t nmemb, void* userdata) ->size_t {
            auto channel = (websocket_channel*)(userdata);            
            assert(channel);
            if (!channel->is_upgrade_success_) return 0;
            auto ret = channel->on_send_buffer(buffer, size * nmemb);
            if (ret <= 0) {
                return CURL_READFUNC_PAUSE;
            }
            return ret;
        };
        curl_easy_setopt(channel_handle, CURLOPT_READFUNCTION, read_buf);

        // send
        if (CURLM_OK != curl_multi_add_handle(_poller->curl_handle_, channel_handle)) {
            // 发起请求，并删除自己
            task_ptr->on_error(); task_ptr->force_release();
            curl_easy_cleanup(channel_handle); 
        }
    });
    return true;
}

bool websocket::send_text(
    std::shared_ptr<io_committer> committer, std::string& text, bool move) {
    if (text.empty() || !committer || !related_) return false;
    std::string send_text;
    if (move) {
        send_text = std::move(text);
    } else {
        send_text = text;
    }
    auto related = related_;
    committer->post([related, text{std::move(send_text)}](poller*) mutable {
        auto channel = related->related_channel_;
        if (!channel) {
            channel->send_text(text);
        }
    });
    return true;
}

bool websocket::send_data(
    std::shared_ptr<io_committer> committer, std::string& data, bool move) {
    if (data.empty() || !committer || !related_) return false;
    std::string send_data;
    if (move) {
        send_data = std::move(data);
    } else {
        send_data = data;
    }
    auto related = related_;
    committer->post([related, data{std::move(send_data)}](poller*) mutable {
        auto channel = related->related_channel_;
        if (!channel) {
            channel->send_data(data);
        }
    });
    return true;
}

bool websocket::send_ping(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_) return false;
    auto related = related_;
    committer->post([related](poller*) mutable {
        auto channel = related->related_channel_;
        if (channel) {
            channel->send_ping();
        }
    });
    return true;
}

bool websocket::send_pong(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_) return false;
    auto related = related_;
    committer->post([related](poller*) mutable {
        auto channel = related->related_channel_;
        if (channel) {
            channel->send_pong();
        }
    });
    return true;
}

bool websocket::close(std::shared_ptr<io_committer> committer) {
    if (!committer || !related_) return false;
    auto related = related_;
    state_ = websocket_state::__closing__;
    committer->post([related](poller*) mutable {
        auto channel = related->related_channel_;
        if (channel) {
            channel->close();
        }
    });
    return true;
}