{
    depfiles_gcc = "build/.objs/vorbis/macosx/x86_64/release/./synthesis.c.o: synthesis.c   ogg.h os_types.h ivorbiscodec.h codec_internal.h codebook.h registry.h   backends.h misc.h os.h asm_arm.h vorbis_block.h\
",
    files = {
        "synthesis.c"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c99",
            "-I.",
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