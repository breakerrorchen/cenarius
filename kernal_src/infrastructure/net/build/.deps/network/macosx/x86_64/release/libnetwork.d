{
    files = {
        "build/.objs/network/macosx/x86_64/release/src/poller_thread.cc.o",
        "build/.objs/network/macosx/x86_64/release/src/io_curl_stond.cc.o",
        "build/.objs/network/macosx/x86_64/release/benchmark/_start.cc.o",
        "build/.objs/network/macosx/x86_64/release/src/poller.cc.o",
        "build/.objs/network/macosx/x86_64/release/src/io_center.cc.o",
        "build/.objs/network/macosx/x86_64/release/src/__version__.cc.o"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang++",
        {
            "-L/Users/bytedance/Code/Cenarius/kernal_src/source/infrastructure/io/external/libuv_build/mac",
            "-L/Users/bytedance/Code/Cenarius/kernal_src/source/infrastructure/io/external/curl_build/mac/lib",
            "-L/Users/bytedance/Code/Cenarius/kernal_src/source/infrastructure/io/external/mbedtls_build/mac/crypto/library",
            "-L/Users/bytedance/Code/Cenarius/kernal_src/source/infrastructure/io/external/mbedtls_build/mac/library",
            "-Wl,-x",
            "-fvisibility=hidden",
            "-luv_a",
            "-lcurl",
            "-lmbedx509",
            "-lmbedtls",
            "-lmbedcrypto",
            "-shared",
            "-fPIC",
            "-arch",
            "x86_64",
            "-mmacosx-version-min=10.15",
            "-isysroot",
            "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk",
            "-stdlib=libc++",
            "-lz"
        }
    }
}