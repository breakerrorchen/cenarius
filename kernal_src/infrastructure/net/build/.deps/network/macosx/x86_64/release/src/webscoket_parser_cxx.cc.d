{
    depfiles_gcc = "build/.objs/network/macosx/x86_64/release/src/webscoket_parser_cxx.cc.o:   src/webscoket_parser_cxx.cc   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/webscoket_parser_cxx.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/webscoket_parser.h\
",
    files = {
        "src/webscoket_parser_cxx.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/src",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl",
            "-Qunused-arguments",
            "-arch",
            "x86_64",
            "-fpascal-strings",
            "-fmessage-length=0",
            "-mmacosx-version-min=10.15",
            "-isysroot",
            "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk"
        }
    }
}