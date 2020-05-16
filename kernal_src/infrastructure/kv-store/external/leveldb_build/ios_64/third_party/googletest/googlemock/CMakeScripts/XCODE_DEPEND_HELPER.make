# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.gmock.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a


PostBuild.gmock_main.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmock_maind.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmock_maind.a


PostBuild.gtest.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a


PostBuild.gtest_main.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtest_maind.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtest_maind.a


PostBuild.gmock.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a


PostBuild.gmock_main.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock_main.a


PostBuild.gtest.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a


PostBuild.gtest_main.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest_main.a


PostBuild.gmock.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a


PostBuild.gmock_main.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock_main.a


PostBuild.gtest.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a


PostBuild.gtest_main.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest_main.a


PostBuild.gmock.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a


PostBuild.gmock_main.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock_main.a


PostBuild.gtest.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a


PostBuild.gtest_main.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest_main.a




# For each target create a dummy ruleso the target does not have to exist
