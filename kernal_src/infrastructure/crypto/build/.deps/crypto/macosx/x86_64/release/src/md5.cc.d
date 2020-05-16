{
    files = {
        "src/md5.cc",
        "include/md5.h",
        "include/__version__.h",
        "src/md5_i.h",
        "src/md5.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/source/infrastructure/crypto/include",
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