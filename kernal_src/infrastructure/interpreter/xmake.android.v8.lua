
target("v8_interpreter")
    set_languages("c99", "cxx11")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    --add_rules("mode.debug")
    set_kind("shared")

    -- v8
    add_defines     ("__use_v8_backend__")
    add_includedirs ("external/v8/android/v8.7.2.100/include")
    add_linkdirs    ("external/v8/android/v8.7.2.100/libs/$(arch)")
    add_links       ("v8_libplatform", "v8_base", "v8_libbase", "v8_snapshot")
    add_links       ("v8_libsampler", "v8_init", "v8_initializers")

    -- src
    add_includedirs("include")
    add_files("src/*.cc")


