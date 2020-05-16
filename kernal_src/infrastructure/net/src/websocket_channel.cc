
#include "websocket.h"
#include "websocket_channel.h"
#include "webscoket_parser_cxx.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

websocket_channel::~websocket_channel() {
    if (h_list_) { 
        curl_slist_free_all(h_list_); 
    }

    if (related_) {
        related_->related_channel_ = nullptr;
    }
}

void websocket_channel::on_connect() {
    is_upgrade_success_ = true;
    if (related_) {
        related_->related_channel_ = this;
    }

    if (h_list_) { 
        curl_slist_free_all(h_list_); h_list_ = nullptr;
    }
    if (!related_ || !related_->sendback_) return;
    std::weak_ptr<websocket_related> ws_related = related_;
    related_->sendback_->post([ws_related]() {
        auto related = ws_related.lock();
        if (related) {
            auto related_client = related->related_client_.lock();
            if (related_client) {
                related_client->state_ = websocket_state::__open__;
            }

            if (related->on_connect_) {
                related->on_connect_();
            }
        }
    });

    parser_.on_header_ = [&](websocket_parser* _parser) ->int {
        on_parser_header(_parser);
        return 0;
    };

    parser_.on_body_ = [&](websocket_parser* _parser, 
        const char* buffer, size_t size) ->int {
        on_parser_content(_parser, buffer, size);
        return 0;
    };

    parser_.on_end_ = [&](websocket_parser* _parser) ->int {
        on_parser_finish(_parser);
        return 0;
    };
}

void websocket_channel::on_header() {
    if (!related_ || !related_->sendback_) return;
    std::weak_ptr<websocket_related> ws_related = related_;
    auto header = std::move(headers_);
    related_->sendback_->post([ws_related, header]() {
        auto related = ws_related.lock();
        if (related && related->on_header_) {
            related->on_header_(header);
        }
    });
}

void websocket_channel::close() {
    if (is_closed_) return;
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    auto conf = (websocket_flags)(
		  WS_OP_CLOSE | WS_FINAL_FRAME | WS_HAS_MASK);
    auto len = websocket_calc_frame_size(conf, 0);
    std::vector<uint8_t> decode_buffer;
    decode_buffer.resize(len);
    static char define_mask[4] = {1, 1, 1, 1};
    is_closing_ = true;
    websocket_build_frame((char*)(&(decode_buffer[0])), 
		  conf, define_mask, nullptr, 0);
    send((char*)(&(decode_buffer[0])), decode_buffer.size());
}

void websocket_channel::send_ping() {
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    if (is_closed_ || is_closing_) return;
    auto conf = (websocket_flags)(
		  WS_OP_PING | WS_FINAL_FRAME | WS_HAS_MASK);
    auto len = websocket_calc_frame_size(conf, 0);
    std::vector<uint8_t> decode_buffer;
    decode_buffer.resize(len);
    static char define_mask[4] = {1, 1, 1, 1};
    websocket_build_frame((char*)(&(decode_buffer[0])), 
		  conf, define_mask, nullptr, 0);
    send((char*)(&(decode_buffer[0])), decode_buffer.size());
}

void websocket_channel::send_pong() {
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    if (is_closed_ || is_closing_) return;
    auto conf = (websocket_flags)(
		  WS_OP_PONG | WS_FINAL_FRAME | WS_HAS_MASK);
    auto len = websocket_calc_frame_size(conf, 0);
    std::vector<uint8_t> decode_buffer;
    decode_buffer.resize(len);
    static char define_mask[4] = {1, 1, 1, 1};
    websocket_build_frame((char*)(&(decode_buffer[0])), 
		  conf, define_mask, nullptr, 0);
    send((char*)(&(decode_buffer[0])), decode_buffer.size());
}

void websocket_channel::send_text(std::string& str) {
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    if (is_closed_ || is_closing_) return;
    if (str.empty()) return;
    auto conf = (websocket_flags)(
		  WS_OP_TEXT | WS_FINAL_FRAME | WS_HAS_MASK);
    auto len = websocket_calc_frame_size(conf, str.length());
    std::vector<uint8_t> decode_buffer;
    decode_buffer.resize(len);
    static char define_mask[4] = {1, 1, 1, 1};
    websocket_build_frame((char*)(&(decode_buffer[0])),
		  conf, define_mask, str.c_str(), str.length());
    send((char*)(&(decode_buffer[0])), decode_buffer.size());
}

void websocket_channel::send_data(std::string& data) {
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    if (is_closed_ || is_closing_) return;
    if (data.size() == 0) return;
    auto conf = (websocket_flags)(
		  WS_OP_BINARY | WS_FINAL_FRAME | WS_HAS_MASK);
    auto len = websocket_calc_frame_size(conf, data.size());
    std::vector<uint8_t> decode_buffer;
    decode_buffer.resize(len);
    static char define_mask[4] = {1, 1, 1, 1};
    websocket_build_frame((char*)(&(decode_buffer[0])),
		  conf, define_mask, (char*)data.c_str(), data.size());
    send((char*)(&(decode_buffer[0])), decode_buffer.size());
}

void websocket_channel::send(char* buffer, size_t size) {
    if (nullptr == curl_handle_ || nullptr == handle_) return;
    if (is_closed_ || is_closing_) return;
    if (!buffer || 0 == size) return;
    if (is_pause_send_) {
        curl_easy_pause(handle_, CURLPAUSE_SEND_CONT);
        is_pause_send_ = false;
    }
    buffer_.append((uint8_t*)buffer, size);

    // 标记sendbuffer的大小
    if (related_) {
        related_->set_sendbuffer_size(buffer_.size());
    }
}

void websocket_channel::on_recv_buffer(char* buffer, size_t size) {
    if (size != parser_.execute((uint8_t*)buffer, size)) {
        on_error();

        // 解析错误，删除自己
        curl_multi_remove_handle(curl_handle_, handle_);
        curl_easy_cleanup(handle_);
        force_release();
    }
}

int websocket_channel::on_send_buffer(char* buffer, size_t size) {
    auto buffer_size = buffer_.size(); int ret = 0;
    if (0 < buffer_size) {
        auto min_size = std::min(size, (size_t)buffer_size);
        memcpy(buffer, buffer_.c_buffer(), min_size);
        buffer_.offset(min_size);
        ret =  min_size;
    } else {
        is_pause_send_ = true;
    }

    // 标记sendbuffer的大小
    if (related_) {
        related_->set_sendbuffer_size(buffer_.size());
    }

    // 如果数据已经发送完毕了
    // 并且数据在发送之后就需要关闭链接
    if (is_closing_ && 0 == buffer_.size()) {
        is_closed_ = true;
        on_close();

        // 删除自己
        curl_multi_remove_handle(curl_handle_, handle_);
        curl_easy_cleanup(handle_);
        force_release();
    }
    return ret;
}

void websocket_channel::on_error() {
    if (!related_ || !related_->sendback_) return;
    std::weak_ptr<websocket_related> ws_related = related_;
    related_->sendback_->post([ws_related]() {
        auto related = ws_related.lock();
        if (related) {
            auto related_client = related->related_client_.lock();
            if (related_client) {
                related_client->state_ = websocket_state::__closed__;
            }

            if (related->on_error_) {
                related->on_error_();
            }
        }
    });
}

void websocket_channel::on_close() {
    if (!related_ || !related_->sendback_) return;
    std::weak_ptr<websocket_related> ws_related = related_;
    related_->sendback_->post([ws_related]() {
        auto related = ws_related.lock();
        if (related) {
            auto related_client = related->related_client_.lock();
            if (related_client) {
                related_client->state_ = websocket_state::__closed__;
            }
            
            if (related->on_close_) {
                related->on_close_();
            }
        }
    });
    is_closed_ = true;
}

void websocket_channel::on_finish(const CURL*, const CURLcode&) {
    // poller中的逻辑，finish调用后强制删除
    // 所以这里就不做删除操作了，防止出现double free的情况
    if (!is_closed_) {
        on_close();
    }
}

void websocket_channel::on_parser_header(
    websocket_parser* _parser) {
    ;
}

void websocket_channel::on_parser_content(
    websocket_parser* _parser, const char* buffer, size_t size) {
    if (!_parser || !buffer || 0 == size) return;
    if (_parser->flags & WS_OP_MASK) {
		parser_.parser_decode((uint8_t*)buffer, size);
	}
    if (_parser->flags & WS_OP_TEXT) {
        current_recv_text_.append(buffer, size);
    } else if (_parser->flags & WS_OP_BINARY) {
        current_recv_data_.append(buffer, size);
    }
}

void websocket_channel::on_parser_finish(websocket_parser* _parser) {
    if (!_parser || !(_parser->flags & WS_FIN)) { 
        return; 
    }
    if (!related_ || !related_->sendback_) return;

    std::weak_ptr<websocket_related> ws_related = related_;
    if (_parser->flags & WS_OP_TEXT) {
        related_->sendback_->post([ws_related, 
            text{std::move(current_recv_text_)}]() mutable {
            auto related = ws_related.lock();
            if (related && related->on_recv_text_) {
                related->on_recv_text_(text);
            }
        });
        current_recv_text_.clear();
    } else if (_parser->flags & WS_OP_BINARY) {
        related_->sendback_->post([ws_related, 
            data{std::move(current_recv_data_)}]() mutable {
            auto related = ws_related.lock();
            if (related && related->on_recv_data_) {
                related->on_recv_data_(data);
            }
        });
        current_recv_text_.clear();
    } else if (_parser->flags & WS_OP_PING) {
        related_->sendback_->post([ws_related]() {
            auto related = ws_related.lock();
            if (related && related->on_ping_) {
                related->on_ping_();
            }
        });
    } else if (_parser->flags & WS_OP_PONG) {
        related_->sendback_->post([ws_related]() {
            auto related = ws_related.lock();
            if (related && related->on_pong_) {
                related->on_pong_();
            }
        });
    } else if (_parser->flags & WS_OP_CLOSE) {
        // on_close 的函数里面会销毁自己
        // 在on_close之后不可以在有相关的操作
        on_close();

        // 删除自己
        curl_multi_remove_handle(curl_handle_, handle_);
        curl_easy_cleanup(handle_);
        force_release();
    }
}