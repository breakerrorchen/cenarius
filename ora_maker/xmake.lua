
target("ora_maker")
    set_languages("c99", "cxx11")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    set_kind("binary")

    -- 这里是mac系统下面的编译配置。
    -- 需要在windows和linux下面编译snappy
    -- 然后修改链接的路径，就可以得到不同平台的打包器
    add_includedirs("external/filesystem/include")
    add_includedirs("external/snappy")
    add_includedirs("external/libs/macosx/x86_64")
    add_linkdirs   ("external/libs/macosx/x86_64")
    add_links      ("snappy")

    -- src
    add_files("src/*.cc")
    add_files("src/*.c")