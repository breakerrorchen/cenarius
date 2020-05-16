
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>

#include "backend/es_render/connector.h"
namespace cenarius { namespace infrastructure { namespace renderer {
// canvas的3d渲染上下文, 这里采用es_render的接口作为渲染上下文
class canvas_render_3d : public render_connector {
public:
    virtual ~canvas_render_3d() = default;
public:
};


}}}