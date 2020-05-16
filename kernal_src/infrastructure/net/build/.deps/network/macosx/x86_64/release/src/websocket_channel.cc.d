{
    depfiles_gcc = "build/.objs/network/macosx/x86_64/release/src/websocket_channel.cc.o:   src/websocket_channel.cc   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/websocket_channel.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/io_center.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/poller_thread.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/poller.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv/errno.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv/version.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv/unix.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv/threadpool.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include/uv/darwin.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/curl.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/curlver.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/system.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/easy.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/multi.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl/urlapi.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/io_committer.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/http_task.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/http_header.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/websocket_related.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/io_sendback.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/http_contants.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/websocket_buffer.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/webscoket_parser_cxx.h   /Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include/webscoket_parser.h\
",
    files = {
        "src/websocket_channel.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-fvisibility=hidden",
            "-Oz",
            "-std=c++11",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/src",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/mbedtls/crypto/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/libuv/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/net/external/curl/include/curl",
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