#include "Vector4.h"


Vector4::Vector4()
    :x(0.f)
    ,y(0.f)
    ,z(0.f)
    ,w(1.f)
{}

Vector4::Vector4 (float px, float py, float pz, float pw)
    :x(px)
    ,y(py)
    ,z(pz)
    ,w(pw)
{}

Vector4::Vector4(const Vector4& v)
    : x(v.x)
    ,y(v.y)
    ,z(v.z)
    ,w(v.w)
{}

Vector4& Vector4::operator=(const Vector4& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
    return *this;
}

bool Vector4::operator==(const Vector4& v) const
{
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

bool Vector4::operator!=(const Vector4& v) const
{
    return x != v.x && y != v.y && z != v.z && w != v.w;
}

Vector4 Vector4::operator-() const
{
    return Vector4(-x, -y, -z);
}

Vector4 Vector4::operator+(const Vector4& v) const
{
    return Vector4(x + v.x, y + v.y, z + v.z);
}

Vector4 Vector4::operator-(const Vector4& v) const
{
    return Vector4(x - v.x, y - v.y, z - v.z);
}

Vector4& Vector4::operator+=(const Vector4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}


Vector4 Vector4::operator/(float p) const
{
    float oneOverP = 1.f / p;
    return Vector4(x*oneOverP, y*oneOverP, z*oneOverP);
}
Vector4 Vector4::operator*(float p) const
{
    return Vector4(x*p, y*p, z*p);
}

Vector4& Vector4::operator/=(float p)
{
    float oneOverP = 1.f / p;
    x *= oneOverP;
    y *= oneOverP;
    z *= oneOverP;
    return *this;
}

Vector4& Vector4::operator*=(float p)
{
    x *= p;
    y *= p;
    z *= p;
    return *this;
}

float Vector4::operator|(const Vector4& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

void Vector4::zero()
{
    x = y = z = 0.f;
}
void Vector4::normalize()
{
    float l = this->len();
    if (l!=0.f)
    {
        float inv = 1.f / l;
        x *= inv;
        y *= inv;
        z *= inv;
    }
}

/*
    i	j	k
    a.x	a.y	a.z
    b.x	b.y b.z
 */
Vector4 Vector4::sCross(const Vector4& a, const Vector4& b)
{
    return Vector4(
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    );
}

float Vector4::sDistance(const Vector4& a, const Vector4& b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return sqrtf(dx*dx + dy * dy + dz * dz);
}

Vector4 Vector4::sLeap(const Vector4& x, const Vector4& y, float p)
{
    return LinearInterpolate(x, y, p);
}

Vector4 operator*(float p, const Vector4& v)
{
    return Vector4(p * v.x, p*v.y, p*v.z);
}
