
#include "_.h"
using namespace cenarius;
using namespace kernal;
using namespace infrastructure;
using namespace renderer;
using namespace components;

#ifndef kPiFloat
#define kPiFloat        (3.1415926)
#endif//kPiFloat

#ifndef kTwoPiFloat
#define kTwoPiFloat     (2 * kPiFloat)
#endif//kTwoPiFloat

// code from Chrome
// third_party/blink/renderer/modules/canvas/canvas2d/canvas_path.cc
inline float AdjustEndAngle(float start_angle, float end_angle, bool anticlockwise) {
    float new_end_angle = end_angle;
    /* http://www.whatwg.org/specs/web-apps/current-work/multipage/the-canvas-element.html#dom-context-2d-arc
     * If the anticlockwise argument is false and endAngle-startAngle is equal
     * to or greater than 2pi, or,
     * if the anticlockwise argument is true and startAngle-endAngle is equal to
     * or greater than 2pi,
     * then the arc is the whole circumference of this ellipse, and the point at
     * startAngle along this circle's circumference, measured in radians clockwise
     * from the ellipse's semi-major axis, acts as both the start point and the
     * end point.
     */
    if (!anticlockwise && end_angle - start_angle >= kTwoPiFloat) {
        new_end_angle = start_angle + kTwoPiFloat;
    } else if (anticlockwise && start_angle - end_angle >= kTwoPiFloat) {
        new_end_angle = start_angle - kTwoPiFloat;
        /*
         * Otherwise, the arc is the path along the circumference of this ellipse
         * from the start point to the end point, going anti-clockwise if the
         * anticlockwise argument is true, and clockwise otherwise.
         * Since the points are on the ellipse, as opposed to being simply angles
         * from zero, the arc can never cover an angle greater than 2pi radians.
         */
        
        /* NOTE: When startAngle = 0, endAngle = 2Pi and anticlockwise = true, the
         * spec does not indicate clearly.
         * We draw the entire circle, because some web sites use arc(x, y, r, 0,
         * 2*Math.PI, true) to draw circle.
         * We preserve backward-compatibility.
         */
    } else if (!anticlockwise && start_angle > end_angle) {
        new_end_angle = start_angle +
            (kTwoPiFloat - fmodf(start_angle - end_angle, kTwoPiFloat));
    } else if (anticlockwise && start_angle < end_angle) {
        new_end_angle = start_angle -
            (kTwoPiFloat - fmodf(end_angle - start_angle, kTwoPiFloat));
    }
    return new_end_angle;
}

// code from Chrome
// third_party/blink/renderer/modules/canvas/canvas2d/canvas_path.cc
inline void CanonicalizeAngle(float* start_angle, float* end_angle) {
    // Make 0 <= startAngle < 2*PI
    float new_start_angle = fmodf(*start_angle, kTwoPiFloat);
    if (new_start_angle < 0) {
        new_start_angle += kTwoPiFloat;
        // Check for possible catastrophic cancellation in cases where
        // newStartAngle was a tiny negative number (c.f. crbug.com/503422)
        if (new_start_angle >= kTwoPiFloat)
            new_start_angle -= kTwoPiFloat;
    }
    float delta = new_start_angle - *start_angle;
    *start_angle = new_start_angle; *end_angle = *end_angle + delta;
}

// code from Chrome
// third_party/blink/renderer/platform/graphics/path.cc
inline void AddEllipse(SkPath& path, float cx, float cy, float radius_x, 
    float radius_y, float start_angle, float end_angle) {
    SkScalar radius_x_scalar = (SkScalar)(radius_x);
    SkScalar radius_y_scalar = (SkScalar)(radius_y);
    SkRect oval = SkRect::MakeLTRB(
    	cx - radius_x_scalar, cy - radius_y_scalar, 
      	cx + radius_x_scalar, cy + radius_y_scalar);
    float sweep = end_angle - start_angle;
    SkScalar start_degrees = (SkScalar)(start_angle * 180 / kPiFloat);
    SkScalar sweep_degrees = (SkScalar)(sweep * 180 / kPiFloat);
    SkScalar s360 = SkIntToScalar(360);

    // We can't use SkPath::addOval(), because addOval() makes a new sub-path.
    // addOval() calls moveTo() and close() internally.

    // Use s180, not s360, because SkPath::arcTo(oval, angle, s360, false) draws
    // nothing.
    SkScalar s180 = SkIntToScalar(180);
    if (SkScalarNearlyEqual(sweep_degrees, s360)) {
        // SkPath::arcTo can't handle the sweepAngle that is equal to or greater
        // than 2Pi.
        path.arcTo(oval, start_degrees, s180, false);
        path.arcTo(oval, start_degrees + s180, s180, false);
        return;
    }

    if (SkScalarNearlyEqual(sweep_degrees, -s360)) {
        path.arcTo(oval, start_degrees, -s180, false);
        path.arcTo(oval, start_degrees - s180, -s180, false);
        return;
    }
    path.arcTo(oval, start_degrees, sweep_degrees, false);
}

void render_context_2d::arc(js_parameter& parameter) {
	assert(transmitter_ && raw_context_);
	if (parameter.get_argument_count() < 5) return;
	float x, y, r, s, e; bool clock_wise = true;
	x = parameter.get_argument_at(0).to_float();
	y = parameter.get_argument_at(1).to_float();
	r = parameter.get_argument_at(2).to_float();
	s = parameter.get_argument_at(3).to_float();
	e = parameter.get_argument_at(4).to_float();
	if (parameter.get_argument_count() > 5) {
		clock_wise = !(parameter.get_argument_at(5).to_bool());
	}
    if (r < 0) return;
    auto& martix = related_->get_lt_context().current_matrix_;
    if (!r || s == e) {
        auto x1 = x + r * cosf(s);
        auto y1 = y + r * sinf(s);
        SkPoint pt; martix.mapXY(x1, y1, &pt);
        auto& path = related_->lt_current_path_;
        if (path.isEmpty()) {
            path.moveTo(pt.x(), pt.y());
        } else {
            path.lineTo(pt.x(), pt.y());
        }

        struct __task__ {
            render_context_thread_related* related_ = nullptr;
            SkPoint pt_;
            void run(barrel_buffer*) {
                assert(related_);
                auto& path = related_->rt_current_path_;
                if (path.isEmpty()) {
                    path.moveTo(pt_.x(), pt_.y());
                } else {
                    path.lineTo(pt_.x(), pt_.y());
                }
            }
        };
        auto task = transmitter_->alloc<__task__>();
        assert(nullptr != task);
        if (task) {
            task->pt_ = pt; 
            task->related_ = related_.get();
        }
        return;
    }

    CanonicalizeAngle(&s, &e);
    auto _adjust_end_angle = AdjustEndAngle(s, e, !clock_wise);
    SkPath _t_path;
    AddEllipse(_t_path, x, y, r, r, s, _adjust_end_angle);
    _t_path.transform(martix);
    related_->lt_current_path_.addPath(_t_path);
    struct __task__ {
        render_context_thread_related* related_ = nullptr;
        SkPath path_;
        void run(barrel_buffer*) {
            assert(related_);
            related_->rt_current_path_.addPath(path_);
        }
    };
    auto task = transmitter_->alloc<__task__>();
    assert(nullptr != task);
    if (task) {
        task->path_ = std::move(_t_path);
        task->related_ = related_.get();
    }
}