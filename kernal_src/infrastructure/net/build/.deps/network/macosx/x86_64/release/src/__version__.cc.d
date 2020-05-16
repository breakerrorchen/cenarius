{
    files = {
        "src/__version__.cc",
        "include/__version__.h",
        "src/__version__.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/cenarius_core/infrastructure/io/include",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/cenarius_core/infrastructure/io/external/libuv/include",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/cenarius_core/infrastructure/io/external/curl/include/curl",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/cenarius_core/infrastructure/io/src",
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