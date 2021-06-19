/**
* Author:gwang
* Date: 2021-06-19
* Description: provide common function for Vector4
*/

#pragma once

#include "MathToolkit.h"

class Vector4
{
public:
    Vector4();
    Vector4(float px, float py, float pz, float pw=1.f);
    Vector4(const Vector4& v);
    Vector4& operator=(const Vector4& v);

    bool operator==(const Vector4& v) const;
    bool operator!=(const Vector4& v) const;

    Vector4 operator-() const;
    Vector4 operator+(const Vector4& v) const;
    Vector4 operator-(const Vector4& v) const;

    Vector4& operator+=(const Vector4& v);
    Vector4& operator-=(const Vector4& v);

    Vector4 operator/(float p) const;
    Vector4 operator*(float p) const;
    Vector4& operator/=(float p);
    Vector4& operator*=(float p);

    float operator|(const Vector4& v) const;

    void zero();
    void normalize();
    inline float len() { return sqrtf(*this | *this); }
    
    static Vector4 sCross(const Vector4& a, const Vector4& b);
    static float sDistance(const Vector4& a, const Vector4& b);
    static Vector4 sLeap(const Vector4& x, const Vector4& y, float p);

public:
    float x, y, z, w;
};

Vector4 operator*(float p, const Vector4& v);
