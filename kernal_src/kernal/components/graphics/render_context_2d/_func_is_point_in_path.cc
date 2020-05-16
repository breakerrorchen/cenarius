
#include "kernal/isolate/related_thread.h"
#include "_.h"
using namespace cenarius;
using namespace interpreter;
using namespace kernal;
using namespace components;

// code from chrome
inline bool SkPathContainsPoint(SkPath* originalPath, float x, float y, SkPathFillType ft) {
    SkRegion rgn; SkRegion clip;
    auto originalFillType = originalPath->getFillType();

    const SkPath* path = originalPath;
    SkPath scaledPath;
    int scale = 1;

    SkRect bounds = originalPath->getBounds();

    // We can immediately return false if the point is outside the bounding
    // rect.  We don't use bounds.contains() here, since it would exclude
    // points on the right and bottom edges of the bounding rect, and we want
    // to include them.
    SkScalar fX = SkFloatToScalar(x);
    SkScalar fY = SkFloatToScalar(y);
    if (fX < bounds.fLeft || fX > bounds.fRight || 
        fY < bounds.fTop || fY > bounds.fBottom)
        return false;
    originalPath->setFillType(ft);

    // Skia has trouble with coordinates close to the max signed 16-bit values
    // If we have those, we need to scale.
    //
    // TODO: remove this code once Skia is patched to work properly with large
    // values
    const SkScalar kMaxCoordinate = SkIntToScalar(1<<15);
    SkScalar biggestCoord = std::max(std::max(
        std::max(bounds.fRight, bounds.fBottom), -bounds.fLeft), -bounds.fTop);
    if (biggestCoord > kMaxCoordinate) {
        scale = std::ceil(sk_ieee_float_divide(biggestCoord, kMaxCoordinate));

        SkMatrix m;
        m.setScale(SkScalarInvert(
            SkIntToScalar(scale)), SkScalarInvert(SkIntToScalar(scale)));
        originalPath->transform(m, &scaledPath);
        path = &scaledPath;
    }

    int _x = static_cast<int>(floorf(x / scale));
    int _y = static_cast<int>(floorf(y / scale));
    auto rect = SkIRect::MakeLTRB(_x - 1, _y - 1, _x + 1, _y + 1);
    clip.setRect(rect);

    bool contains = rgn.setPath(*path, clip);

    originalPath->setFillType(originalFillType);
    return contains;
}

void render_context_2d::is_point_in_path(js_parameter& _parameter) {
    assert(related_);
    const static char* _evenodd = "evenodd";
    if (_parameter.get_argument_count() < 2) return;
    auto js_context = _parameter.get_context();
    auto x = _parameter[0].to_float();
    auto y = _parameter[1].to_float();
    auto fill_type = SkPathFillType::kWinding;
    if (_parameter.get_argument_count() > 2) {
        auto str = _parameter.get_argument_at(0).to_string();
        if (str == _evenodd) {
            fill_type = SkPathFillType::kEvenOdd;
        }
    }
    auto& path = related_->lt_current_path_;
    bool is_in = SkPathContainsPoint(&path, x, y, fill_type);
    _parameter.set_return(js_value::create(js_context, is_in));
}