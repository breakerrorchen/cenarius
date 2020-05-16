
target("kv-store")
    set_languages("c99", "cxx11")
    --set_optimize("smallest")ls
    --set_strip("all")
    --set_symbols("hidden")
    add_rules("mode.debug")
    set_kind("binary")


    -- mac leveldb
    add_includedirs ("$(projectdir)/external/leveldb/include")
    add_linkdirs    ("$(projectdir)/external/leveldb_build/mac")
    add_links       ("leveldb")

    -- src
    add_includedirs("$(projectdir)/include")
    add_files("$(projectdir)/src/*.cc")
    add_files("$(projectdir)/benchmark/*.cc")
