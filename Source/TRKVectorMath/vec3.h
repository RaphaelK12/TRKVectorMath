
#pragma once
#include "vec2.h"

class vec3 {
public:
	union {
		struct {
			float x, y, z;
		};
		struct {
			float r, g, b;
		};
		float v[3];
		//unsigned long long bits;
	};

	~vec3();
	vec3();


	vec3(const float fX);
	vec3(const vec3& val);
	vec3(const float fX, const vec2& fY);
	vec3(const vec2& fX, const float fY);
	vec3(const float fX, const float fY, const float fZ);

	float& operator [] (unsigned short idx);
	const float& operator [] (unsigned short idx) const;

	vec3& operator = (const vec3& val);
	vec3& operator = (const float& val);

	vec3& operator += (const vec3& val);
	vec3& operator -= (const vec3& val);
	vec3& operator *= (const vec3& val);
	vec3& operator /= (const vec3& val);

	vec3& operator += (const float& val);
	vec3& operator -= (const float& val);
	vec3& operator *= (const float& val);
	vec3& operator /= (const float& val);

	vec3 operator + (const vec3& val) const;
	vec3 operator - (const vec3& val) const;
	vec3 operator * (const vec3& val) const;
	vec3 operator / (const vec3& val) const;

	vec3 operator + (const float& val) const;
	vec3 operator - (const float& val) const;
	vec3 operator * (const float& val) const;
	vec3 operator / (const float& val) const;

	vec3 operator - (void) const;

	vec3 operator & (const vec3& rcVct) const;
	vec3 operator % (const vec3& rcVct) const;
	bool operator != (const vec3& rcVct) const;
	bool operator == (const vec3& rcVct) const;

};

vec3  operator+(float p_scalar, const vec3& p_vec);
vec3  operator-(float p_scalar, const vec3& p_vec);
vec3  operator*(float p_scalar, const vec3& p_vec);
vec3  operator/(float p_scalar, const vec3& p_vec);

//////////////////////////////////////            //////////////////////////////////////
//////////////////////////////////////    vec3    //////////////////////////////////////
//////////////////////////////////////            //////////////////////////////////////

int   print(const vec3& v);

float dot(const vec3& v, const vec3& val);
float sqr(const vec3& v);
float len_sq(const vec3& v);
float length(const vec3& v);
float distance(const vec3& v, const vec3& val);
float magnitude(const vec3& v);
float GetAngle(const vec3& v, const vec3& rcVect);

vec3  mix(const vec3& a, const vec3& b, float factor);
vec3  clamp(const vec3& v, float a, float b);
vec3  clamp(const vec3& v, const vec3& a, const vec3& b);
vec3  saturate(const vec3& v);

vec3  smoothstep(const vec3& v, float a, float b);
vec3  smoothstep(const vec3& v, const vec3& a, const vec3& b);

vec3  smootherstep(const vec3& v, float a, float b);
vec3  smootherstep(const vec3& v, const vec3& a, const vec3& b);

vec3  normalize(const vec3& v);
vec3  cross(const vec3& v, const vec3& val);
vec3  sqrt(const vec3& a);

vec3  reflect(const vec3& I, const vec3& N);
vec3  refract(const vec3& I, const vec3& N, float eta);
vec3  calcNormal(const vec3& v1, const vec3& v2, const vec3& v3);
vec3  faceNormal(const vec3& v1, const vec3& v2, const vec3& v3);
vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref);

vec3  rotateXTurn(const vec3& v, float val);
vec3  rotateXDeg(const vec3& v, float val);
vec3  rotateXGrad(const vec3& v, float val);
vec3  rotateXRad(const vec3& v, float val);

vec3  rotateYTurn(const vec3& v, float val);
vec3  rotateYDeg(const vec3& v, float val);
vec3  rotateYGrad(const vec3& v, float val);
vec3  rotateYRad(const vec3& v, float val);

vec3  rotateZTurn(const vec3& v, float val);
vec3  rotateZDeg(const vec3& v, float val);
vec3  rotateZGrad(const vec3& v, float val);
vec3  rotateZRad(const vec3& v, float val);

vec3  rotateTurn(const vec3& v, const vec3& val);
vec3  rotateDeg(const vec3& v, const vec3& val);
vec3  rotateGrad(const vec3& v, const vec3& val);
vec3  rotateRad(const vec3& v, const vec3& val);

vec3  rotateAroundAxis(const vec3& p, const vec3& axis, float angle);

vec3  rotateAxis(const vec3& v, const vec3& axis, float theta);

float DistanceToLine(const vec3& base, const vec3& rclDirect, const vec3& point);

float distanceToLine(const vec3& P, const vec3& A, const vec3& B);

















