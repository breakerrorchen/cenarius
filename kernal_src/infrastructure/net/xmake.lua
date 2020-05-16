
target("network")
    set_languages("c99", "cxx11")
    set_optimize("smallest")
    set_strip("all")
    set_symbols("hidden")
    add_rules("mode.release")
    set_kind("binary")

    add_includedirs ("$(projectdir)/include")
    add_includedirs ("$(projectdir)/src")
    add_includedirs ("$(projectdir)/external/mbedtls/crypto/include")
    -- mac libuv
    add_includedirs ("$(projectdir)/external/libuv/include")
    add_linkdirs    ("$(projectdir)/external/libuv_build/mac")
    add_links       ("uv_a")

    --mac libcurl
    add_includedirs ("$(projectdir)/external/curl/include/curl")
    add_linkdirs    ("$(projectdir)/external/curl_build/mac/lib")
    add_links       ("curl")

    --mac mbedtls
    add_linkdirs    ("$(projectdir)/external/mbedtls_build/mac/crypto/library/")
    add_linkdirs    ("$(projectdir)/external/mbedtls_build/mac/library/")
    add_linkdirs    ("$(projectdir)/external/mbedtls_build/mac/library/")
    add_links       ("mbedx509")
    add_links       ("mbedtls")
    add_links       ("mbedcrypto")
    
    

    -- src
    add_files      ("$(projectdir)/src/*.cc")
    add_files      ("$(projectdir)/src/*.c")
    add_files      ("$(projectdir)/benchmark/*.cc")
