#include "Vector3.h"


Vector3::Vector3(float px, float py, float pz)
    : x(px)
    ,y(py)
    ,z(pz)
{}
Vector3::Vector3(const Vector3& v)
    :x(v.x)
    ,y(v.y)
    ,z(v.z)
{}

Vector3& Vector3::operator=(const Vector3 v)
{}

bool Vector3::operator==(const Vector3& v) const
{
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3::operator!=(const Vector3& v) const
{
    return x != v.x && x != v.y && x != v.z;
}

//向量点乘
float Vector3::operator|(const Vector3& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}
Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}
Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 Vector3::operator*(float p) const
{
    return Vector3(x*p, y*p, z*p);
}

Vector3 Vector3::operator/(float p) const
{
    //TODO:check 0
    float oneOverP = 1.f / p;
    return Vector3(x*oneOverP, y*oneOverP, z*oneOverP);
}

Vector3& Vector3::operator*=(const Vector3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

void Vector3::zero()
{
    x = y = z = 0.f;
}
void Vector3::normalize()
{
    float le = this->len();
    if (le-0.f> sfFloatZeroCheck)
    {
        float inv = 1.f / le;
        x = x * inv;
        y = y * inv;
        z = z * inv;
    }
}
/*
    i	j	k
    a.x	a.y	a.z
    b.x	b.y b.z
 */
Vector3 Vector3::sCross(const Vector3& a, const Vector3& b)
{
    return Vector3(a.y*b.z - a.z*b.y, -a.x*b.z + a.z*b.x, a.x*b.y - a.y*b.x);
}


float Vector3::sDistance(const Vector3& a, const Vector3& b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;
    return sqrtf(dx*dx+dy*dy+dz*dz);
}

Vector3 Vector3::sLeap(const Vector3& x, const Vector3& y, float p)
{
    return LinearInterpolate<Vector3, float>(x, y, p);
}

Vector3 operator*(float p, const Vector3& v)
{
    return Vector3(p*v.x, p*v.y, p*v.z);
}
