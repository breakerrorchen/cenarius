{
    depfiles_gcc = "build/.objs/interpreter/macosx/x86_64/release/src/i_javascriptcore_context.cc.o:   src/i_javascriptcore_context.cc   /Users/bytedance/Desktop/interpreter的副本/include/interpreter.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_base.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_initializer.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_vm.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_actuator.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_context.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_release_scope.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_str.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_typedarr_buffer.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_value.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_value_holder.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_object_field.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_object.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_object_holder.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_class_slot.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_parameter.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_invoker.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_invoke_function.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_invoke_connection.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_class.h   /Users/bytedance/Desktop/interpreter的副本/include/i_javascriptcore_bind.h\
",
    files = {
        "src/i_javascriptcore_context.cc"
    },
    values = {
        "/usr/bin/xcrun -sdk macosx clang",
        {
            "-std=c++11",
            "-I/Users/bytedance/Desktop/interpreter的副本/external/v8/mac/include",
            "-I/Users/bytedance/Desktop/interpreter的副本/include",
            "-D__use_javascriptcore_backend__",
            "-framework",
            "JavaScriptCore",
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