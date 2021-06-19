/**
* Author:gwang
* Date: 2021-06-19
* Description: provide common function for Vector3
*/


#pragma once

#include "MathToolkit.h"

class Vector3
{
public:
    Vector3() = default;
    Vector3(float px, float py, float pz);
    Vector3(const Vector3& v);
    Vector3& operator=(const Vector3& v);

    bool operator==(const Vector3& v) const;
    bool operator!=(const Vector3& v) const;

    //向量点乘
    float operator|(const Vector3& v) const;

    Vector3 operator-() const;
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;

    //标量运算
    Vector3 operator*(float p) const;
    Vector3 operator/(float p) const;
    Vector3& operator*=(float p);
    Vector3& operator/=(float p);

    //向量运算
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);

    void zero();
    void normalize();

    inline float len(){ return sqrtf(*this | *this); }

    static Vector3 sCross(const Vector3& a, const Vector3& b);
    static float sDistance(const Vector3& a, const Vector3& b);
    static Vector3 sLeap(const Vector3& x, const Vector3& y, float p);

public:
    float x, y, z;
};

//标量左乘
Vector3 operator*(float p, const Vector3& v);

