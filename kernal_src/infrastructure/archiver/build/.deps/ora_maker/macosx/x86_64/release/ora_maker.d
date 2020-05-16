{
    files = {
        "build/.objs/ora_maker/macosx/x86_64/release/ora_maker/src/start.cc.o"
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