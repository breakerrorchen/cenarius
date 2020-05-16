
#include "common/logger.h"
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

void components::canvas::get_context(js_parameter& parameter) {
    if (parameter.get_argument_count() == 0) return;
    auto _0 = parameter.get_argument_at(0);
    if (!_0.is_str()) return;
    auto _0_str = _0.to_string();
    if (_0_str == "webgl" || _0_str == "experimental-webgl") {
    	components::canvas::get_context_3d(parameter);
    } else if (_0_str == "2d") {
    	components::canvas::get_context_2d(parameter);
    } 
}