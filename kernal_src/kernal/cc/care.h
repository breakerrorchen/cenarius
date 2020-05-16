
#pragma once
#include "common/base_header_inct.h"
#include "care_info.h"
#include "care_communicate.h"
#include "care_render.h"
#include "care_controller.h"

namespace cenarius { namespace kernal { namespace cc {
class care {
public:
    virtual ~care() = default;
public:
    virtual std::shared_ptr<care_communicate> communicate() = 0;
    virtual std::shared_ptr<care_info>        arguments()   = 0;
    virtual std::shared_ptr<care_render>      render()      = 0;
    virtual std::shared_ptr<care_controller>  controller()  = 0;
};


}}}