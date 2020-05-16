
// #if defined(__cplusplus) && __cplusplus >= 201703L && defined(__has_include)
// #if __has_include(<filesystem>)
// #define __GHC_USE_STD_FS__
// #include <filesystem>
// namespace cenarius { namespace infrastructure {
//     namespace filesystem = std::filesystem;
// }}
// #endif
// #endif
// #ifndef __GHC_USE_STD_FS__
#include <ghc/filesystem.hpp>
namespace cenarius { namespace infrastructure {
    namespace filesystem = ghc::filesystem;
}}
// #endif

namespace cenarius { namespace infrastructure { namespace fs_utils {
    inline void dir_path_normal(std::string& path) {
        auto path_len = path.length();
        for (decltype(path_len) i = 0; i < path_len; ++i) {
            if ('\\' == path[i]) { path[i] = '/'; }
        }
        if (!path.empty() && path.back() != '/') { path += '/'; }
    }
}}}