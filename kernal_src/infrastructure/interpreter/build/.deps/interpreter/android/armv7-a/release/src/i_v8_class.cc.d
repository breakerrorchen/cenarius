{
    depfiles_gcc = "build/.objs/interpreter/android/armv7-a/release/src/i_v8_class.cc.o:   src/i_v8_class.cc\
",
    files = {
        "src/i_v8_class.cc"
    },
    values = {
        "/Users/bytedance/Code/android-ndk-r20b/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++",
        {
            "-std=c++11",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/interpreter/external/v8/mac/include",
            "-I/Users/bytedance/Desktop/Cenarius/kernal_src/infrastructure/interpreter/include",
            "-D__use_javascriptcore_backend__",
            "-framework",
            "JavaScriptCore",
            "-fPIE",
            "-pie",
            "--sysroot=/Users/bytedance/Code/android-ndk-r20b/sysroot",
            "-isystem",
            "/Users/bytedance/Code/android-ndk-r20b/sysroot/usr/include/arm-linux-androideabi",
            "-I/Users/bytedance/Code/android-ndk-r20b/sources/cxx-stl/llvm-libc++/include",
            "-I/Users/bytedance/Code/android-ndk-r20b/sources/cxx-stl/llvm-libc++/libs/armeabi-v7a/include",
            "-I/Users/bytedance/Code/android-ndk-r20b/sources/cxx-stl/llvm-libc++abi/include",
            "-Qunused-arguments",
            "-mthumb",
            "-target",
            "armv7-none-linux-androideabi",
            "-gcc-toolchain",
            "/Users/bytedance/Code/android-ndk-r20b/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64",
            "-D__ANDROID_API__=21"
        }
    }
}