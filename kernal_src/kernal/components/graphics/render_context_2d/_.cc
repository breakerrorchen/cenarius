
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace components;
using namespace infrastructure;
using namespace interpreter;
using namespace service;
using namespace renderer;
using namespace asynchronous;
using namespace bestead;
using namespace isolate;

// void draw(SkCanvas* canvas) {
//     const char* fontFamily = nullptr;  // Default system family, if it exists.
//     SkFontStyle fontStyle;  // Default is normal weight, normal width,  upright slant.
//     sk_sp<SkFontMgr> fontManager = SkFontMgr::RefDefault();
//     sk_sp<SkTypeface> typeface = fontManager->legacyMakeTypeface(fontFamily, fontStyle);

//     SkFont font1(typeface, 64.0f, 1.0f, 0.0f);
//     SkFont font2(typeface, 64.0f, 1.5f, 0.0f);
//     font1.setEdging(SkFont::Edging::kAntiAlias);
//     font2.setEdging(SkFont::Edging::kAntiAlias);

//     // Note: MakeFromString may fail to produce expected results if the typeface
//     // does not have glyphs for the characters in the string.  The characters
//     // will not be kerned or shaped beyond a simple mapping from one Unicode
//     // code point to one glyph with a default advance.
//     sk_sp<SkTextBlob> blob1 = SkTextBlob::MakeFromString("Skia", font1);
//     sk_sp<SkTextBlob> blob2 = SkTextBlob::MakeFromString("Skia", font2);

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

render_context_2d::render_context_2d(__sptr<command_transmitter> 
	_transmitter, puppet<renderer::canvas>& _canvas,
	std::shared_ptr<alived_token<canvas>> related_canvas)
	: transmitter_(_transmitter), related_canvas_(related_canvas) {
	assert(_transmitter && related_canvas);
	related_ = std::make_shared<render_context_thread_related>();
	render_context_2d_context_local context_local;
	related_->lt_context_stack_.emplace(context_local);
	auto default_font = render_util_tools::get_default_font();
	related_->get_lt_context().typeface_ = default_font;
	related_->get_lt_context().typeface_size_ = 12;
	struct __task__ {
		puppet_container<canvas_render_2d>* raw_context_;
		puppet_container<renderer::canvas>* raw_canvas_;
		render_context_thread_related* related_ = nullptr;
		sk_sp<SkTypeface> font_;
		void run(barrel_buffer*) {
			assert(raw_context_ && raw_canvas_ && related_);
			raw_context_->data_ = raw_canvas_->data_->render_2d();
			render_context_2d_context _2d_context;
			related_->rt_context_stack_.emplace(_2d_context);
			related_->get_rt_context().typeface_ = font_;
			related_->get_rt_context().typeface_size_ = 12;
		}
	};
	auto task = _transmitter->alloc<__task__>();
	assert(nullptr != task);
	if (task) {
		task->raw_canvas_  = _canvas.get();
		task->raw_context_ = raw_context_.get();
		task->related_ 	   = related_.get();
		task->font_ 	   = default_font;
	}
	_transmitter->force_commit(false, true);

	// // 初始化context stack
	// render_context_2d_context _2d_context;
	// context_stack_.emplace(_2d_context);

	// //test
	// auto raw_context = get_current_canvas();
	// raw_context->drawColor(SK_ColorWHITE);
	// for (int i = 0; i < 1; ++i) {
	// 	draw(raw_context);
	// }
	// force_commit();
}

render_context_2d::~render_context_2d() {
	assert(transmitter_ && related_);
	struct __task__ {
		std::shared_ptr<render_context_thread_related> related_;
		puppet_container<canvas_render_2d>* raw_context_;
		void run(barrel_buffer*) {
			assert(raw_context_);
			delete raw_context_;
		}
	};
	auto task = transmitter_->alloc<__task__>();
	assert(nullptr != task);
	if (task) {
		task->related_ 	   = related_;
		task->raw_context_ = raw_context_.get();
	}
}

// SkCanvas* render_context_2d::get_current_canvas() {
// 	if (nullptr == current_canvas_) {
// 		// 这里直接记录最大值，不知道会不会影响性能
// 		current_canvas_ = canvas_recoder_
// 			.beginRecording(SK_ScalarMax, SK_ScalarMax);
// 	}
// 	return current_canvas_;
// }

void render_context_2d::force_commit() {
	// assert(transmitter_);
	// if (nullptr == current_canvas_) { return; }

	// struct __task__ {
	// 	puppet_container<canvas_render_2d>* raw_context_;
	// 	sk_sp<SkPicture> playback_;
	// 	void run(barrel_buffer*) {
	// 		assert(raw_context_->data_ && playback_);
	// 		auto _ctx = raw_context_->data_->get();
	// 		if (_ctx) {
	// 			_ctx->drawPicture(playback_);
	// 		}
	// 	}
	// };
	// auto task = transmitter_->alloc<__task__>();
	// assert(nullptr != task);
	// task->raw_context_ = raw_context_.get();
	// task->playback_ = 
	// 	canvas_recoder_.finishRecordingAsPicture();
	// current_canvas_ = nullptr;

	// // 有绘制的内容，强制推送一把
	// transmitter_->force_commit();
}