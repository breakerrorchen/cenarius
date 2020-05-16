
target("interpreter")
    set_languages("c99", "cxx11")
    --set_optimize("smallest")
    --set_strip("all")
    --set_symbols("hidden")
    add_rules("mode.debug")
    set_kind("binary")

    -- v8
    --add_defines     ("__use_v8_backend__")
    add_includedirs ("$(projectdir)/external/v8/mac/include")
    add_linkdirs    ("$(projectdir)/external/v8/mac/libs")
    add_links       ("v8_libplatform", "v8_libbase", "v8")
    add_rpathdirs   ("$(projectdir)/external/v8/mac/libs")
    add_files       ("$(projectdir)/src/v8/*.cc")

    -- JavaScriptCore
    add_defines("__use_javascriptcore_backend__")
    add_frameworks("JavaScriptCore")

    -- src
    add_includedirs("$(projectdir)/include")
    add_files("$(projectdir)/src/*.cc")
    add_files("$(projectdir)/benchmark/*.cc")


