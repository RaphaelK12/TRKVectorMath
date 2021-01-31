
#pragma once

class vec2 {
public:
	union {
		struct {
			float x, y;
		};
		struct {
			float r, g;
		};
		float v[2];
		//unsigned long long bits;
	};

	~vec2();
	vec2();
	vec2(const float fX, const float fY);
	vec2(const float fX);
	vec2(const vec2& val);

	float& operator [] (unsigned short idx);
	const float& operator [] (unsigned short idx) const;

	vec2 operator-() const;


	vec2& operator = (const vec2& val);
	vec2& operator = (const float& val);

	vec2& operator += (const vec2& val);
	vec2& operator -= (const vec2& val);
	vec2& operator *= (const vec2& val);
	vec2& operator /= (const vec2& val);

	vec2& operator += (const float& val);
	vec2& operator -= (const float& val);
	vec2& operator *= (const float& val);
	vec2& operator /= (const float& val);

	vec2 operator + (const vec2& val)const;
	vec2 operator - (const vec2& val)const;
	vec2 operator * (const vec2& val)const;
	vec2 operator / (const vec2& val)const;

	vec2 operator + (const float& val)const;
	vec2 operator - (const float& val)const;
	vec2 operator * (const float& val)const;
	vec2 operator / (const float& val)const;

	vec2 operator & (const vec2& rcVct) const;
	vec2 operator % (const vec2& rcVct) const;
	bool operator != (const vec2& rcVct) const;
	bool operator == (const vec2& rcVct) const;

};

vec2  operator+(float p_scalar, const vec2& p_vec);
vec2  operator-(float p_scalar, const vec2& p_vec);
vec2  operator*(float p_scalar, const vec2& p_vec);
vec2  operator/(float p_scalar, const vec2& p_vec);

vec2  mix(const vec2& a, const vec2& b, float factor);
vec2  clamp(const vec2& v, float& a, float& b);
vec2  clamp(const vec2& v, const vec2& a, const vec2& b);
vec2  saturate(const vec2& v);
vec2  smoothstep(const vec2& v, float a, float b);
vec2  smoothstep(const vec2& v, const vec2& a, const vec2& b);
vec2  smootherstep(const vec2& v, float a, float b);
vec2  smootherstep(const vec2& v, const vec2& a, const vec2& b);

int   print(const vec2& v);

vec2  normalize(const vec2& v);
float distance(const vec2& v, const vec2& val);
float dot(const vec2& v, const vec2& val);
float GetAngle(const vec2& v, const vec2& rcVect);
float sqr(const vec2& v);
float length(const vec2& v);
float len_sq(const vec2& v);
float cross(const vec2& v, const vec2& val);

vec2  rotateTurn(const vec2& v, float val);
vec2  rotateDeg (const vec2& v, float val);
vec2  rotateGrad(const vec2& v, float val);
vec2  rotateRad (const vec2& v, float val);

void  fitImage(const vec2& screen, const vec2& im, float zoom, vec2& rcStart, vec2& rcEnd);

float DistanceToLine(const vec2& base, const vec2& rclDirect, const vec2& point);
float pDistance(const vec2& point, const vec2& l1, const vec2& l2);

float magnitude(const vec2& v);

float angle(const vec2& v);
bool  is_normalized(const vec2& v);
float distance_to(const vec2& v, const vec2& p_vec2);
float distance_squared_to(const vec2& v, const vec2& p_vec2);
float angle_to(const vec2& v, const vec2& p_vec2);
float angle_to_point(const vec2& v, const vec2& p_vec2);
float dot(const vec2& v, const vec2& p_other);
float cross(const vec2& v, const vec2& p_other);
vec2  floor(const vec2& v);
vec2  ceil(const vec2& v);
vec2  round(const vec2& v);
vec2  rotated(const vec2& v, float p_by);
vec2  posmod(const vec2& v, float p_mod);
vec2  posmodv(const vec2& v, const vec2& p_modv);
vec2  project(const vec2& v, const vec2& p_b);
vec2  snapped(const vec2& v, const vec2& p_by);
vec2  clamped(const vec2& v, float p_len);
vec2  cubic_interpolate(const vec2& v, const vec2& p_b, const vec2& p_pre_a, const vec2& p_post_b, float p_t);
vec2  move_toward(const vec2& v, const vec2& p_to,  float p_delta);
vec2  slide(const vec2& v, const vec2& p_normal);
vec2  reflect(const vec2& v, const vec2& p_normal);
vec2  bounce(const vec2& v, const vec2& p_normal);
bool  is_equal_approx(const vec2& v, const vec2& p_v);












