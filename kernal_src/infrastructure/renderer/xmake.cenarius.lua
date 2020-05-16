
target("cenarius")
    add_includedirs ("external/skia/opengles")
    add_includedirs ("external/skia/opengles/include")
    add_includedirs ("external/skia/opengles/include/atlastest")
    add_includedirs ("external/skia/opengles/include/c")
    add_includedirs ("external/skia/opengles/include/codec")
    add_includedirs ("external/skia/opengles/include/config")
    add_includedirs ("external/skia/opengles/include/core")
    add_includedirs ("external/skia/opengles/include/effects")
    add_includedirs ("external/skia/opengles/include/encode")
    add_includedirs ("external/skia/opengles/include/gpu")
    add_includedirs ("external/skia/opengles/include/gpu/gl")
    add_includedirs ("external/skia/opengles/include/pathops")
    add_includedirs ("external/skia/opengles/include/ports")
    add_includedirs ("external/skia/opengles/include/private")
    add_includedirs ("external/skia/opengles/include/svg")

    add_includedirs (".")
    add_includedirs ("include")
    add_files       ("src/*.cc")
    add_files       ("src/*.c")
    add_files       ("backend/es_render/*.cc")
    add_files       ("backend/es_render/_/*.cc")
    add_linkdirs    ("external/skia/opengles/libs/$(plat)/$(arch)")
    add_links       ("skia")

    if is_plat("android") then
        add_files       ("backend/android/*.cc")
        add_links       ("android", "EGL", "GLESv3")
    elseif is_plat("iphoneos") then
        add_files       ("backend/ios/*.cc")
        add_frameworks  ("OpenGLES", "CoreGraphics", "CoreText")
    end