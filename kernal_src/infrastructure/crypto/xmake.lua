
target("crypto")
    set_languages("c99", "cxx11")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    set_kind("static")

    add_includedirs("$(projectdir)/include")
    add_files      ("$(projectdir)/src/*.cc")