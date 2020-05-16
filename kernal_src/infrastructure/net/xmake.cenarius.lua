
target("cenarius")
    add_includedirs ("external/libuv/include")
    add_includedirs ("external/curl/include/curl")
    add_includedirs ("external/mbedtls/crypto/include")
    add_includedirs ("include")
    add_files       ("src/*.cc")
    add_files       ("src/*.c")

    add_linkdirs    ("external/libs/$(plat)/$(arch)")
    add_links       ("uv_a")
    add_links       ("curl")
    add_links       ("mbedx509")
    add_links       ("mbedtls")
    add_links       ("mbedcrypto")



