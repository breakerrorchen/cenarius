{
    files = {
        "build/.objs/kv-store/macosx/x86_64/release/src/__version__.cc.o",
        "build/.objs/kv-store/macosx/x86_64/release/benchmark/_start.cc.o",
        "build/.objs/kv-store/macosx/x86_64/release/src/kv.cc.o"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang++",
        {
            "-L/Users/bytedance/Code/Cenarius/kernal_src/source/Infrastructure/kv-store/external/leveldb_build/mac",
            "-lleveldb",
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