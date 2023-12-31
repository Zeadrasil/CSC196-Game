#pragma once
#include <cmath>
#include <sstream>
namespace JoeBidenWakeup
{
class Vector2
{
public:
	float x;
	float y;
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float location)
	{
		x = location;
		y = location;
	}
	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2(int x, int y)
	{
		this->x = (float)x;
		this->y = (float)y;
	}

	Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); };
	Vector2 operator - (const Vector2& v) const {return Vector2(x - v.x, y - v.y); };
	Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); };
	Vector2 operator / (const Vector2& v) const {return Vector2(x / v.x, y / v.y); };

	Vector2 operator + (float f) const { return Vector2(x + f, y + f); };
	Vector2 operator - (float f) const { return Vector2(x - f, y - f); };
	Vector2 operator * (float f) const { return Vector2(x * f, y * f); };
	Vector2 operator / (float f) const { return Vector2(x / f, y / f); };

	Vector2& operator += (const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	};
	Vector2& operator -= (const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	};
	Vector2& operator *= (const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	};
	Vector2& operator /= (const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	};

	float distanceSquared(const Vector2& v) { return (v - *this).lengthSquared(); };
	float distance(const Vector2& v) { return std::sqrt(distanceSquared(v)); };

	float lengthSquared() const { return (x * x) + (y * y); };
	float length() const { return std::sqrt(lengthSquared()); };
	Vector2 normalized() { return *this / length(); };
	void normalize() { *this /= length(); };

	float angle() const { return std::atan2f(y, x); };

	Vector2 rotateR(float radians) const;

	static float signedAngle(const Vector2& v1, const Vector2& v2);
	static float angle(const Vector2& v1, const Vector2& v2);
	static float dot(const Vector2& v1, const Vector2& v2);
};
 inline std::istream& operator >> (std::istream& stream, Vector2& v)
{
	std::string line;
	std::getline(stream, line);
	std::string xs = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
	v.x = std::stof(xs);

	std::string ys = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
	v.y = std::stof(ys);
	return stream;
}

 inline Vector2 Vector2::rotateR(float radians) const
 {
	 return { (x * std::cos(radians)) - (y * std::sin(radians)), (x * std::sin(radians)) + (y * std::cos(radians))};
 }

 inline float Vector2::angle(const Vector2& v1, const Vector2& v2)
 {
	 return std::acos(dot(v1, v2));
 }
 inline float Vector2::signedAngle(const Vector2& v1, const Vector2& v2)
 {
	 float y = v1.x * v2.y - v1.y * v2.x;
	 float x = v1.x * v2.x + v1.y * v2.y;

	 return std::atan2(y, x);
 }
 inline float Vector2::dot(const Vector2& v1, const Vector2& v2)
 {
	 return v1.x * v2.x + v1.y * v2.y;
 }
}

