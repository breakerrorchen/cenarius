
target("css_pattern")
    set_languages("c99", "cxx17")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    set_kind("binary")

    add_includedirs("$(projectdir)/include")
    add_includedirs("$(projectdir)/external/katana-parser/src")
    add_files      ("$(projectdir)/src/*.cc")
    add_files      ("$(projectdir)/external/katana-parser/src/*.c")
    add_files      ("$(projectdir)/benchmark/*.cc")