{
    files = {
        "build/.objs/ora_maker/macosx/x86_64/release/src/start.cc.o"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang++",
        {
            "-Lexternal/libs/macosx/x86_64",
            "-Wl,-x",
            "-fvisibility=hidden",
            "-lsnappy",
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