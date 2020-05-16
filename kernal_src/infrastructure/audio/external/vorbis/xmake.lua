
target("vorbis")
    set_languages("c99", "cxx17")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    add_includedirs (".")
    add_files       ("*.cc");
    add_files       ("*.c");
    set_kind        ("static")