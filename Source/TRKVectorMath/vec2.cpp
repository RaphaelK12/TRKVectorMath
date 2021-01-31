
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#include "mathBase.h"
#include "vec2.h"

vec2::~vec2() {
	x = 0;
	y = 0;
}
vec2::vec2() {
	x = 0;
	y = 0;
}
vec2::vec2(const float fX, const float fY) {
	x = fX;
	y = fY;
}
vec2::vec2(const float fX) {
	x = fX;
	y = fX;
}
vec2::vec2(const vec2& val) {
	x = val.x;
	y = val.y;
}

float& vec2::operator [] (unsigned short idx) {
	switch (idx) {
		case 0: return x;
		case 1: return y;
	}
	return x;
}

const float& vec2::operator [] (unsigned short idx) const {
	switch (idx) {
		case 0: return x;
		case 1: return y;
	}
	return x;
}

vec2& vec2::operator = (const vec2& val) {
	x = val.x;
	y = val.y;
	return *this;
}
vec2& vec2::operator = (const float& val) {
	x = val;
	y = val;
	return *this;
}

vec2& vec2::operator += (const vec2& val) {
	x = x + val.x;
	y = y + val.y;
	return *this;
}
vec2& vec2::operator -= (const vec2& val) {
	x = x - val.x;
	y = y - val.y;
	return *this;
}
vec2& vec2::operator *= (const vec2& val) {
	x = x * val.x;
	y = y * val.y;
	return *this;
}
vec2& vec2::operator /= (const vec2& val) {
	x = x / val.x;
	y = y / val.y;
	return *this;
}

vec2& vec2::operator += (const float& val) {
	x = x + val;
	y = y + val;
	return *this;
}
vec2& vec2::operator -= (const float& val) {
	x = x - val;
	y = y - val;
	return *this;
}
vec2& vec2::operator *= (const float& val) {
	x = x * val;
	y = y * val;
	return *this;
}
vec2& vec2::operator /= (const float& val) {
	x = x / val;
	y = y / val;
	return *this;
}

vec2 vec2::operator + (const vec2& val) const {
	vec2 tmp;
	tmp.x = x + val.x;
	tmp.y = y + val.y;
	return tmp;
}
vec2 vec2::operator - (const vec2& val) const {
	vec2 tmp;
	tmp.x = x - val.x;
	tmp.y = y - val.y;
	return tmp;
}
vec2 vec2::operator * (const vec2& val) const {
	vec2 tmp;
	tmp.x = x * val.x;
	tmp.y = y * val.y;
	return tmp;
}
vec2 vec2::operator / (const vec2& val) const {
	vec2 tmp;
	tmp.x = x / val.x;
	tmp.y = y / val.y;
	return tmp;
}

vec2 vec2::operator - (const float& val)const {
	vec2 tmp;
	tmp.x = x - val;
	tmp.y = y - val;
	return tmp;
}
vec2 vec2::operator * (const float& val)const {
	vec2 tmp;
	tmp.x = x * val;
	tmp.y = y * val;
	return tmp;
}
vec2 vec2::operator / (const float& val)const {
	vec2 tmp;
	tmp.x = x / val;
	tmp.y = y / val;
	return tmp;
}
vec2 vec2::operator + (const float& val)const {
	vec2 tmp;
	tmp.x = x + val;
	tmp.y = y + val;
	return tmp;
}

vec2 vec2::operator & (const vec2& rcVct) const {
	vec2 cVctRes;
	cVctRes.x = x * fabs(rcVct.x);
	cVctRes.y = y * fabs(rcVct.y);
	return cVctRes;
}
vec2 vec2::operator % (const vec2& rcVct) const {
	vec2 cVctRes;
	cVctRes.x = fmodf(x, rcVct.x);
	cVctRes.y = fmodf(y, rcVct.y);
	return cVctRes;
}
bool vec2::operator != (const vec2& rcVct) const {
	return !((*this) == rcVct);
}
bool vec2::operator == (const vec2& rcVct) const {
	return (fabs(x - rcVct.x) <= FLT_EPSILON) &&
		   (fabs(y - rcVct.y) <= FLT_EPSILON);
}

vec2 vec2::operator-() const {
	return vec2(-x, -y);
}

vec2  operator+(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar + p_vec.x;
	tmp.y = p_scalar + p_vec.y;
	return tmp;
}
vec2  operator-(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar - p_vec.x;
	tmp.y = p_scalar - p_vec.y;
	return tmp;
}
vec2  operator*(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar * p_vec.x;
	tmp.y = p_scalar * p_vec.y;
	return tmp;
}
vec2  operator/(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar / p_vec.x;
	tmp.y = p_scalar / p_vec.y;
	return tmp;
}

//////////////////////////////////////            //////////////////////////////////////
//////////////////////////////////////    vec2    //////////////////////////////////////
//////////////////////////////////////            //////////////////////////////////////

vec2  mix(const vec2 &a, const vec2 &b, float factor) {
	return a * (1 - factor) + b * factor;
}
vec2  clamp(const vec2& v, float& a, float& b) {
	vec2 tmp;
	tmp.x = clamp(v.x, a, b);
	tmp.y = clamp(v.y, a, b);
	return tmp;
}
vec2  clamp(const vec2& v, const vec2& a, const  vec2& b) {
	vec2 tmp;
	tmp.x = clamp(v.x, a.x, b.x);
	tmp.y = clamp(v.y, a.y, b.y);
	return tmp;
}
vec2  saturate(const vec2& v) {
	vec2 tmp;
	tmp.x = saturate(v.x);
	tmp.y = saturate(v.y);
	return tmp;
}
vec2  smoothstep(const vec2& v, float a, float b) {
	vec2 tmp;
	tmp.x = smoothstep(v.x, a, b);
	tmp.y = smoothstep(v.y, a, b);
	return tmp;
}
vec2  smoothstep(const vec2& v, const vec2& a, const  vec2& b) {
	vec2 tmp;
	tmp.x = smoothstep(v.x, a.x, b.x);
	tmp.y = smoothstep(v.y, a.y, b.y);
	return tmp;
}
vec2  smootherstep(const vec2& v, float a, float b) {
	vec2 tmp;
	tmp.x = smootherstep(v.x, a, b);
	tmp.y = smootherstep(v.y, a, b);
	return tmp;
}
vec2  smootherstep(const vec2& v, const vec2& a, const vec2& b) {
	vec2 tmp;
	tmp.x = smootherstep(v.x, a.x, b.x);
	tmp.y = smootherstep(v.y, a.y, b.y);
	return tmp;
}

int   print(const vec2& v) {
	return printf("x = %f,	y = %f,	len = %f", v.x, v.y, length(v));
}

vec2  normalize(const vec2& v) {
	float l = v.x * v.x + v.y * v.y;
	vec2 tmp(v);
	if (l != 0 && l != 1.f) {
		l = sqrt(l);
		tmp.x /= l;
		tmp.y /= l;
	}
	return tmp;
}
float distance(const vec2& v, const vec2& val) {
	return abs(length(v - val));
}
float dot(const vec2& v, const vec2& val) {
	return (v.x * val.x) + (v.y * val.y);
}
float GetAngle(const vec2& v, const vec2& rcVect) {
	float divid, fNum;

	divid = length(v) * length(rcVect);

	if ((divid < -1e-10f) || (divid > 1e-10f)) {
		fNum = dot(v, rcVect) / divid;
		if (fNum < -1)
			return F_PI;
		else if (fNum > 1)
			return 0.0F;
		else
			return acos(fNum);
	}
	else
		return 1.f; // division by zero
}
float sqr(const vec2& v) {
	return ((v.x * v.x) + (v.y * v.y));
}
float length(const vec2& v) {
	float l = (v.x * v.x) + (v.y * v.y);
	if (l != 0)
		l = sqrt(l);
	return l;
}
float len_sq(const vec2& v) {
	return (v.x * v.x) + (v.y * v.y);
}
float cross(const vec2& v, const vec2& val) {
	return (v.x * val.y) - (v.y * val.x);
}

vec2 rotateTurn(const vec2& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec2 rotateDeg (const vec2& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec2 rotateGrad(const vec2& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec2 rotateRad (const vec2& v, float val) {
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}

void  fitImage(const vec2& screen, const vec2& im, float zoom, vec2& rcStart, vec2& rcEnd) {
	vec2 rc;
	float w1 = 1, w2 = 1;
	float x = 1, y = 1, scx = 1, scy = 1;
	float x_start = 2, y_start = 2, x_end = 4, y_end = 4;
	float bmx = im.x * zoom;
	float bmy = im.y * zoom;

	{ // if screnn < image then rescale image to fit in window
		scx = screen.x - 4;
		scy = screen.y - 4;
		x   = bmx;
		y   = bmy;

		if (scx < x) w1 = scx / x;
		if (scy < y) w2 = scy / y;
		x = (bmx)*min(w1, w2);
		y = (bmy)*min(w1, w2);
		x_end = floorf(x + 0.5f);
		y_end = floorf(y + 0.5f);

		x_start = floorf((screen.x / 2.f - x / 2.f) + 0.5f);
		y_start = floorf((screen.y / 2.f - y / 2.f) + 0.5f);
		x_start = max(x_start, 2.f);
		y_start = max(y_start, 2.f);
	};
	{ // rescale to window size, maintaining aspect
		scx = screen.x - 4;
		scy = screen.y - 4;
		x   = bmx;
		y   = bmy;

		/*if (scx < x)*/ w1 = scx / x;
		/*if (scy < y)*/ w2 = scy / y;
		x = (bmx)*min(w1, w2);
		y = (bmy)*min(w1, w2);
		x_end = floorf(x + 0.5f);
		y_end = floorf(y + 0.5f);
		x_start = floorf((screen.x / 2.f - x / 2.f) + 0.5f);
		y_start = floorf((screen.y / 2.f - y / 2.f) + 0.5f);
		x_start = max(x_start, 2.f);
		y_start = max(y_start, 2.f);
	};


	rcStart.x = x_start;
	rcStart.y = y_start;
	rcEnd.x = x_end;
	rcEnd.y = y_end;
}

float DistanceToLine(const vec2& base, const vec2& rclDirect, const vec2& point) {
	return fabs((cross(rclDirect, base - point))) / length(rclDirect);
}
float pDistance(const vec2& point, const vec2& l1, const vec2& l2) {

	float  A = point.x - l1.x;
	float  B = point.y - l1.y;
	float  C = l2.x - l1.x;
	float  D = l2.y - l1.y;

	float  dot = A * C + B * D;
	float  len_sq = C * C + D * D;
	float  param = -1;
	if (len_sq != 0) //in case of 0 length line
		param = dot / len_sq;

	float  xx, yy;

	if (param < 0) {
		xx = l1.x;
		yy = l1.y;
	}
	else if (param > 1) {
		xx = l2.x;
		yy = l2.y;
	}
	else {
		xx = l1.x + param * C;
		yy = l1.y + param * D;
	}

	float  dx = point.x - xx;
	float  dy = point.y - yy;
	return sqrt(dx * dx + dy * dy);
}

float magnitude(const vec2 &v) {
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

float angle(const vec2& v) {
	return atan2(v.y, v.x);
}
bool  is_normalized(const vec2& v) {
	// use length_squared() instead of length() to avoid sqrt(), makes it more stringent.
	return is_equal_approx(len_sq(v), 1.0, FLT_EPSILON);
}
float distance_to(const vec2& v, const vec2& p_vec2) {
	return sqrt((v.x - p_vec2.x) * (v.x - p_vec2.x) + (v.y - p_vec2.y) * (v.y - p_vec2.y));
}
float distance_squared_to(const vec2& v, const vec2& p_vec2) {
	return (v.x - p_vec2.x) * (v.x - p_vec2.x) + (v.y - p_vec2.y) * (v.y - p_vec2.y);
}
float angle_to(const vec2& v, const vec2& p_vec2) {
	return atan2(cross(v, p_vec2), dot(v, p_vec2));
}
float angle_to_point(vec2& v, const vec2& p_vec2) {
	return atan2(v.y - p_vec2.y, v.x - p_vec2.x);
}
vec2  floor(const vec2& v) {
	return vec2(floor(v.x), floor(v.y));
}
vec2  ceil(const vec2& v) {
	return vec2(ceil(v.x), ceil(v.y));
}
vec2  round(const vec2& v) {
	return vec2(round(v.x), round(v.y));
}
vec2  rotated(const vec2& v, float p_by) {
	float sine = sin(p_by);
	float cosi = cos(p_by);
	return vec2(
		v.x * cosi - v.y * sine,
		v.x * sine + v.y * cosi);
}
vec2  posmod (const vec2& v, float p_mod) {
	return vec2(fposmod(v.x, p_mod), fposmod(v.y, p_mod));
}
vec2  posmodv(const vec2& v, const vec2& p_modv) {
	return vec2(fposmod(v.x, p_modv.x), fposmod(v.y, p_modv.y));
}
vec2  project(const vec2& v, const vec2& p_b) {
	return p_b * (dot(v, p_b) / len_sq(p_b));
}
vec2  snapped(const vec2& v, const vec2& p_by) {
	return vec2(
		snapped(v.x, p_by.x),
		snapped(v.y, p_by.y));
}
vec2  clamped(const vec2& v, float p_len) {
	float l = length(v);
	vec2 ve = v;
	if (l > 0 && p_len < l) {
		ve /= l;
		ve *= p_len;
	}

	return v;
}
vec2  cubic_interpolate(const vec2& v, const vec2& p_b, const vec2& p_pre_a, const vec2& p_post_b, float p_t) {
	vec2 p0 = p_pre_a;
	vec2 p1 = v;
	vec2 p2 = p_b;
	vec2 p3 = p_post_b;

	float t = p_t;
	float t2 = t * t;
	float t3 = t2 * t;

	vec2 out;
	out = 0.5 * ((p1 * 2.0) +
				 (-p0 + p2) * t +
				 (2.0 * p0 - 5.0 * p1 + 4 * p2 - p3) * t2 +
				 (-p0 + 3.0 * p1 - 3.0 * p2 + p3) * t3);
	return out;
}
vec2  move_toward(const vec2& v, const vec2& p_to,  float p_delta) {
	vec2 vd = p_to - v;
	float len = length(vd);
	return len <= p_delta || len < F_CMP_EPSILON ? p_to : v + vd / len * p_delta;
}
vec2  slide(const vec2& v, const vec2& p_normal) {// slide returns the component of the vector along the given plane, specified by its normal vector.
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), vec2(), "The normal vec2 must be normalized.");
#endif
	return v - p_normal * dot(v, p_normal);
}
vec2  reflect(const vec2& v, const vec2& p_normal) {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), vec2(), "The normal vec2 must be normalized.");
#endif
	return 2.0 * p_normal * dot(v, p_normal) - v;
}
vec2  bounce(const vec2& v, const vec2& p_normal) {
	return -reflect(v, p_normal);
}
bool  is_equal_approx(const vec2& v, const vec2& p_v) {
	return is_equal_approx(v.x, p_v.x, F_CMP_EPSILON) && is_equal_approx(v.y, p_v.y, F_CMP_EPSILON);
}




















