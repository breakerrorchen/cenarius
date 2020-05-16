
#include "render_basement.h"
using namespace cenarius;
using namespace infrastructure;
using namespace renderer;
PFNGLGENVERTEXARRAYSOESPROC glGenVertexArraysOESEXT         = 0;
PFNGLBINDVERTEXARRAYOESPROC glBindVertexArrayOESEXT         = 0;
PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArraysOESEXT   = 0;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC 
    glTexImage2DMultisampleOESEXT                           = 0;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC
      glRenderbufferStorageMultisampleOESEXT                = 0;
PFNGLBLITFRAMEBUFFERANGLEPROC glBlitFramebufferOESEXT       = 0;

void render_basement::initializer() {
    static std::once_flag _flag;
    std::call_once(_flag, []() {
        glGenVertexArraysOESEXT = (PFNGLGENVERTEXARRAYSOESPROC)
            ::eglGetProcAddress("glGenVertexArraysOES");
        glBindVertexArrayOESEXT = (PFNGLBINDVERTEXARRAYOESPROC)
            ::eglGetProcAddress("glBindVertexArrayOES");
        glDeleteVertexArraysOESEXT = (PFNGLDELETEVERTEXARRAYSOESPROC)
            ::eglGetProcAddress("glDeleteVertexArraysOES");
        glRenderbufferStorageMultisampleOESEXT =
            (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)
            ::eglGetProcAddress("glRenderbufferStorageMultisampleEXT");
        glBlitFramebufferOESEXT = (PFNGLBLITFRAMEBUFFERANGLEPROC)
            ::eglGetProcAddress("glBlitFramebuffer");
        glTexImage2DMultisampleOESEXT = 
            (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)::eglGetProcAddress(
                "glTexImage2DMultisample");
   });
}