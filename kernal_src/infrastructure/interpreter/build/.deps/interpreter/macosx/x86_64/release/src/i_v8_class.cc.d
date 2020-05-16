{
    depfiles_gcc = "build/.objs/interpreter/macosx/x86_64/release/src/i_v8_class.cc.o:   src/i_v8_class.cc\
",
    files = {
        "src/i_v8_class.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-std=c++11",
            "-I/Users/bytedance/Desktop/interpreter的副本/external/v8/mac/include",
            "-I/Users/bytedance/Desktop/interpreter的副本/include",
            "-D__use_javascriptcore_backend__",
            "-framework",
            "JavaScriptCore",
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