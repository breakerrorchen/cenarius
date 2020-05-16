
#include "extension_embeder.h"
#include "misc/console.h"
#include "misc/performance.h"
#include "timer/_.h"
#include "graphics/_.h"
#include "graphics/canvas/_.h"
#include "graphics/render_context_2d/_.h"
#include "graphics/render_context_2d_gradient/_.h"
#include "graphics/render_context_2d_pattern/_.h"
#include "graphics/render_context_3d/_.h"
#include "graphics/render_context_3d_active_info/_.h"
#include "graphics/render_context_3d_buffer/_.h"
#include "graphics/render_context_3d_constants/_.h"
#include "graphics/render_context_3d_framebuffer/_.h"
#include "graphics/render_context_3d_program/_.h"
#include "graphics/render_context_3d_renderbuffer/_.h"
#include "graphics/render_context_3d_shader/_.h"
#include "graphics/render_context_3d_shader_precison/_.h"
#include "graphics/render_context_3d_texture/_.h"
#include "graphics/render_context_3d_uniform_location/_.h"
#include "image/_.h"
#include "image_data/_.h"
#include "lifecycle/_.h"
#include "storage/_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;

extension_embeder::extension_embeder(js_actuator& actuator)
    : actuator_(actuator) {
    ;
}

/**
 * 除去global对象外，还构建一个全局的cenarius对象, __cc__是别名
 * cenarius用来提供模拟小游戏的扩展接口
 * */
void extension_embeder::build(js_object& global_object) {
    js_release_scope __release_scope__(actuator_);
    auto _context = actuator_.get_context();
    auto _cenarius = js_object::create(_context);
    global_object["cenarius"] = _cenarius;
    global_object["__cc__"  ] = _cenarius;

#define __extension_outlet__(ctx, obj, cls)                                         \
    components::cls::outlet(ctx, obj);
    __extension_outlet__(_context, global_object, console                           )
    __extension_outlet__(_context, _cenarius    , lifecycle                         )
    __extension_outlet__(_context, _cenarius    , graphics                          )
    __extension_outlet__(_context, global_object, canvas                            )
    __extension_outlet__(_context, global_object, render_context_2d                 )
    __extension_outlet__(_context, global_object, render_context_2d_gradient        )
    __extension_outlet__(_context, global_object, render_context_2d_pattern         )
    __extension_outlet__(_context, global_object, render_context_3d                 )
    __extension_outlet__(_context, global_object, render_context_3d_active_info     )
    __extension_outlet__(_context, global_object, render_context_3d_buffer          )
    __extension_outlet__(_context, global_object, render_context_3d_constants       )
    __extension_outlet__(_context, global_object, render_context_3d_framebuffer     )
    __extension_outlet__(_context, global_object, render_context_3d_program         )
    __extension_outlet__(_context, global_object, render_context_3d_renderbuffer    )
    __extension_outlet__(_context, global_object, render_context_3d_shader          )
    __extension_outlet__(_context, global_object, render_context_3d_shader_precison )
    __extension_outlet__(_context, global_object, render_context_3d_texture         )
    __extension_outlet__(_context, global_object, render_context_3d_uniform_location)
    __extension_outlet__(_context, global_object, image                             )
    __extension_outlet__(_context, global_object, image_data                        )
    __extension_outlet__(_context, global_object, timer                             )
    __extension_outlet__(_context, global_object, performance                       )
    __extension_outlet__(_context, global_object, local_storage                     )
#undef __extension_outlet__
}