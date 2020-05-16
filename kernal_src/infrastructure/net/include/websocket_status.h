
#pragma once

namespace cenarius { namespace infrastructure { namespace net {
enum class websocket_state {
    __connecting__      = 0,
    __open__            = 1,
    __closing__         = 2,
    __closed__          = 3,
};

}}}