{
    depfiles_gcc = "build/.objs/archiver/macosx/x86_64/release/__/mmap/src/mmap_posix.cc.o:   ../mmap/src/mmap_posix.cc ../mmap/src/mmap_posix.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/../mmap/include/mmap.h\
",
    files = {
        "../mmap/src/mmap_posix.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/../mmap/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/src",
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