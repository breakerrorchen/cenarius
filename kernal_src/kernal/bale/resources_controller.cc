
// #include "resources_controller.h"
// using namespace cenarius;
// using namespace kernal;
// using namespace assets;

// static const char* assets_cache = "cache";

// resources_controller::resources_controller(const char* src, 
//     const char* cache) {
//     std::string path_src(src), cache_src(cache); 
//     fs_utils::dir_path_normal(path_src );
//     fs_utils::dir_path_normal(cache_src);
//     root_path_.assign(path_src.c_str());
//     if (!filesystem::exists(root_path_)) {
//         throw std::invalid_argument("root-dir is not exists");
//     }
//     system_cache_path_.assign(cache_src.c_str());
//     if (!filesystem::exists(system_cache_path_)) {
//         throw std::invalid_argument("cache-dir is not exists");
//     }
// }

// resources_controller::resources_controller(
//     resources_controller&& from) {
//     operator=(std::move(from));
// }

// resources_controller& resources_controller::operator=(
//     resources_controller&& from) {
//     if (this != &from) {
//         root_path_ = std::move(from.root_path_);
//     }
//     return *this;
// }

// bool resources_controller::available_check() {
//     auto cache = root_path_.concat(assets_cache);
//     if (!filesystem::exists(cache)) {
//         filesystem::create_directories(cache);
//     }
//     return true;
// }