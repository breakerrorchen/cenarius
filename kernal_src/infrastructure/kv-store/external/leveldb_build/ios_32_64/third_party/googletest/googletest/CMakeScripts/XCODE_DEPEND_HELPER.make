# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.gtest.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest.build/$(OBJDIR)/armv7/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest.build/$(OBJDIR)/armv7s/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest.build/$(OBJDIR)/arm64/libgtestd.a


PostBuild.gtest_main.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtest_maind.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest_main.build/$(OBJDIR)/armv7/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest_main.build/$(OBJDIR)/armv7s/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Debug/gtest_main.build/$(OBJDIR)/arm64/libgtest_maind.a


PostBuild.gtest.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/Release/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a


PostBuild.gtest.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/MinSizeRel/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a


PostBuild.gtest.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/gtest.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a




# For each target create a dummy ruleso the target does not have to exist
