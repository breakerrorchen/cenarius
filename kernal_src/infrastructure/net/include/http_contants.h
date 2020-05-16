
#pragma once
#include "io_center.h"

namespace cenarius { namespace infrastructure { namespace net {
enum class http_method : uint8_t {
    __options__ ,
    __get__     ,
    __head__    ,
    __post__    ,
    __put__     ,
    __delete__  ,
    __trace__   ,
    __connect__ ,
};


}}}