
#pragma once
#include "common/base_header_inct.h"
#include "kernal/cc/care.h"
#include "care_communicate.h"
#include "care_render.h"
#include "care_controller.h"
#include "care_communicate.h"

namespace cenarius { namespace platform {
using namespace kernal;
using namespace cc;
class care_i final : public care {
public:
    std::shared_ptr<care_communicate> communicate() override;
    std::shared_ptr<care_info>        arguments()   override;
    std::shared_ptr<care_render>      render()      override;
    std::shared_ptr<care_controller>  controller()  override;
public:
    std::shared_ptr<care_communicate_i> communicate_;
    std::shared_ptr<care_render_i>      render_;
    std::shared_ptr<care_info>			info_;
    std::shared_ptr<care_controller_i>  controller_;
}; 


}}