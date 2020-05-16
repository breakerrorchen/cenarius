{
    depfiles_gcc = "build/.objs/archiver/macosx/x86_64/release/src/ora_center.cc.o:   src/ora_center.cc   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/ora_center.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/ora_branch.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/ora_i.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/ora_node.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/ora_bundle.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/include/mmap.h\
",
    files = {
        "src/ora_center.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/archiver/../..",
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