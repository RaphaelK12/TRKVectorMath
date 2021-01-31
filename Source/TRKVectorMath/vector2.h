

#pragma once

struct Vector2 {
	union {
		struct {
			union {
				float x, r, width;
			};
			union {
				float y, g, height;
			};
		};
		float v[2];
	};

	float& operator[](int p_idx) {
		return p_idx ? y : x;
	}
	const float& operator[](int p_idx) const {
		return p_idx ? y : x;
	}

	void normalize();
	Vector2 normalized() const;
	bool is_normalized() const;

	float length() const;
	float length_squared() const;

	float distance_to(const Vector2& p_vector2) const;
	float distance_squared_to(const Vector2& p_vector2) const;
	float angle_to(const Vector2& p_vector2) const;
	float angle_to_point(const Vector2& p_vector2) const;
	Vector2 direction_to(const Vector2& p_b) const;

	float dot(const Vector2& p_other) const;
	float cross(const Vector2& p_other) const;
	Vector2 posmod(const float p_mod) const;
	Vector2 posmodv(const Vector2& p_modv) const;
	Vector2 project(const Vector2& p_b) const;

	Vector2 plane_project(float p_d, const Vector2& p_vec) const;

	Vector2 clamped(float p_len) const;

	Vector2 lerp(const Vector2& p_b, float p_t) const;
	Vector2 slerp(const Vector2& p_b, float p_t) const;
	Vector2 cubic_interpolate(const Vector2& p_b, const Vector2& p_pre_a, const Vector2& p_post_b, float p_t) const;
	Vector2 move_toward(const Vector2& p_to, const float p_delta) const;

	Vector2 slide(const Vector2& p_normal) const;
	Vector2 bounce(const Vector2& p_normal) const;
	Vector2 reflect(const Vector2& p_normal) const;

	bool is_equal_approx(const Vector2& p_v) const;

	Vector2 operator+(const Vector2& p_v) const;
	void operator+=(const Vector2& p_v);
	Vector2 operator-(const Vector2& p_v) const;
	void operator-=(const Vector2& p_v);
	Vector2 operator*(const Vector2& p_v1) const;

	Vector2 operator*(const float& rvalue) const;
	void operator*=(const float& rvalue);
	void operator*=(const Vector2& rvalue) {
		*this = *this * rvalue;
	}

	Vector2 operator/(const Vector2& p_v1) const;

	Vector2 operator/(const float& rvalue) const;

	void operator/=(const float& rvalue);
	void operator/=(const Vector2& rvalue) {
		*this = *this / rvalue;
	}

	Vector2 operator-() const;

	bool operator==(const Vector2& p_vec2) const;
	bool operator!=(const Vector2& p_vec2) const;

	bool operator<(const Vector2& p_vec2) const {
		return x == p_vec2.x ? (y < p_vec2.y) : (x < p_vec2.x);
	}
	bool operator>(const Vector2& p_vec2) const {
		return x == p_vec2.x ? (y > p_vec2.y) : (x > p_vec2.x);
	}
	bool operator<=(const Vector2& p_vec2) const {
		return x == p_vec2.x ? (y <= p_vec2.y) : (x < p_vec2.x);
	}
	bool operator>=(const Vector2& p_vec2) const {
		return x == p_vec2.x ? (y >= p_vec2.y) : (x > p_vec2.x);
	}

	float angle() const;

	Vector2 abs() const {
		return Vector2(::abs(x), ::abs(y));
	}

	Vector2 rotated(float p_by) const;
	Vector2 tangent() const {
		return Vector2(y, -x);
	}

	Vector2 sign() const;
	Vector2 floor() const;
	Vector2 ceil() const;
	Vector2 round() const;
	Vector2 snapped(const Vector2& p_by) const;
	float aspect() const {
		return width / height;
	}

	Vector2() {}
	Vector2(float p_x, float p_y) {
		x = p_x;
		y = p_y;
	}
};

Vector2 Vector2::plane_project(float p_d, const Vector2& p_vec) const {
	return p_vec - *this * (dot(p_vec) - p_d);
}

Vector2 operator*(float p_scalar, const Vector2& p_vec) {
	return p_vec * p_scalar;
}

Vector2 operator*(double p_scalar, const Vector2& p_vec) {
	return p_vec * p_scalar;
}

Vector2 operator*(int32_t p_scalar, const Vector2& p_vec) {
	return p_vec * p_scalar;
}

Vector2 operator*(int64_t p_scalar, const Vector2& p_vec) {
	return p_vec * p_scalar;
}

Vector2 Vector2::operator+(const Vector2& p_v) const {
	return Vector2(x + p_v.x, y + p_v.y);
}

void Vector2::operator+=(const Vector2& p_v) {
	x += p_v.x;
	y += p_v.y;
}

Vector2 Vector2::operator-(const Vector2& p_v) const {
	return Vector2(x - p_v.x, y - p_v.y);
}

void Vector2::operator-=(const Vector2& p_v) {
	x -= p_v.x;
	y -= p_v.y;
}

Vector2 Vector2::operator*(const Vector2& p_v1) const {
	return Vector2(x * p_v1.x, y * p_v1.y);
}

Vector2 Vector2::operator*(const float& rvalue) const {
	return Vector2(x * rvalue, y * rvalue);
}

void Vector2::operator*=(const float& rvalue) {
	x *= rvalue;
	y *= rvalue;
}

Vector2 Vector2::operator/(const Vector2& p_v1) const {
	return Vector2(x / p_v1.x, y / p_v1.y);
}

Vector2 Vector2::operator/(const float& rvalue) const {
	return Vector2(x / rvalue, y / rvalue);
}

void Vector2::operator/=(const float& rvalue) {
	x /= rvalue;
	y /= rvalue;
}

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

bool Vector2::operator==(const Vector2& p_vec2) const {
	return x == p_vec2.x && y == p_vec2.y;
}

bool Vector2::operator!=(const Vector2& p_vec2) const {
	return x != p_vec2.x || y != p_vec2.y;
}

Vector2 Vector2::lerp(const Vector2& p_b, float p_t) const {
	Vector2 res = *this;

	res.x += (p_t * (p_b.x - x));
	res.y += (p_t * (p_b.y - y));

	return res;
}

Vector2 Vector2::slerp(const Vector2& p_b, float p_t) const {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!is_normalized(), Vector2(), "The start Vector2 must be normalized.");
#endif
	float theta = angle_to(p_b);
	return rotated(theta * p_t);
}

Vector2 Vector2::direction_to(const Vector2& p_b) const {
	Vector2 ret(p_b.x - x, p_b.y - y);
	ret.normalize();
	return ret;
}



