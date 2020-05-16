
target("archiver")
    set_languages("c99", "cxx11")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    set_kind("binary")

    -- 这个项目目前单独编译会依赖mmap模块
    -- 这里简单的处理一下
    add_includedirs ("$(projectdir)/../../")
    add_includedirs ("$(projectdir)/../mmap/include")
    add_files       ("$(projectdir)/../mmap/src/*.cc")

    -- include
    add_includedirs ("$(projectdir)/include")
    add_includedirs ("$(projectdir)/src")

    -- src
    add_files      ("$(projectdir)/benchmark/*.cc")
    add_files      ("$(projectdir)/src/*.cc")
    add_files      ("$(projectdir)/src/*.c")