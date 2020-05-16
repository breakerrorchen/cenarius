# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.uv.Debug:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv.dylib:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv.dylib


PostBuild.uv_a.Debug:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a


PostBuild.uv_run_tests.Debug:
PostBuild.uv.Debug: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests


PostBuild.uv_run_tests_a.Debug:
PostBuild.uv_a.Debug: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a


PostBuild.uv.Release:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv.dylib:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv.dylib


PostBuild.uv_a.Release:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a


PostBuild.uv_run_tests.Release:
PostBuild.uv.Release: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests


PostBuild.uv_run_tests_a.Release:
PostBuild.uv_a.Release: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a


PostBuild.uv.MinSizeRel:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv.dylib:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv.dylib


PostBuild.uv_a.MinSizeRel:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a


PostBuild.uv_run_tests.MinSizeRel:
PostBuild.uv.MinSizeRel: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests


PostBuild.uv_run_tests_a.MinSizeRel:
PostBuild.uv_a.MinSizeRel: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a


PostBuild.uv.RelWithDebInfo:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv.dylib:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv.dylib


PostBuild.uv_a.RelWithDebInfo:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a


PostBuild.uv_run_tests.RelWithDebInfo:
PostBuild.uv.RelWithDebInfo: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests.app/uv_run_tests


PostBuild.uv_run_tests_a.RelWithDebInfo:
PostBuild.uv_a.RelWithDebInfo: /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a:\
	/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/uv_run_tests_a.app/uv_run_tests_a




# For each target create a dummy ruleso the target does not have to exist
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv.1.0.0.dylib:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/iossim_32/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
