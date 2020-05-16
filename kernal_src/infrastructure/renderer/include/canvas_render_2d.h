
#pragma once
#include <assert.h>
#include <stdio.h>
#include <memory>

// for skia
#include "SkPath.h"
#include "SkPaint.h"
#include "SkRegion.h"
#include "SkSurface.h"
#include "SkCanvas.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"
#include "SkPathEffect.h"
#include "SkTextBlob.h"
#include "SkTileMode.h"
#include "SkFontMgr.h"
#include "SkFontMetrics.h"
#include "SkTypeface.h"
#include "GrContext.h"
#include "SkBlurMaskFilter.h"
#include "GrGLDefines.h"
#include "GrGLInterface.h"
#include "GrBackendSurface.h"
#include "SkDashPathEffect.h"
#include "SkLayerDrawLooper.h"
#include "SkDropShadowImageFilter.h"
#include "SkGradientShader.h"
#include "SkDiscretePathEffect.h"
#include "utils/SkTextUtils.h"

namespace cenarius { namespace infrastructure { namespace renderer {
// canvas的2d渲染上下文, 这里采用skia作为默认的渲染器
class canvas_render_2d {
public:
    virtual ~canvas_render_2d() = default;
public:
    // 这里使用skia作为默认的2d渲染器
    virtual SkCanvas* get() = 0;
public:
	virtual void test() = 0;
public:
    sk_sp<GrContext> sk_context_;
};


}}}