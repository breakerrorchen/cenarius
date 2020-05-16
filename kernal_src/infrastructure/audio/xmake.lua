
target("audio")
    set_languages("c99", "cxx11")
    --set_optimize("smallest")ls
    --set_strip("all")
    --set_symbols("hidden")
    add_rules("mode.debug")
    set_kind("binary")


    -- mac leveldb
    add_includedirs ("$(projectdir)/external/fmod/macosx/core/inc/include")
    add_linkdirs    ("$(projectdir)/external/fmod/macosx/core/lib")
    add_rpathdirs   ("$(projectdir)/external/fmod/macosx/core/lib")
    add_links       ("fmod")

    -- src
    add_includedirs ("$(projectdir)/include")
    add_files       ("$(projectdir)/src/*.cc")
    add_files       ("$(projectdir)/benchmark/*.cc")
