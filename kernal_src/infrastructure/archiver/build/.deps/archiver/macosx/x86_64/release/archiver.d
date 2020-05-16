{
    files = {
        "build/.objs/archiver/macosx/x86_64/release/src/ora_center.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/benchmark/_start.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/mmap_creator.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/ora_branch_builder.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/ora_node.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/ora_bundle.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/ora_branch.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/mmap_windows.cc.o",
        "build/.objs/archiver/macosx/x86_64/release/src/mmap_posix.cc.o"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang++",
        {
            "-Wl,-x",
            "-fvisibility=hidden",
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