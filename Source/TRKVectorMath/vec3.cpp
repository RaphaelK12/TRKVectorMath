
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

#include "mathBase.h"
#include "vec3.h"

vec3::~vec3() {
	x = 0;
	y = 0;
	z = 0;
}
vec3::vec3() {
	x = 0;
	y = 0;
	z = 0;
}
vec3::vec3(const float fX, const float fY, const float fZ) {
	x = fX;
	y = fY;
	z = fZ;
}
vec3::vec3(const float fX) {
	x = fX;
	y = fX;
	z = fX;
}
vec3::vec3(const vec3& val) {
	x = val.x;
	y = val.y;
	z = val.z;
}

vec3::vec3(const float fX, const vec2& fY) {
	x = fX;
	y = fY.x;
	z = fY.y;
}
vec3::vec3(const vec2& fX, const float fY) {
	x = fX.x;
	y = fX.y;
	z = fY;
}

float& vec3::operator [] (unsigned short idx) {
	switch (idx) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
	}
	return x;
}

const float& vec3::operator [] (unsigned short idx) const {
	switch (idx) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
	}
	return x;
}

vec3& vec3::operator = (const vec3& val) {
	x = val.x;
	y = val.y;
	z = val.z;
	return *this;
}
vec3& vec3::operator = (const float& val) {
	x = val;
	y = val;
	z = val;
	return *this;
}

vec3& vec3::operator += (const vec3& val) {
	x += val.x;
	y += val.y;
	z += val.z;
	return *this;
}
vec3& vec3::operator -= (const vec3& val) {
	x -= val.x;
	y -= val.y;
	z -= val.z;
	return *this;
}
vec3& vec3::operator *= (const vec3& val) {
	x *= val.x;
	y *= val.y;
	z *= val.z;
	return *this;
}
vec3& vec3::operator /= (const vec3& val) {
	x /= val.x;
	y /= val.y;
	z /= val.z;
	return *this;
}

vec3& vec3::operator += (const float& val) {
	x += val;
	y += val;
	z += val;
	return *this;
}
vec3& vec3::operator -= (const float& val) {
	x -= val;
	y -= val;
	z -= val;
	return *this;
}
vec3& vec3::operator *= (const float& val) {
	x *= val;
	y *= val;
	z *= val;
	return *this;
}
vec3& vec3::operator /= (const float& val) {
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

vec3 vec3::operator + (const vec3& val) const {
	vec3 tmp;
	tmp.x = x + val.x;
	tmp.y = y + val.y;
	tmp.z = y + val.z;
	return tmp;
}
vec3 vec3::operator - (const vec3& val) const {
	vec3 tmp;
	tmp.x = x - val.x;
	tmp.y = y - val.y;
	tmp.z = z - val.z;
	return tmp;
}
vec3 vec3::operator * (const vec3& val) const {
	vec3 tmp;
	tmp.x = x * val.x;
	tmp.y = y * val.y;
	tmp.z = z * val.z;
	return tmp;
}
vec3 vec3::operator / (const vec3& val) const {
	vec3 tmp;
	tmp.x = x / val.x;
	tmp.y = y / val.y;
	tmp.z = z / val.z;
	return tmp;
}

vec3 vec3::operator + (const float& val) const {
	vec3 tmp;
	tmp.x = x + val;
	tmp.y = y + val;
	tmp.z = z + val;
	return tmp;
}
vec3 vec3::operator - (const float& val) const {
	vec3 tmp;
	tmp.x = x - val;
	tmp.y = y - val;
	tmp.z = z - val;
	return tmp;
}
vec3 vec3::operator * (const float& val) const {
	vec3 tmp;
	tmp.x = x * val;
	tmp.y = y * val;
	tmp.z = z * val;
	return tmp;
}
vec3 vec3::operator / (const float& val) const {
	vec3 tmp;
	tmp.x = x / val;
	tmp.y = y / val;
	tmp.z = z / val;
	return tmp;
}

vec3 vec3::operator & (const vec3& rcVct) const {
	vec3 cVctRes;
	cVctRes.x = x * fabs(rcVct.x);
	cVctRes.y = y * fabs(rcVct.y);
	cVctRes.z = z * fabs(rcVct.z);
	return cVctRes;
}
vec3 vec3::operator % (const vec3& rcVct) const {
	vec3 cVctRes;
	cVctRes.x = fmodf(x, rcVct.x);
	cVctRes.y = fmodf(y, rcVct.y);
	cVctRes.z = fmodf(z, rcVct.z);
	return cVctRes;
}
bool vec3::operator != (const vec3& rcVct) const {
	return !((*this) == rcVct);
}
bool vec3::operator == (const vec3& rcVct) const {
	return (fabs(x - rcVct.x) <= FLT_EPSILON) &&
		(fabs(y - rcVct.y) <= FLT_EPSILON) &&
		(fabs(z - rcVct.z) <= FLT_EPSILON);
}

vec3 vec3::operator - () const {
	return vec3(-x, -y, -z);
}

vec3  operator+(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar + p_vec.x;
	tmp.y = p_scalar + p_vec.y;
	tmp.z = p_scalar + p_vec.z;
	return tmp;
}
vec3  operator-(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar - p_vec.x;
	tmp.y = p_scalar - p_vec.y;
	tmp.z = p_scalar - p_vec.z;
	return tmp;
}
vec3  operator*(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar * p_vec.x;
	tmp.y = p_scalar * p_vec.y;
	tmp.z = p_scalar * p_vec.z;
	return tmp;
}
vec3  operator/(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar / p_vec.x;
	tmp.y = p_scalar / p_vec.y;
	tmp.z = p_scalar / p_vec.z;
	return tmp;
}

int   print(const vec3& v) {
	return printf("x = %f,	y = %f,	z = %f,	len = %f\n", v.x, v.y, v.z, length(v));
}

float length(const vec3& v) {
	return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
float len_sq(const vec3& v) {
	return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
}
float distance(const vec3& v, const vec3& val) {
	return abs(length(v - val));
}
float dot(const vec3& v, const vec3& val) {
	return (v.x * val.x) + (v.y * val.y) + (v.z * val.z);
}
float sqr(const vec3& v) {
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
float GetAngle(const vec3& v, const vec3& rcVect) {
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
float magnitude(const vec3& v) {
	return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}

vec3  mix(const vec3& a, const vec3& b, float factor) {
	return a * (1 - factor) + b * factor;
}
vec3  clamp(const vec3 &v, float a, float b) {
	vec3 tmp;
	tmp.x = clamp(v.x, a, b);
	tmp.y = clamp(v.y, a, b);
	tmp.z = clamp(v.z, a, b);
	return tmp;
}
vec3  clamp(const vec3 &v, const vec3 &a, const vec3 &b) {
	vec3 tmp;
	tmp.x = clamp(v.x, a.x, b.x);
	tmp.y = clamp(v.y, a.y, b.y);
	tmp.z = clamp(v.z, a.z, b.z);
	return tmp;
}
vec3  saturate(const vec3 &v) {
	vec3 tmp;
	tmp.x = saturate(v.x);
	tmp.y = saturate(v.y);
	tmp.z = saturate(v.z);
	return tmp;
}

vec3  smoothstep(const vec3 &v, float a, float b) {
	vec3 tmp;
	tmp.x = smoothstep(v.x, a, b);
	tmp.y = smoothstep(v.y, a, b);
	tmp.z = smoothstep(v.z, a, b);
	return tmp;
}
vec3  smoothstep(const vec3 &v, const vec3 &a, const vec3 &b) {
	vec3 tmp;
	tmp.x = smoothstep(v.x, a.x, b.x);
	tmp.y = smoothstep(v.y, a.y, b.y);
	tmp.z = smoothstep(v.z, a.z, b.z);
	return tmp;
}
vec3  smootherstep(const vec3 &v, float a, float b) {
	vec3 tmp;
	tmp.x = smootherstep(v.x, a, b);
	tmp.y = smootherstep(v.y, a, b);
	tmp.z = smootherstep(v.z, a, b);
	return tmp;
}
vec3  smootherstep(const vec3 &v, const vec3 &a, const vec3 &b) {
	vec3 tmp;
	tmp.x = smootherstep(v.x, a.x, b.x);
	tmp.y = smootherstep(v.y, a.y, b.y);
	tmp.z = smootherstep(v.z, a.z, b.z);
	return tmp;
}

vec3  normalize(const vec3& v) {
	vec3 tmp(v);
	float fLen = length(v);
	if (fLen != 0.f && fLen != 1.f) {
		tmp.x /= fLen;
		tmp.y /= fLen;
		tmp.z /= fLen;
	}
	return tmp;
}
vec3  cross(const vec3& v, const vec3& val) {
	vec3 tmp;
	tmp.x = (v.y * val.z) - (v.z * val.y);
	tmp.y = (v.z * val.x) - (v.x * val.z);
	tmp.z = (v.x * val.y) - (v.y * val.x);
	return tmp;
}
vec3  sqrt(const vec3 &a) {
	return vec3(sqrt(a.x), sqrt(a.y), sqrt(a.z));
}
vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref) {
	if (dot(Nref, I) < 0.0f) {
		return N;
	}
	return -N;
}
vec3  reflect(const vec3& I, const vec3& N) {
	return I - N * dot(N, I) * 2.0f;
}
vec3  refract(const vec3& I, const vec3& N, float eta) {
	float k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
	if (k < 0.0f)
		return vec3(0.0f);
	else
		return I * eta - (N * sqrt(k)) + eta * dot(N, I);
}
vec3  calcNormal(const vec3& v1, const vec3& v2, const vec3& v3) {
	vec3 n1, n2;
	n1 = v2 - v1;
	n2 = v2 - v3;
	return cross(n1, n2);
}
vec3  faceNormal(const vec3& v1, const vec3& v2, const vec3& v3) {
	vec3 n1, n2;
	// Calculate two vectors from the three points
	n1 = v1 - v2;
	n2 = v2 - v3;
	// Take the cross product of the two vectors to get
	// the normal vector and
	// Normalize the vector (shorten length to one)
	return normalize(cross(n1, n2));
}

vec3  rotateXTurn (const vec3& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	 tmp. y = (v.y * fcos) - (v.z * fsin);
	 tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
vec3  rotateXDeg  (const vec3& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
vec3  rotateXGrad (const vec3& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
vec3  rotateXRad  (const vec3& v, float val) {
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}

vec3  rotateYTurn (const vec3& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
vec3  rotateYDeg  (const vec3& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
vec3  rotateYGrad (const vec3& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
vec3  rotateYRad  (const vec3& v, float val) {
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}

vec3  rotateZTurn (const vec3& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec3  rotateZDeg  (const vec3& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec3  rotateZGrad (const vec3& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
vec3  rotateZRad  (const vec3& v, float val) {
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}

vec3  rotateTurn  (const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZTurn(v,val.z);
	tmp = rotateYTurn(tmp,val.y);
	tmp = rotateXTurn(tmp,val.x);
	return tmp;
}
vec3  rotateDeg	  (const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZDeg(v, val.z);
	tmp = rotateYDeg(tmp, val.y);
	tmp = rotateXDeg(tmp,val.x);
	return tmp;
}
vec3  rotateGrad  (const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZGrad(v, val.z);
	tmp = rotateYGrad(tmp, val.y);
	tmp = rotateXGrad(tmp,val.x);
	return tmp;
}
vec3  rotateRad	  (const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZRad(v, val.z);
	tmp = rotateYRad(tmp, val.y);
	tmp = rotateXRad(tmp,val.x);
	return tmp;
}

vec3  rotateAroundAxis(const vec3& p, const vec3& axis, float angle) {
	float costheta = cosf(angle);
	float sintheta = sinf(angle);
	vec3 r;

	r.x = ((costheta + (1 - costheta) * axis.x * axis.x) * p.x) +
		(((1 - costheta) * axis.x * axis.y - axis.z * sintheta) * p.y) +
		(((1 - costheta) * axis.x * axis.z + axis.y * sintheta) * p.z);

	r.y = (((1 - costheta) * axis.x * axis.y + axis.z * sintheta) * p.x) +
		((costheta + (1 - costheta) * axis.y * axis.y) * p.y) +
		(((1 - costheta) * axis.y * axis.z - axis.x * sintheta) * p.z);

	r.z = (((1 - costheta) * axis.x * axis.z - axis.y * sintheta) * p.x) +
		(((1 - costheta) * axis.y * axis.z + axis.x * sintheta) * p.y) +
		((costheta + (1 - costheta) * axis.z * axis.z) * p.z);

	return r;
}

vec3  rotateAxis(const vec3& v, const vec3& axis, float theta) {
	float cos_theta = cos(theta);
	float sin_theta = sin(theta);
	return (v * cos_theta) + (cross(axis, v) * sin_theta) + (axis * dot(axis, v)) * (1 - cos_theta);
}

float DistanceToLine(const vec3& base, const vec3& rclDirect, const vec3& point)  {
	return fabs(length(cross(rclDirect, base - point))) / length(rclDirect);
}

float distanceToLine(const vec3& P, const vec3& A, const vec3& B) {
	vec3 v1 = B - A, v2 = P - A;
	return length(cross(v1, v2)) / length(v1);
}

































