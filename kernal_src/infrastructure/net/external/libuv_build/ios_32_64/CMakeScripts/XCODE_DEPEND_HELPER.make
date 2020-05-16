# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.uv_a.Debug:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Debug/uv_a.build/$(OBJDIR)/armv7/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Debug/uv_a.build/$(OBJDIR)/armv7s/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Debug/uv_a.build/$(OBJDIR)/arm64/libuv_a.a


PostBuild.uv_a.Release:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Release/uv_a.build/$(OBJDIR)/armv7/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Release/uv_a.build/$(OBJDIR)/armv7s/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/Release/uv_a.build/$(OBJDIR)/arm64/libuv_a.a


PostBuild.uv_a.MinSizeRel:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/MinSizeRel/uv_a.build/$(OBJDIR)/armv7/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/MinSizeRel/uv_a.build/$(OBJDIR)/armv7s/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/MinSizeRel/uv_a.build/$(OBJDIR)/arm64/libuv_a.a


PostBuild.uv_a.RelWithDebInfo:
/Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a:
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/RelWithDebInfo/uv_a.build/$(OBJDIR)/armv7/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/RelWithDebInfo/uv_a.build/$(OBJDIR)/armv7s/libuv_a.a
	/bin/rm -f /Users/bytedance/Code/Cenarius/kernal_src/source/essential/network/external/libuv_build/ios_32_64/libuv.build/RelWithDebInfo/uv_a.build/$(OBJDIR)/arm64/libuv_a.a




# For each target create a dummy ruleso the target does not have to exist
