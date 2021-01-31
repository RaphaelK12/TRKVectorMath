

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <limits>
#include <float.h>
#include <iomanip>
#include <iostream>
#include <type_traits>
using namespace std;

#include "vector2.h"
#include "mathBase.h"

float Vector2::angle() const {
	return atan2(y, x);
}

float Vector2::length() const {
	return sqrt(x * x + y * y);
}

float Vector2::length_squared() const {
	return x * x + y * y;
}

void Vector2::normalize() {
	float l = x * x + y * y;
	if (l != 0) {
		l = sqrt(l);
		x /= l;
		y /= l;
	}
}

Vector2 Vector2::normalized() const {
	Vector2 v = *this;
	v.normalize();
	return v;
}

bool Vector2::is_normalized() const {
	// use length_squared() instead of length() to avoid sqrt(), makes it more stringent.
	return is_equal_approx(length_squared(), 1.0, FLT_EPSILON);
}

float Vector2::distance_to(const Vector2& p_vector2) const {
	return sqrt((x - p_vector2.x) * (x - p_vector2.x) + (y - p_vector2.y) * (y - p_vector2.y));
}

float Vector2::distance_squared_to(const Vector2& p_vector2) const {
	return (x - p_vector2.x) * (x - p_vector2.x) + (y - p_vector2.y) * (y - p_vector2.y);
}

float Vector2::angle_to(const Vector2& p_vector2) const {
	return atan2(cross(p_vector2), dot(p_vector2));
}

float Vector2::angle_to_point(const Vector2& p_vector2) const {
	return atan2(y - p_vector2.y, x - p_vector2.x);
}

float Vector2::dot(const Vector2& p_other) const {
	return x * p_other.x + y * p_other.y;
}

float Vector2::cross(const Vector2& p_other) const {
	return x * p_other.y - y * p_other.x;
}

Vector2 Vector2::sign() const {
	return Vector2(SGN(x), SGN(y));
}

Vector2 Vector2::floor() const {
	return Vector2(floor(x), floor(y));
}

Vector2 Vector2::ceil() const {
	return Vector2(ceil(x), ceil(y));
}

Vector2 Vector2::round() const {
	return Vector2(round(x), round(y));
}

Vector2 Vector2::rotated(float p_by) const {
	float sine = sin(p_by);
	float cosi = cos(p_by);
	return Vector2(
		x * cosi - y * sine,
		x * sine + y * cosi);
}

Vector2 Vector2::posmod(const float p_mod) const {
	return Vector2(fposmod(x, p_mod), fposmod(y, p_mod));
}

Vector2 Vector2::posmodv(const Vector2& p_modv) const {
	return Vector2(fposmod(x, p_modv.x), fposmod(y, p_modv.y));
}

Vector2 Vector2::project(const Vector2& p_b) const {
	return p_b * (dot(p_b) / p_b.length_squared());
}

Vector2 Vector2::snapped(const Vector2& p_by) const {
	return Vector2(
		stepify(x, p_by.x),
		stepify(y, p_by.y));
}

Vector2 Vector2::clamped(float p_len) const {
	float l = length();
	Vector2 v = *this;
	if (l > 0 && p_len < l) {
		v /= l;
		v *= p_len;
	}

	return v;
}

Vector2 Vector2::cubic_interpolate(const Vector2& p_b, const Vector2& p_pre_a, const Vector2& p_post_b, float p_t) const {
	Vector2 p0 = p_pre_a;
	Vector2 p1 = *this;
	Vector2 p2 = p_b;
	Vector2 p3 = p_post_b;

	float t = p_t;
	float t2 = t * t;
	float t3 = t2 * t;

	Vector2 out;
	out = 0.5 * ((p1 * 2.0) +
				 (-p0 + p2) * t +
				 (2.0 * p0 - 5.0 * p1 + 4 * p2 - p3) * t2 +
				 (-p0 + 3.0 * p1 - 3.0 * p2 + p3) * t3);
	return out;
}

Vector2 Vector2::move_toward(const Vector2& p_to, const float p_delta) const {
	Vector2 v = *this;
	Vector2 vd = p_to - v;
	float len = vd.length();
	return len <= p_delta || len < CMP_EPSILON ? p_to : v + vd / len * p_delta;
}

// slide returns the component of the vector along the given plane, specified by its normal vector.
Vector2 Vector2::slide(const Vector2& p_normal) const {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), Vector2(), "The normal Vector2 must be normalized.");
#endif
	return *this - p_normal * this->dot(p_normal);
}

Vector2 Vector2::bounce(const Vector2& p_normal) const {
	return -reflect(p_normal);
}

Vector2 Vector2::reflect(const Vector2& p_normal) const {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), Vector2(), "The normal Vector2 must be normalized.");
#endif
	return 2.0 * p_normal * this->dot(p_normal) - *this;
}

bool Vector2::is_equal_approx(const Vector2& p_v) const {
	return is_equal_approx(x, p_v.x) && is_equal_approx(y, p_v.y);
}

/* Vector2i */

Vector2i Vector2i::operator+(const Vector2i& p_v) const {
	return Vector2i(x + p_v.x, y + p_v.y);
}

void Vector2i::operator+=(const Vector2i& p_v) {
	x += p_v.x;
	y += p_v.y;
}

Vector2i Vector2i::operator-(const Vector2i& p_v) const {
	return Vector2i(x - p_v.x, y - p_v.y);
}

void Vector2i::operator-=(const Vector2i& p_v) {
	x -= p_v.x;
	y -= p_v.y;
}

Vector2i Vector2i::operator*(const Vector2i& p_v1) const {
	return Vector2i(x * p_v1.x, y * p_v1.y);
}

Vector2i Vector2i::operator*(const int& rvalue) const {
	return Vector2i(x * rvalue, y * rvalue);
}

void Vector2i::operator*=(const int& rvalue) {
	x *= rvalue;
	y *= rvalue;
}

Vector2i Vector2i::operator/(const Vector2i& p_v1) const {
	return Vector2i(x / p_v1.x, y / p_v1.y);
}

Vector2i Vector2i::operator/(const int& rvalue) const {
	return Vector2i(x / rvalue, y / rvalue);
}

void Vector2i::operator/=(const int& rvalue) {
	x /= rvalue;
	y /= rvalue;
}

Vector2i Vector2i::operator-() const {
	return Vector2i(-x, -y);
}

bool Vector2i::operator==(const Vector2i& p_vec2) const {
	return x == p_vec2.x && y == p_vec2.y;
}

bool Vector2i::operator!=(const Vector2i& p_vec2) const {
	return x != p_vec2.x || y != p_vec2.y;
}
