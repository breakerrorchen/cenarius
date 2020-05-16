
#pragma once
#include "render_care.h"
#include "renderer.h"
#include "render_util_tools.h"

// void loadFallbackFont() {
//     fallbackFaceId = 0;
// #if FOS(ANDROID)
//     const std::string sansName = "NotoSerifCJK-Regular", serifName = "NotoSerifCJK-Regular";
// #else
//     const std::string sansName = "PingFang SC", serifName = "Songti SC";
// #endif
//     const SkUnichar scCh = 0x534e;
//     auto sansFace = fontMgr->matchFamilyStyleCharacter(sansName.c_str(), defaultFontStyle, nullptr, 0, scCh);
//     fallbackFaceId = autoCacheTypeFace(sansFace ? sk_sp<SkTypeface>(sansFace) : SkTypeface::MakeDefault())->uniqueID();

//     faceNameMap[std::string("sans")] = faceNameMap[std::string("sans-serif")] = fallbackFaceId;

//     auto serifFace = fontMgr->matchFamilyStyleCharacter(serifName.c_str(), defaultFontStyle, nullptr, 0, scCh);
//     if (serifFace != nullptr && sansFace != nullptr && serifFace->uniqueID() != sansFace->uniqueID()) {
//         faceNameMap[std::string("serif")] = autoCacheTypeFace(sk_sp<SkTypeface>(serifFace))->uniqueID();
//     }
// }

sk_sp<SkTypeface> cenarius::infrastructure::renderer::
	render_util_tools::get_default_font() {
	// Default system family, if it exists.
	const char* fontFamily = "NotoSerifCJK-Regular";  
	SkFontStyle fontStyle;
	sk_sp<SkFontMgr> fm = SkFontMgr::RefDefault();
	const SkUnichar ch = 0x3434;
	auto face = fm->matchFamilyStyleCharacter(
		fontFamily, fontStyle, nullptr, 0, ch);
	return sk_sp<SkTypeface>(face);
}