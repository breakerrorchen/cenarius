
#include "webscoket_parser_cxx.h"
using namespace cenarius;
using namespace infrastructure;
using namespace net;

static int _on_frame_header(websocket_parser* parser) {
    auto related = (ws_parser_cxx*)(parser->data);
    if (related && related->on_header_) {
        return related->on_header_(parser);
    }
    return 0;
}

static int _on_frame_body(websocket_parser* parser,
    const char* at, size_t size) {
    auto related = (ws_parser_cxx*)(parser->data);
    if (related && related->on_body_) {
        return related->on_body_(parser, at, size);
    }
    return 0;
}

static int _on_frame_end(websocket_parser* parser) {
    auto related = (ws_parser_cxx*)(parser->data);
    if (related && related->on_end_) {
        return related->on_end_(parser);
    }
    return 0;
}

ws_parser_cxx::ws_parser_cxx() {
	websocket_parser_settings_init(&settings_);
	settings_.on_frame_header = _on_frame_header;
    settings_.on_frame_body   = _on_frame_body;
    settings_.on_frame_end    = _on_frame_end;
	websocket_parser_init(&parser_);
	parser_.data = (void*)this;
}

void ws_parser_cxx::parser_decode(
	uint8_t* buffer, size_t size) {
	websocket_parser_decode(
        (char*)buffer, (char*)buffer, size, &parser_);
}

size_t ws_parser_cxx::execute(
	uint8_t* buffer, size_t size) {
	return websocket_parser_execute(
		&parser_, &settings_, (char*)buffer, size);
}