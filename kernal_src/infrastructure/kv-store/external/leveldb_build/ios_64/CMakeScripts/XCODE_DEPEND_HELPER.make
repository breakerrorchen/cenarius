# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.arena_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test


PostBuild.autocompact_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test


PostBuild.bloom_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test


PostBuild.c_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test


PostBuild.cache_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test


PostBuild.coding_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test


PostBuild.corruption_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test


PostBuild.crc32c_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test


PostBuild.db_bench.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench


PostBuild.db_bench_sqlite3.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3


PostBuild.db_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test


PostBuild.dbformat_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test


PostBuild.env_posix_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test


PostBuild.env_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test


PostBuild.fault_injection_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test


PostBuild.filename_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test


PostBuild.filter_block_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test


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


PostBuild.hash_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test


PostBuild.issue178_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test


PostBuild.issue200_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test


PostBuild.issue320_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test


PostBuild.leveldb.Debug:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a


PostBuild.leveldbutil.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil


PostBuild.log_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test


PostBuild.logging_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test


PostBuild.memenv_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test


PostBuild.no_destructor_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test


PostBuild.recovery_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test


PostBuild.skiplist_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test


PostBuild.status_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test


PostBuild.table_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test


PostBuild.version_edit_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test


PostBuild.version_set_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test


PostBuild.write_batch_test.Debug:
PostBuild.leveldb.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.Debug: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test


PostBuild.arena_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test


PostBuild.autocompact_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test


PostBuild.bloom_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test


PostBuild.c_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test


PostBuild.cache_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test


PostBuild.coding_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test


PostBuild.corruption_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test


PostBuild.crc32c_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test


PostBuild.db_bench.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench


PostBuild.db_bench_sqlite3.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3


PostBuild.db_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test


PostBuild.dbformat_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test


PostBuild.env_posix_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test


PostBuild.env_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test


PostBuild.fault_injection_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test


PostBuild.filename_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test


PostBuild.filter_block_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test


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


PostBuild.hash_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test


PostBuild.issue178_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test


PostBuild.issue200_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test


PostBuild.issue320_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test


PostBuild.leveldb.Release:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a


PostBuild.leveldbutil.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil


PostBuild.log_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test


PostBuild.logging_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test


PostBuild.memenv_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test


PostBuild.no_destructor_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test


PostBuild.recovery_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test


PostBuild.skiplist_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test


PostBuild.status_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test


PostBuild.table_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test


PostBuild.version_edit_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test


PostBuild.version_set_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test


PostBuild.write_batch_test.Release:
PostBuild.leveldb.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.Release: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test


PostBuild.arena_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test


PostBuild.autocompact_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test


PostBuild.bloom_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test


PostBuild.c_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test


PostBuild.cache_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test


PostBuild.coding_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test


PostBuild.corruption_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test


PostBuild.crc32c_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test


PostBuild.db_bench.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench


PostBuild.db_bench_sqlite3.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3


PostBuild.db_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test


PostBuild.dbformat_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test


PostBuild.env_posix_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test


PostBuild.env_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test


PostBuild.fault_injection_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test


PostBuild.filename_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test


PostBuild.filter_block_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test


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


PostBuild.hash_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test


PostBuild.issue178_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test


PostBuild.issue200_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test


PostBuild.issue320_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test


PostBuild.leveldb.MinSizeRel:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a


PostBuild.leveldbutil.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil


PostBuild.log_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test


PostBuild.logging_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test


PostBuild.memenv_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test


PostBuild.no_destructor_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test


PostBuild.recovery_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test


PostBuild.skiplist_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test


PostBuild.status_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test


PostBuild.table_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test


PostBuild.version_edit_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test


PostBuild.version_set_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test


PostBuild.write_batch_test.MinSizeRel:
PostBuild.leveldb.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.MinSizeRel: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test


PostBuild.arena_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/arena_test.app/arena_test


PostBuild.autocompact_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/autocompact_test.app/autocompact_test


PostBuild.bloom_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/bloom_test.app/bloom_test


PostBuild.c_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/c_test.app/c_test


PostBuild.cache_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/cache_test.app/cache_test


PostBuild.coding_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/coding_test.app/coding_test


PostBuild.corruption_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/corruption_test.app/corruption_test


PostBuild.crc32c_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/crc32c_test.app/crc32c_test


PostBuild.db_bench.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench.app/db_bench


PostBuild.db_bench_sqlite3.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_bench_sqlite3.app/db_bench_sqlite3


PostBuild.db_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/db_test.app/db_test


PostBuild.dbformat_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/dbformat_test.app/dbformat_test


PostBuild.env_posix_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_posix_test.app/env_posix_test


PostBuild.env_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/env_test.app/env_test


PostBuild.fault_injection_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/fault_injection_test.app/fault_injection_test


PostBuild.filename_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filename_test.app/filename_test


PostBuild.filter_block_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/filter_block_test.app/filter_block_test


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


PostBuild.hash_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/hash_test.app/hash_test


PostBuild.issue178_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue178_test.app/issue178_test


PostBuild.issue200_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue200_test.app/issue200_test


PostBuild.issue320_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/issue320_test.app/issue320_test


PostBuild.leveldb.RelWithDebInfo:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a


PostBuild.leveldbutil.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/leveldbutil.app/leveldbutil


PostBuild.log_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/log_test.app/log_test


PostBuild.logging_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/logging_test.app/logging_test


PostBuild.memenv_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/memenv_test.app/memenv_test


PostBuild.no_destructor_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/no_destructor_test.app/no_destructor_test


PostBuild.recovery_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/recovery_test.app/recovery_test


PostBuild.skiplist_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/skiplist_test.app/skiplist_test


PostBuild.status_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/status_test.app/status_test


PostBuild.table_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/table_test.app/table_test


PostBuild.version_edit_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_edit_test.app/version_edit_test


PostBuild.version_set_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/version_set_test.app/version_set_test


PostBuild.write_batch_test.RelWithDebInfo:
PostBuild.leveldb.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gmock.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
PostBuild.gtest.RelWithDebInfo: /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test:\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a\
	/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a
	/bin/rm -f /Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/write_batch_test.app/write_batch_test




# For each target create a dummy ruleso the target does not have to exist
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Debug${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/Release${EFFECTIVE_PLATFORM_NAME}/libleveldb.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgmockd.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Debug/libgtestd.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/MinSizeRel/libgtest.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/RelWithDebInfo/libgtest.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgmock.a:
/Users/bytedance/Code/Toffee/kernal_src/source/essential/kv-store/external/leveldb_build/ios_64/lib/Release/libgtest.a:
