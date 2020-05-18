#include "common/logger.h"
#include "care_render.h"
using namespace cenarius;
using namespace kernal;
using namespace cc;
using namespace platform;

// void draw(SkCanvas* canvas) {
//     canvas->drawColor(SK_ColorWHITE);
//     const char* fontFamily = "NotoSerifCJK-Regular";  // Default system family, if it exists.
//     SkFontStyle fontStyle = SkFontStyle::Bold(); // Default is normal weight, normal width,  upright slant.
//     sk_sp<SkFontMgr> fontManager = SkFontMgr::RefDefault();
    
//     const SkUnichar scCh = 0x534e;
//     auto sansFace = fontManager->matchFamilyStyleCharacter(fontFamily, fontStyle, nullptr, 0, 0x3434);
//     //auto sansFace = fontManager->matchFamilyStyle(fontFamily, fontStyle);

//     sk_sp<SkTypeface> _t(sansFace); SkPaint paint1, paint2, paint3;

//     paint1.setAntiAlias(true);
//     paint1.setColor(SkColorSetARGB(0xFF, 0x42, 0x85, 0xF4));

//     SkFont font1(_t, 64.0f, 1.0f, 0.0f);
//     sk_sp<SkTextBlob> blob1 = SkTextBlob::MakeFromString("果冻", font1);
//     canvas->drawTextBlob(blob1.get(), 20.0f, 64.0f, paint1);
    
// }


// void draw1(SkCanvas* canvas) {
//     const char* fontFamily = "NotoSerifCJK-Regular";  // Default system family, if it exists.
//     SkFontStyle fontStyle;  // Default is normal weight, normal width,  upright slant.
//     sk_sp<SkFontMgr> fontManager = SkFontMgr::RefDefault();
//     sk_sp<SkTypeface> typeface(fontManager->matchFamilyStyle(fontFamily, fontStyle));

//     SkFont font1(typeface, 64.0f, 1.0f, 0.0f);
//     SkFont font2(typeface, 64.0f, 1.5f, 0.0f);
//     font1.setEdging(SkFont::Edging::kAntiAlias);
//     font2.setEdging(SkFont::Edging::kAntiAlias);

//     // Note: MakeFromString may fail to produce expected results if the typeface
//     // does not have glyphs for the characters in the string.  The characters
//     // will not be kerned or shaped beyond a simple mapping from one Unicode
//     // code point to one glyph with a default advance.
//     sk_sp<SkTextBlob> blob1 = SkTextBlob::MakeFromString("果冻", font1);
//     sk_sp<SkTextBlob> blob2 = SkTextBlob::MakeFromString("果冻", font2);

//     SkPaint paint1, paint2, paint3;

//     paint1.setAntiAlias(true);
//     paint1.setColor(SkColorSetARGB(0xFF, 0x42, 0x85, 0xF4));

//     paint2.setAntiAlias(true);
//     paint2.setColor(SkColorSetARGB(0xFF, 0xDB, 0x44, 0x37));
//     paint2.setStyle(SkPaint::kStroke_Style);
//     paint2.setStrokeWidth(3.0f);

//     paint3.setAntiAlias(true);
//     paint3.setColor(SkColorSetARGB(0xFF, 0x0F, 0x9D, 0x58));

//     canvas->clear(SK_ColorWHITE);
//     canvas->drawTextBlob(blob1.get(), 20.0f, 64.0f, paint1);
//     canvas->drawTextBlob(blob1.get(), 20.0f, 144.0f, paint2);
//     canvas->drawTextBlob(blob2.get(), 20.0f, 224.0f, paint3);
// }

care_render_i::care_render_i() {
    render_basement::initializer();
}

void care_render_i::on_start() {
    {
        spinlocker_watcher _watcher(locker_);
        current_window_ = new_window_; 
        new_window_ = nullptr;
    }

    // 对上层构造出平台无关的渲染层的实现
    assert(current_window_);
    canvas_center_ = std::make_shared<render_interface_canvas_center>();
    render_native_window _native_window(current_window_->get(), 
        current_window_->window_scale());
    renderer_ = std::make_shared<renderer_combined>(_native_window);
    canvas_center_->renderer_combined_ = renderer_;
}

// 在每一次上屏之前，需要判断是不是底层的native-window的大小发生了变化
// 所以需要做这个处理
void care_render_i::pre_commit_drawable() {
    bool should_reset_window = false;
    {
        spinlocker_watcher _watcher(locker_);
        if (new_window_) {
            current_window_ = new_window_; 
            new_window_ = nullptr;
            should_reset_window = true;
        }
    }

    // 重置底层的native_window
    if (should_reset_window) {
        assert(current_window_ && renderer_);
        auto scale = current_window_->window_scale();
        auto win = current_window_->get();
        renderer_->reset(render_native_window(win, scale));
    }
}

void care_render_i::commit_drawable() {
    ;
}

void care_render_i::after_commit_drawable() {
    ;
}

std::shared_ptr<canvas_center> care_render_i::get_canvas_center() {
    return std::dynamic_pointer_cast<canvas_center>(canvas_center_);
}

void care_render_i::on_finish() {
    ;
}

void care_render_i::reset_window(std::shared_ptr<render_window> _w) {
    spinlocker_watcher _watcher(locker_); 
    new_window_ = _w;
}