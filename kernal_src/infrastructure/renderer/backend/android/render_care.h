
#pragma once
#include <assert.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <algorithm>
#include <atomic>
#include <stack>
#include <set>
#include <memory>
#include <future>
#include <mutex>
#include <atomic>
#include <condition_variable>

// skia
#include "GrGLDefines.h"
#include "GrContext.h"
#include "GrGLInterface.h"
#include "GrBackendSurface.h"

#include "SkPath.h"
#include "SkPaint.h"
#include "SkRegion.h"
#include "SkSurface.h"
#include "SkCanvas.h"
#include "SkPathEffect.h"
#include "SkTextBlob.h"
#include "SkFontMgr.h"
#include "SkTypeface.h"

// #include "SkBlurMaskFilter.h"
// #include "SkDashPathEffect.h"
// #include "SkLayerDrawLooper.h"
// #include "SkDropShadowImageFilter.h"
// #include "SkGradientShader.h"
// #include "SkDiscretePathEffect.h"

// android
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/looper.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <GLES2/gl2platform.h>
#include <GLES3/gl31.h>
#include <GLES3/gl32.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>
#include <GLES3/gl3platform.h>


#define glClearDepth                        glClearDepthf
#define glDeleteVertexArrays                glDeleteVertexArraysOES
#define glGenVertexArrays                   glGenVertexArraysOES
#define glBindVertexArray                   glBindVertexArrayOES
#define GL_VERTEX_ARRAY_BINDING             GL_VERTEX_ARRAY_BINDING_OES
#define glMapBuffer                         glMapBufferOES
#define glUnmapBuffer                       glUnmapBufferOES
#define glRenderbufferStorageMultisample    glRenderbufferStorageMultisampleOES
#define glBlitFramebuffer                   glBlitFramebufferOES
#define glCompressedTexImage3D              glCompressedTexImage3DOES
#define GL_RGBA8                            GL_RGBA8_OES
#define GL_DEPTH24_STENCIL8                 GL_DEPTH24_STENCIL8_OES
#define GL_DEPTH_COMPONENT24                GL_DEPTH_COMPONENT24_OES
#define GL_WRITE_ONLY                       GL_WRITE_ONLY_OES
#define GL_READ_FRAMEBUFFER                 GL_READ_FRAMEBUFFER_ANGLE
#define GL_DRAW_FRAMEBUFFER                 GL_DRAW_FRAMEBUFFER_ANGLE
#define GL_READ_FRAMEBUFFER_BINDING         GL_READ_FRAMEBUFFER_BINDING_ANGLE
#define GL_DRAW_FRAMEBUFFER_BINDING         GL_DRAW_FRAMEBUFFER_BINDING_ANGLE

// GL_GLEXT_PROTOTYPES isn't defined in glplatform.h on android ndk r7
// we manually define it here

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES 1
#endif

// gl2.h doesn't define GLchar on Android
typedef char GLchar;

// android defines GL_BGRA_EXT but not GL_BRGA
#ifndef GL_BGRA
#define GL_BGRA  0x80E1
#endif

//declare here while define in
extern PFNGLGENVERTEXARRAYSOESPROC                  glGenVertexArraysOESEXT;
extern PFNGLBINDVERTEXARRAYOESPROC                  glBindVertexArrayOESEXT;
extern PFNGLDELETEVERTEXARRAYSOESPROC               glDeleteVertexArraysOESEXT;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC      glRenderbufferStorageMultisampleOESEXT;
extern PFNGLBLITFRAMEBUFFERANGLEPROC                glBlitFramebufferOESEXT;
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC             glTexImage2DMultisampleOESEXT;
#define glGenVertexArraysOES                        glGenVertexArraysOESEXT
#define glBindVertexArrayOES                        glBindVertexArrayOESEXT
#define glDeleteVertexArraysOES                     glDeleteVertexArraysOESEXT
#define glRenderbufferStorageMultisampleOES         glRenderbufferStorageMultisampleOESEXT
#define glBlitFramebufferOES                        glBlitFramebufferOESEXT
#define glTexImage2DMultisample                     glTexImage2DMultisampleOESEXT;