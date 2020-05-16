
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory>
#include <functional>
#include "webscoket_parser.h"

namespace cenarius { namespace infrastructure { namespace net {
class ws_parser_cxx final {
public:
	ws_parser_cxx();
public:
	void parser_decode(uint8_t*, size_t);
public:
	size_t execute(uint8_t*, size_t);
public:
	std::function<int(websocket_parser*)> on_header_;
	std::function<int(websocket_parser*,
        const char*, size_t)> on_body_;
	std::function<int(websocket_parser*)> on_end_;
private:
	websocket_parser parser_;
	websocket_parser_settings settings_;
};


}}}
