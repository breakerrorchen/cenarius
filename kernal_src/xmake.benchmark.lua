
target("cenarius_benchmark")
    set_languages("c99", "cxx17")

    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")

    set_kind("binary")
    add_cxflags("-fsanitize=address")
    add_ldflags("-fsanitize=address")
    add_shflags("-fsanitize=address")

    
    add_includedirs(".");

    -- src
    add_files      ("benchmark/*.cc")
    add_files      ("kernal/bestead/*.cc")