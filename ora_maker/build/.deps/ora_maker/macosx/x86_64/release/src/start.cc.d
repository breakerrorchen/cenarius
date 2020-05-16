{
    depfiles_gcc = "build/.objs/ora_maker/macosx/x86_64/release/src/start.cc.o: src/start.cc   external/filesystem/include/ghc/filesystem.hpp   external/snappy/snappy.h   external/libs/macosx/x86_64/snappy-stubs-public.h\
",
    files = {
        "src/start.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-Iexternal/filesystem/include",
            "-Iexternal/snappy",
            "-Iexternal/libs/macosx/x86_64",
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