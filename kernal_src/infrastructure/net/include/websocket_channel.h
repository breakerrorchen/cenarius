
#pragma once
#include "io_center.h"
#include "http_task.h"
#include "http_header.h"
#include "websocket_related.h"
#include "websocket_buffer.h"
#include "webscoket_parser_cxx.h"

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
namespace cenarius { namespace infrastructure { namespace net {
class websocket;
class websocket_channel final: public http_task 
    , public std::enable_shared_from_this<websocket_channel> {
    friend class websocket;
public:
    ~websocket_channel();

public:
    void on_connect();
    void on_header();

public:
    void close();
    void send_ping();
    void send_pong();
    void send_text(std::string&);
    void send_data(std::string&);

private:
    void send          (char*, size_t);
    void on_recv_buffer(char*, size_t);
    int  on_send_buffer(char*, size_t);
    void on_error      ();
    void on_close      ();
    void on_finish     (const CURL*, const CURLcode&);

private:
    void on_parser_header (websocket_parser*);
    void on_parser_content(websocket_parser*, const char*, size_t);
    void on_parser_finish (websocket_parser*);

private:
    CURLM* curl_handle_ = nullptr;
    curl_slist* h_list_ = nullptr;
    CURL* handle_ = nullptr;
    websocket_buffer buffer_;
    ws_parser_cxx parser_;
    bool is_pause_send_ = false;
    bool is_upgrade_success_ = false;
    bool is_closing_ = false;
    bool is_closed_ = false;
    std::shared_ptr<http_header> headers_;
    std::shared_ptr<websocket_related> related_;

private:
    std::string current_recv_text_;
    std::string current_recv_data_;
};


}}}