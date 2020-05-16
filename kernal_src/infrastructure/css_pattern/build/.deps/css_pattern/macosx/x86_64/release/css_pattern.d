{
    files = {
        "build/.objs/css_pattern/macosx/x86_64/release/src/__version__.cc.o",
        "build/.objs/css_pattern/macosx/x86_64/release/src/css_parser_color.cc.o",
        "build/.objs/css_pattern/macosx/x86_64/release/benchmark/_start.cc.o",
        "build/.objs/css_pattern/macosx/x86_64/release/src/css_parser_font.cc.o"
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