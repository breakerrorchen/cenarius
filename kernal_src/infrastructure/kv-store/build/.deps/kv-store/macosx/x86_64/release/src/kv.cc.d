{
    files = {
        "src/kv.cc",
        "include/kv.h",
        "external/leveldb/include/leveldb/db.h",
        "external/leveldb/include/leveldb/export.h",
        "external/leveldb/include/leveldb/iterator.h",
        "external/leveldb/include/leveldb/slice.h",
        "external/leveldb/include/leveldb/status.h",
        "external/leveldb/include/leveldb/options.h",
        "external/leveldb/include/leveldb/write_batch.h",
        "include/__version__.h",
        "src/kv.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-std=c++11",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/source/Infrastructure/kv-store/external/leveldb/include",
            "-I/Users/bytedance/Code/Cenarius/kernal_src/source/Infrastructure/kv-store/include",
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