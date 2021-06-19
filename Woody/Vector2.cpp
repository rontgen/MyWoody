#include "Vector2.h"

Vector2::Vector2(const Vector2& v)
	:x(v.x)
	,y(v.y)
{}
Vector2::Vector2(float px, float py)
	:x(px)
	,y(py)
{}

Vector2& Vector2::operator=(const Vector2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

bool Vector2::operator==(const Vector2& v) const
{
	return x == v.x && y == v.y;
}

bool Vector2::operator!=(const Vector2& v) const
{
	return x != v.x && y != v.y;
}

float Vector2::operator|(const Vector2& v) const
{
	return x * v.x + y * v.y;
}

//向量点乘
Vector2 Vector2::operator+(const Vector2& v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

//向量与标量乘
Vector2 Vector2::operator*(float p) const
{
	return Vector2(x*p, y*p);
}
Vector2 Vector2::operator/(float p) const
{
	static const float b = 0.000001f;
	//TODO:check 0
	float oneOverP = 1.f / p;
	return Vector2(x *oneOverP, y *oneOverP);
}
Vector2& Vector2::operator+=(float p)
{
	x += p;
	y += p;
	return *this;
}
Vector2& Vector2::operator-=(float p)
{
	x -= p;
	y -= p;
	return *this;
}
Vector2& Vector2::operator*=(float p)
{
	x *= p;
	y *= p;
	return *this;
}
Vector2& Vector2::operator/=(float p)
{
	x /= p;
	y /= p;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
void Vector2::zero()
{
	x = y = 0.f;
}

void Vector2::normalize()
{
	static const float b = 0.0000001f;
	float len = this->Length();
	if (len-0.f > b)
	{
		float invLen = 1.f / len;
		x *= invLen;
		y *= invLen;
	}
}


float Vector2::sDistance(const Vector2& a, const Vector2& b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrtf(dx*dx + dy * dy);
}

Vector2 Vector2::sLeap(const Vector2& a, const Vector2& b, float p)
{
	return LinearInterpolate<Vector2, float>(a, b, p);
}