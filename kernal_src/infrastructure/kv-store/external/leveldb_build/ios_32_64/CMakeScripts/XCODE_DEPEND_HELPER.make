# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.arena_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/arena_test.build/$(OBJDIR)/armv7/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/arena_test.build/$(OBJDIR)/armv7s/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/arena_test.build/$(OBJDIR)/arm64/arena_test


PostBuild.autocompact_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/autocompact_test.build/$(OBJDIR)/armv7/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/autocompact_test.build/$(OBJDIR)/armv7s/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/autocompact_test.build/$(OBJDIR)/arm64/autocompact_test


PostBuild.bloom_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/bloom_test.build/$(OBJDIR)/armv7/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/bloom_test.build/$(OBJDIR)/armv7s/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/bloom_test.build/$(OBJDIR)/arm64/bloom_test


PostBuild.c_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/c_test.build/$(OBJDIR)/armv7/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/c_test.build/$(OBJDIR)/armv7s/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/c_test.build/$(OBJDIR)/arm64/c_test


PostBuild.cache_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/cache_test.build/$(OBJDIR)/armv7/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/cache_test.build/$(OBJDIR)/armv7s/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/cache_test.build/$(OBJDIR)/arm64/cache_test


PostBuild.coding_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/coding_test.build/$(OBJDIR)/armv7/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/coding_test.build/$(OBJDIR)/armv7s/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/coding_test.build/$(OBJDIR)/arm64/coding_test


PostBuild.corruption_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/corruption_test.build/$(OBJDIR)/armv7/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/corruption_test.build/$(OBJDIR)/armv7s/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/corruption_test.build/$(OBJDIR)/arm64/corruption_test


PostBuild.crc32c_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/crc32c_test.build/$(OBJDIR)/armv7/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/crc32c_test.build/$(OBJDIR)/armv7s/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/crc32c_test.build/$(OBJDIR)/arm64/crc32c_test


PostBuild.db_bench.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench.build/$(OBJDIR)/armv7/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench.build/$(OBJDIR)/armv7s/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench.build/$(OBJDIR)/arm64/db_bench


PostBuild.db_bench_sqlite3.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench_sqlite3.build/$(OBJDIR)/armv7/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench_sqlite3.build/$(OBJDIR)/armv7s/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_bench_sqlite3.build/$(OBJDIR)/arm64/db_bench_sqlite3


PostBuild.db_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_test.build/$(OBJDIR)/armv7/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_test.build/$(OBJDIR)/armv7s/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/db_test.build/$(OBJDIR)/arm64/db_test


PostBuild.dbformat_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/dbformat_test.build/$(OBJDIR)/armv7/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/dbformat_test.build/$(OBJDIR)/armv7s/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/dbformat_test.build/$(OBJDIR)/arm64/dbformat_test


PostBuild.env_posix_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_posix_test.build/$(OBJDIR)/armv7/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_posix_test.build/$(OBJDIR)/armv7s/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_posix_test.build/$(OBJDIR)/arm64/env_posix_test


PostBuild.env_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_test.build/$(OBJDIR)/armv7/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_test.build/$(OBJDIR)/armv7s/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/env_test.build/$(OBJDIR)/arm64/env_test


PostBuild.fault_injection_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/fault_injection_test.build/$(OBJDIR)/armv7/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/fault_injection_test.build/$(OBJDIR)/armv7s/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/fault_injection_test.build/$(OBJDIR)/arm64/fault_injection_test


PostBuild.filename_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filename_test.build/$(OBJDIR)/armv7/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filename_test.build/$(OBJDIR)/armv7s/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filename_test.build/$(OBJDIR)/arm64/filename_test


PostBuild.filter_block_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filter_block_test.build/$(OBJDIR)/armv7/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filter_block_test.build/$(OBJDIR)/armv7s/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/filter_block_test.build/$(OBJDIR)/arm64/filter_block_test


PostBuild.gmock.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock.build/$(OBJDIR)/armv7/libgmockd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock.build/$(OBJDIR)/armv7s/libgmockd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock.build/$(OBJDIR)/arm64/libgmockd.a


PostBuild.gmock_main.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmock_maind.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmock_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock_main.build/$(OBJDIR)/armv7/libgmock_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock_main.build/$(OBJDIR)/armv7s/libgmock_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Debug/gmock_main.build/$(OBJDIR)/arm64/libgmock_maind.a


PostBuild.gtest.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest.build/$(OBJDIR)/armv7/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest.build/$(OBJDIR)/armv7s/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest.build/$(OBJDIR)/arm64/libgtestd.a


PostBuild.gtest_main.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtest_maind.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest_main.build/$(OBJDIR)/armv7/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest_main.build/$(OBJDIR)/armv7s/libgtest_maind.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Debug/gtest_main.build/$(OBJDIR)/arm64/libgtest_maind.a


PostBuild.hash_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/hash_test.build/$(OBJDIR)/armv7/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/hash_test.build/$(OBJDIR)/armv7s/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/hash_test.build/$(OBJDIR)/arm64/hash_test


PostBuild.issue178_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue178_test.build/$(OBJDIR)/armv7/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue178_test.build/$(OBJDIR)/armv7s/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue178_test.build/$(OBJDIR)/arm64/issue178_test


PostBuild.issue200_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue200_test.build/$(OBJDIR)/armv7/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue200_test.build/$(OBJDIR)/armv7s/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue200_test.build/$(OBJDIR)/arm64/issue200_test


PostBuild.issue320_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue320_test.build/$(OBJDIR)/armv7/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue320_test.build/$(OBJDIR)/armv7s/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/issue320_test.build/$(OBJDIR)/arm64/issue320_test


PostBuild.leveldb.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldb.build/$(OBJDIR)/armv7/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldb.build/$(OBJDIR)/armv7s/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldb.build/$(OBJDIR)/arm64/libleveldb.a


PostBuild.leveldbutil.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldbutil.build/$(OBJDIR)/armv7/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldbutil.build/$(OBJDIR)/armv7s/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/leveldbutil.build/$(OBJDIR)/arm64/leveldbutil


PostBuild.log_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/log_test.build/$(OBJDIR)/armv7/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/log_test.build/$(OBJDIR)/armv7s/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/log_test.build/$(OBJDIR)/arm64/log_test


PostBuild.logging_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/logging_test.build/$(OBJDIR)/armv7/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/logging_test.build/$(OBJDIR)/armv7s/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/logging_test.build/$(OBJDIR)/arm64/logging_test


PostBuild.memenv_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/memenv_test.build/$(OBJDIR)/armv7/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/memenv_test.build/$(OBJDIR)/armv7s/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/memenv_test.build/$(OBJDIR)/arm64/memenv_test


PostBuild.no_destructor_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/no_destructor_test.build/$(OBJDIR)/armv7/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/no_destructor_test.build/$(OBJDIR)/armv7s/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/no_destructor_test.build/$(OBJDIR)/arm64/no_destructor_test


PostBuild.recovery_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/recovery_test.build/$(OBJDIR)/armv7/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/recovery_test.build/$(OBJDIR)/armv7s/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/recovery_test.build/$(OBJDIR)/arm64/recovery_test


PostBuild.skiplist_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/skiplist_test.build/$(OBJDIR)/armv7/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/skiplist_test.build/$(OBJDIR)/armv7s/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/skiplist_test.build/$(OBJDIR)/arm64/skiplist_test


PostBuild.status_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/status_test.build/$(OBJDIR)/armv7/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/status_test.build/$(OBJDIR)/armv7s/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/status_test.build/$(OBJDIR)/arm64/status_test


PostBuild.table_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/table_test.build/$(OBJDIR)/armv7/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/table_test.build/$(OBJDIR)/armv7s/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/table_test.build/$(OBJDIR)/arm64/table_test


PostBuild.version_edit_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_edit_test.build/$(OBJDIR)/armv7/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_edit_test.build/$(OBJDIR)/armv7s/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_edit_test.build/$(OBJDIR)/arm64/version_edit_test


PostBuild.version_set_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_set_test.build/$(OBJDIR)/armv7/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_set_test.build/$(OBJDIR)/armv7s/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/version_set_test.build/$(OBJDIR)/arm64/version_set_test


PostBuild.write_batch_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/write_batch_test.build/$(OBJDIR)/armv7/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/write_batch_test.build/$(OBJDIR)/armv7s/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Debug/write_batch_test.build/$(OBJDIR)/arm64/write_batch_test


PostBuild.arena_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/arena_test.build/$(OBJDIR)/armv7/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/arena_test.build/$(OBJDIR)/armv7s/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/arena_test.build/$(OBJDIR)/arm64/arena_test


PostBuild.autocompact_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/autocompact_test.build/$(OBJDIR)/armv7/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/autocompact_test.build/$(OBJDIR)/armv7s/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/autocompact_test.build/$(OBJDIR)/arm64/autocompact_test


PostBuild.bloom_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/bloom_test.build/$(OBJDIR)/armv7/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/bloom_test.build/$(OBJDIR)/armv7s/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/bloom_test.build/$(OBJDIR)/arm64/bloom_test


PostBuild.c_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/c_test.build/$(OBJDIR)/armv7/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/c_test.build/$(OBJDIR)/armv7s/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/c_test.build/$(OBJDIR)/arm64/c_test


PostBuild.cache_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/cache_test.build/$(OBJDIR)/armv7/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/cache_test.build/$(OBJDIR)/armv7s/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/cache_test.build/$(OBJDIR)/arm64/cache_test


PostBuild.coding_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/coding_test.build/$(OBJDIR)/armv7/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/coding_test.build/$(OBJDIR)/armv7s/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/coding_test.build/$(OBJDIR)/arm64/coding_test


PostBuild.corruption_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/corruption_test.build/$(OBJDIR)/armv7/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/corruption_test.build/$(OBJDIR)/armv7s/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/corruption_test.build/$(OBJDIR)/arm64/corruption_test


PostBuild.crc32c_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/crc32c_test.build/$(OBJDIR)/armv7/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/crc32c_test.build/$(OBJDIR)/armv7s/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/crc32c_test.build/$(OBJDIR)/arm64/crc32c_test


PostBuild.db_bench.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench.build/$(OBJDIR)/armv7/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench.build/$(OBJDIR)/armv7s/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench.build/$(OBJDIR)/arm64/db_bench


PostBuild.db_bench_sqlite3.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench_sqlite3.build/$(OBJDIR)/armv7/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench_sqlite3.build/$(OBJDIR)/armv7s/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_bench_sqlite3.build/$(OBJDIR)/arm64/db_bench_sqlite3


PostBuild.db_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_test.build/$(OBJDIR)/armv7/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_test.build/$(OBJDIR)/armv7s/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/db_test.build/$(OBJDIR)/arm64/db_test


PostBuild.dbformat_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/dbformat_test.build/$(OBJDIR)/armv7/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/dbformat_test.build/$(OBJDIR)/armv7s/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/dbformat_test.build/$(OBJDIR)/arm64/dbformat_test


PostBuild.env_posix_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_posix_test.build/$(OBJDIR)/armv7/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_posix_test.build/$(OBJDIR)/armv7s/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_posix_test.build/$(OBJDIR)/arm64/env_posix_test


PostBuild.env_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_test.build/$(OBJDIR)/armv7/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_test.build/$(OBJDIR)/armv7s/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/env_test.build/$(OBJDIR)/arm64/env_test


PostBuild.fault_injection_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/fault_injection_test.build/$(OBJDIR)/armv7/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/fault_injection_test.build/$(OBJDIR)/armv7s/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/fault_injection_test.build/$(OBJDIR)/arm64/fault_injection_test


PostBuild.filename_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filename_test.build/$(OBJDIR)/armv7/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filename_test.build/$(OBJDIR)/armv7s/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filename_test.build/$(OBJDIR)/arm64/filename_test


PostBuild.filter_block_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filter_block_test.build/$(OBJDIR)/armv7/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filter_block_test.build/$(OBJDIR)/armv7s/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/filter_block_test.build/$(OBJDIR)/arm64/filter_block_test


PostBuild.gmock.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock.build/$(OBJDIR)/armv7/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock.build/$(OBJDIR)/armv7s/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock.build/$(OBJDIR)/arm64/libgmock.a


PostBuild.gmock_main.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock_main.build/$(OBJDIR)/armv7/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock_main.build/$(OBJDIR)/armv7s/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/Release/gmock_main.build/$(OBJDIR)/arm64/libgmock_main.a


PostBuild.gtest.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/Release/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a


PostBuild.hash_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/hash_test.build/$(OBJDIR)/armv7/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/hash_test.build/$(OBJDIR)/armv7s/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/hash_test.build/$(OBJDIR)/arm64/hash_test


PostBuild.issue178_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue178_test.build/$(OBJDIR)/armv7/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue178_test.build/$(OBJDIR)/armv7s/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue178_test.build/$(OBJDIR)/arm64/issue178_test


PostBuild.issue200_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue200_test.build/$(OBJDIR)/armv7/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue200_test.build/$(OBJDIR)/armv7s/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue200_test.build/$(OBJDIR)/arm64/issue200_test


PostBuild.issue320_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue320_test.build/$(OBJDIR)/armv7/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue320_test.build/$(OBJDIR)/armv7s/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/issue320_test.build/$(OBJDIR)/arm64/issue320_test


PostBuild.leveldb.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldb.build/$(OBJDIR)/armv7/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldb.build/$(OBJDIR)/armv7s/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldb.build/$(OBJDIR)/arm64/libleveldb.a


PostBuild.leveldbutil.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldbutil.build/$(OBJDIR)/armv7/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldbutil.build/$(OBJDIR)/armv7s/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/leveldbutil.build/$(OBJDIR)/arm64/leveldbutil


PostBuild.log_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/log_test.build/$(OBJDIR)/armv7/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/log_test.build/$(OBJDIR)/armv7s/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/log_test.build/$(OBJDIR)/arm64/log_test


PostBuild.logging_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/logging_test.build/$(OBJDIR)/armv7/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/logging_test.build/$(OBJDIR)/armv7s/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/logging_test.build/$(OBJDIR)/arm64/logging_test


PostBuild.memenv_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/memenv_test.build/$(OBJDIR)/armv7/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/memenv_test.build/$(OBJDIR)/armv7s/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/memenv_test.build/$(OBJDIR)/arm64/memenv_test


PostBuild.no_destructor_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/no_destructor_test.build/$(OBJDIR)/armv7/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/no_destructor_test.build/$(OBJDIR)/armv7s/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/no_destructor_test.build/$(OBJDIR)/arm64/no_destructor_test


PostBuild.recovery_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/recovery_test.build/$(OBJDIR)/armv7/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/recovery_test.build/$(OBJDIR)/armv7s/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/recovery_test.build/$(OBJDIR)/arm64/recovery_test


PostBuild.skiplist_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/skiplist_test.build/$(OBJDIR)/armv7/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/skiplist_test.build/$(OBJDIR)/armv7s/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/skiplist_test.build/$(OBJDIR)/arm64/skiplist_test


PostBuild.status_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/status_test.build/$(OBJDIR)/armv7/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/status_test.build/$(OBJDIR)/armv7s/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/status_test.build/$(OBJDIR)/arm64/status_test


PostBuild.table_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/table_test.build/$(OBJDIR)/armv7/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/table_test.build/$(OBJDIR)/armv7s/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/table_test.build/$(OBJDIR)/arm64/table_test


PostBuild.version_edit_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_edit_test.build/$(OBJDIR)/armv7/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_edit_test.build/$(OBJDIR)/armv7s/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_edit_test.build/$(OBJDIR)/arm64/version_edit_test


PostBuild.version_set_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_set_test.build/$(OBJDIR)/armv7/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_set_test.build/$(OBJDIR)/armv7s/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/version_set_test.build/$(OBJDIR)/arm64/version_set_test


PostBuild.write_batch_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/write_batch_test.build/$(OBJDIR)/armv7/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/write_batch_test.build/$(OBJDIR)/armv7s/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/Release/write_batch_test.build/$(OBJDIR)/arm64/write_batch_test


PostBuild.arena_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/arena_test.build/$(OBJDIR)/armv7/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/arena_test.build/$(OBJDIR)/armv7s/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/arena_test.build/$(OBJDIR)/arm64/arena_test


PostBuild.autocompact_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/autocompact_test.build/$(OBJDIR)/armv7/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/autocompact_test.build/$(OBJDIR)/armv7s/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/autocompact_test.build/$(OBJDIR)/arm64/autocompact_test


PostBuild.bloom_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/bloom_test.build/$(OBJDIR)/armv7/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/bloom_test.build/$(OBJDIR)/armv7s/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/bloom_test.build/$(OBJDIR)/arm64/bloom_test


PostBuild.c_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/c_test.build/$(OBJDIR)/armv7/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/c_test.build/$(OBJDIR)/armv7s/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/c_test.build/$(OBJDIR)/arm64/c_test


PostBuild.cache_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/cache_test.build/$(OBJDIR)/armv7/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/cache_test.build/$(OBJDIR)/armv7s/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/cache_test.build/$(OBJDIR)/arm64/cache_test


PostBuild.coding_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/coding_test.build/$(OBJDIR)/armv7/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/coding_test.build/$(OBJDIR)/armv7s/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/coding_test.build/$(OBJDIR)/arm64/coding_test


PostBuild.corruption_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/corruption_test.build/$(OBJDIR)/armv7/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/corruption_test.build/$(OBJDIR)/armv7s/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/corruption_test.build/$(OBJDIR)/arm64/corruption_test


PostBuild.crc32c_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/crc32c_test.build/$(OBJDIR)/armv7/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/crc32c_test.build/$(OBJDIR)/armv7s/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/crc32c_test.build/$(OBJDIR)/arm64/crc32c_test


PostBuild.db_bench.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench.build/$(OBJDIR)/armv7/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench.build/$(OBJDIR)/armv7s/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench.build/$(OBJDIR)/arm64/db_bench


PostBuild.db_bench_sqlite3.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench_sqlite3.build/$(OBJDIR)/armv7/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench_sqlite3.build/$(OBJDIR)/armv7s/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_bench_sqlite3.build/$(OBJDIR)/arm64/db_bench_sqlite3


PostBuild.db_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_test.build/$(OBJDIR)/armv7/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_test.build/$(OBJDIR)/armv7s/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/db_test.build/$(OBJDIR)/arm64/db_test


PostBuild.dbformat_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/dbformat_test.build/$(OBJDIR)/armv7/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/dbformat_test.build/$(OBJDIR)/armv7s/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/dbformat_test.build/$(OBJDIR)/arm64/dbformat_test


PostBuild.env_posix_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_posix_test.build/$(OBJDIR)/armv7/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_posix_test.build/$(OBJDIR)/armv7s/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_posix_test.build/$(OBJDIR)/arm64/env_posix_test


PostBuild.env_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_test.build/$(OBJDIR)/armv7/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_test.build/$(OBJDIR)/armv7s/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/env_test.build/$(OBJDIR)/arm64/env_test


PostBuild.fault_injection_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/fault_injection_test.build/$(OBJDIR)/armv7/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/fault_injection_test.build/$(OBJDIR)/armv7s/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/fault_injection_test.build/$(OBJDIR)/arm64/fault_injection_test


PostBuild.filename_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filename_test.build/$(OBJDIR)/armv7/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filename_test.build/$(OBJDIR)/armv7s/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filename_test.build/$(OBJDIR)/arm64/filename_test


PostBuild.filter_block_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filter_block_test.build/$(OBJDIR)/armv7/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filter_block_test.build/$(OBJDIR)/armv7s/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/filter_block_test.build/$(OBJDIR)/arm64/filter_block_test


PostBuild.gmock.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock.build/$(OBJDIR)/armv7/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock.build/$(OBJDIR)/armv7s/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock.build/$(OBJDIR)/arm64/libgmock.a


PostBuild.gmock_main.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock_main.build/$(OBJDIR)/armv7/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock_main.build/$(OBJDIR)/armv7s/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/MinSizeRel/gmock_main.build/$(OBJDIR)/arm64/libgmock_main.a


PostBuild.gtest.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/MinSizeRel/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a


PostBuild.hash_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/hash_test.build/$(OBJDIR)/armv7/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/hash_test.build/$(OBJDIR)/armv7s/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/hash_test.build/$(OBJDIR)/arm64/hash_test


PostBuild.issue178_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue178_test.build/$(OBJDIR)/armv7/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue178_test.build/$(OBJDIR)/armv7s/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue178_test.build/$(OBJDIR)/arm64/issue178_test


PostBuild.issue200_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue200_test.build/$(OBJDIR)/armv7/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue200_test.build/$(OBJDIR)/armv7s/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue200_test.build/$(OBJDIR)/arm64/issue200_test


PostBuild.issue320_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue320_test.build/$(OBJDIR)/armv7/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue320_test.build/$(OBJDIR)/armv7s/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/issue320_test.build/$(OBJDIR)/arm64/issue320_test


PostBuild.leveldb.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldb.build/$(OBJDIR)/armv7/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldb.build/$(OBJDIR)/armv7s/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldb.build/$(OBJDIR)/arm64/libleveldb.a


PostBuild.leveldbutil.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldbutil.build/$(OBJDIR)/armv7/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldbutil.build/$(OBJDIR)/armv7s/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/leveldbutil.build/$(OBJDIR)/arm64/leveldbutil


PostBuild.log_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/log_test.build/$(OBJDIR)/armv7/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/log_test.build/$(OBJDIR)/armv7s/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/log_test.build/$(OBJDIR)/arm64/log_test


PostBuild.logging_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/logging_test.build/$(OBJDIR)/armv7/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/logging_test.build/$(OBJDIR)/armv7s/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/logging_test.build/$(OBJDIR)/arm64/logging_test


PostBuild.memenv_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/memenv_test.build/$(OBJDIR)/armv7/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/memenv_test.build/$(OBJDIR)/armv7s/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/memenv_test.build/$(OBJDIR)/arm64/memenv_test


PostBuild.no_destructor_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/no_destructor_test.build/$(OBJDIR)/armv7/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/no_destructor_test.build/$(OBJDIR)/armv7s/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/no_destructor_test.build/$(OBJDIR)/arm64/no_destructor_test


PostBuild.recovery_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/recovery_test.build/$(OBJDIR)/armv7/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/recovery_test.build/$(OBJDIR)/armv7s/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/recovery_test.build/$(OBJDIR)/arm64/recovery_test


PostBuild.skiplist_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/skiplist_test.build/$(OBJDIR)/armv7/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/skiplist_test.build/$(OBJDIR)/armv7s/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/skiplist_test.build/$(OBJDIR)/arm64/skiplist_test


PostBuild.status_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/status_test.build/$(OBJDIR)/armv7/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/status_test.build/$(OBJDIR)/armv7s/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/status_test.build/$(OBJDIR)/arm64/status_test


PostBuild.table_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/table_test.build/$(OBJDIR)/armv7/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/table_test.build/$(OBJDIR)/armv7s/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/table_test.build/$(OBJDIR)/arm64/table_test


PostBuild.version_edit_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_edit_test.build/$(OBJDIR)/armv7/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_edit_test.build/$(OBJDIR)/armv7s/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_edit_test.build/$(OBJDIR)/arm64/version_edit_test


PostBuild.version_set_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_set_test.build/$(OBJDIR)/armv7/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_set_test.build/$(OBJDIR)/armv7s/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/version_set_test.build/$(OBJDIR)/arm64/version_set_test


PostBuild.write_batch_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/write_batch_test.build/$(OBJDIR)/armv7/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/write_batch_test.build/$(OBJDIR)/armv7s/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/MinSizeRel/write_batch_test.build/$(OBJDIR)/arm64/write_batch_test


PostBuild.arena_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/arena_test.build/$(OBJDIR)/armv7/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/arena_test.build/$(OBJDIR)/armv7s/arena_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/arena_test.build/$(OBJDIR)/arm64/arena_test


PostBuild.autocompact_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/autocompact_test.build/$(OBJDIR)/armv7/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/autocompact_test.build/$(OBJDIR)/armv7s/autocompact_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/autocompact_test.build/$(OBJDIR)/arm64/autocompact_test


PostBuild.bloom_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/bloom_test.build/$(OBJDIR)/armv7/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/bloom_test.build/$(OBJDIR)/armv7s/bloom_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/bloom_test.build/$(OBJDIR)/arm64/bloom_test


PostBuild.c_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/c_test.build/$(OBJDIR)/armv7/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/c_test.build/$(OBJDIR)/armv7s/c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/c_test.build/$(OBJDIR)/arm64/c_test


PostBuild.cache_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/cache_test.build/$(OBJDIR)/armv7/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/cache_test.build/$(OBJDIR)/armv7s/cache_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/cache_test.build/$(OBJDIR)/arm64/cache_test


PostBuild.coding_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/coding_test.build/$(OBJDIR)/armv7/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/coding_test.build/$(OBJDIR)/armv7s/coding_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/coding_test.build/$(OBJDIR)/arm64/coding_test


PostBuild.corruption_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/corruption_test.build/$(OBJDIR)/armv7/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/corruption_test.build/$(OBJDIR)/armv7s/corruption_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/corruption_test.build/$(OBJDIR)/arm64/corruption_test


PostBuild.crc32c_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/crc32c_test.build/$(OBJDIR)/armv7/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/crc32c_test.build/$(OBJDIR)/armv7s/crc32c_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/crc32c_test.build/$(OBJDIR)/arm64/crc32c_test


PostBuild.db_bench.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench.build/$(OBJDIR)/armv7/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench.build/$(OBJDIR)/armv7s/db_bench
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench.build/$(OBJDIR)/arm64/db_bench


PostBuild.db_bench_sqlite3.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench_sqlite3.build/$(OBJDIR)/armv7/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench_sqlite3.build/$(OBJDIR)/armv7s/db_bench_sqlite3
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_bench_sqlite3.build/$(OBJDIR)/arm64/db_bench_sqlite3


PostBuild.db_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_test.build/$(OBJDIR)/armv7/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_test.build/$(OBJDIR)/armv7s/db_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/db_test.build/$(OBJDIR)/arm64/db_test


PostBuild.dbformat_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/dbformat_test.build/$(OBJDIR)/armv7/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/dbformat_test.build/$(OBJDIR)/armv7s/dbformat_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/dbformat_test.build/$(OBJDIR)/arm64/dbformat_test


PostBuild.env_posix_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_posix_test.build/$(OBJDIR)/armv7/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_posix_test.build/$(OBJDIR)/armv7s/env_posix_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_posix_test.build/$(OBJDIR)/arm64/env_posix_test


PostBuild.env_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_test.build/$(OBJDIR)/armv7/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_test.build/$(OBJDIR)/armv7s/env_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/env_test.build/$(OBJDIR)/arm64/env_test


PostBuild.fault_injection_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/fault_injection_test.build/$(OBJDIR)/armv7/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/fault_injection_test.build/$(OBJDIR)/armv7s/fault_injection_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/fault_injection_test.build/$(OBJDIR)/arm64/fault_injection_test


PostBuild.filename_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filename_test.build/$(OBJDIR)/armv7/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filename_test.build/$(OBJDIR)/armv7s/filename_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filename_test.build/$(OBJDIR)/arm64/filename_test


PostBuild.filter_block_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filter_block_test.build/$(OBJDIR)/armv7/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filter_block_test.build/$(OBJDIR)/armv7s/filter_block_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/filter_block_test.build/$(OBJDIR)/arm64/filter_block_test


PostBuild.gmock.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock.build/$(OBJDIR)/armv7/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock.build/$(OBJDIR)/armv7s/libgmock.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock.build/$(OBJDIR)/arm64/libgmock.a


PostBuild.gmock_main.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock_main.build/$(OBJDIR)/armv7/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock_main.build/$(OBJDIR)/armv7s/libgmock_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googlemock/leveldb.build/RelWithDebInfo/gmock_main.build/$(OBJDIR)/arm64/libgmock_main.a


PostBuild.gtest.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest.build/$(OBJDIR)/armv7/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest.build/$(OBJDIR)/armv7s/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest.build/$(OBJDIR)/arm64/libgtest.a


PostBuild.gtest_main.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest_main.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/armv7/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/armv7s/libgtest_main.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/third_party/googletest/googletest/leveldb.build/RelWithDebInfo/gtest_main.build/$(OBJDIR)/arm64/libgtest_main.a


PostBuild.hash_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/hash_test.build/$(OBJDIR)/armv7/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/hash_test.build/$(OBJDIR)/armv7s/hash_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/hash_test.build/$(OBJDIR)/arm64/hash_test


PostBuild.issue178_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue178_test.build/$(OBJDIR)/armv7/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue178_test.build/$(OBJDIR)/armv7s/issue178_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue178_test.build/$(OBJDIR)/arm64/issue178_test


PostBuild.issue200_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue200_test.build/$(OBJDIR)/armv7/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue200_test.build/$(OBJDIR)/armv7s/issue200_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue200_test.build/$(OBJDIR)/arm64/issue200_test


PostBuild.issue320_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue320_test.build/$(OBJDIR)/armv7/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue320_test.build/$(OBJDIR)/armv7s/issue320_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/issue320_test.build/$(OBJDIR)/arm64/issue320_test


PostBuild.leveldb.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldb.build/$(OBJDIR)/armv7/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldb.build/$(OBJDIR)/armv7s/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldb.build/$(OBJDIR)/arm64/libleveldb.a


PostBuild.leveldbutil.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldbutil.build/$(OBJDIR)/armv7/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldbutil.build/$(OBJDIR)/armv7s/leveldbutil
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/leveldbutil.build/$(OBJDIR)/arm64/leveldbutil


PostBuild.log_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/log_test.build/$(OBJDIR)/armv7/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/log_test.build/$(OBJDIR)/armv7s/log_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/log_test.build/$(OBJDIR)/arm64/log_test


PostBuild.logging_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/logging_test.build/$(OBJDIR)/armv7/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/logging_test.build/$(OBJDIR)/armv7s/logging_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/logging_test.build/$(OBJDIR)/arm64/logging_test


PostBuild.memenv_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/memenv_test.build/$(OBJDIR)/armv7/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/memenv_test.build/$(OBJDIR)/armv7s/memenv_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/memenv_test.build/$(OBJDIR)/arm64/memenv_test


PostBuild.no_destructor_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/no_destructor_test.build/$(OBJDIR)/armv7/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/no_destructor_test.build/$(OBJDIR)/armv7s/no_destructor_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/no_destructor_test.build/$(OBJDIR)/arm64/no_destructor_test


PostBuild.recovery_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/recovery_test.build/$(OBJDIR)/armv7/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/recovery_test.build/$(OBJDIR)/armv7s/recovery_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/recovery_test.build/$(OBJDIR)/arm64/recovery_test


PostBuild.skiplist_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/skiplist_test.build/$(OBJDIR)/armv7/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/skiplist_test.build/$(OBJDIR)/armv7s/skiplist_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/skiplist_test.build/$(OBJDIR)/arm64/skiplist_test


PostBuild.status_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/status_test.build/$(OBJDIR)/armv7/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/status_test.build/$(OBJDIR)/armv7s/status_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/status_test.build/$(OBJDIR)/arm64/status_test


PostBuild.table_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/table_test.build/$(OBJDIR)/armv7/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/table_test.build/$(OBJDIR)/armv7s/table_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/table_test.build/$(OBJDIR)/arm64/table_test


PostBuild.version_edit_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_edit_test.build/$(OBJDIR)/armv7/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_edit_test.build/$(OBJDIR)/armv7s/version_edit_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_edit_test.build/$(OBJDIR)/arm64/version_edit_test


PostBuild.version_set_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_set_test.build/$(OBJDIR)/armv7/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_set_test.build/$(OBJDIR)/armv7s/version_set_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/version_set_test.build/$(OBJDIR)/arm64/version_set_test


PostBuild.write_batch_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/write_batch_test.build/$(OBJDIR)/armv7/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/write_batch_test.build/$(OBJDIR)/armv7s/write_batch_test
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/leveldb.build/RelWithDebInfo/write_batch_test.build/$(OBJDIR)/arm64/write_batch_test




# For each target create a dummy ruleso the target does not have to exist
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgmockd.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Debug/libgtestd.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/MinSizeRel/libgtest.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/RelWithDebInfo/libgtest.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_32_64/lib/Release/libgtest.a:
