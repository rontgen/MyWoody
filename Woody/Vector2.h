/**
* Author:gwang
* Date: 2021-06-19
* Description: provide common function for Vector2
*/

#pragma once
#include "MathToolkit.h"

class Vector2
{
public:
    Vector2() = default;
    Vector2(const Vector2& v);
    Vector2(float px, float py);

    Vector2& operator=(const Vector2& v);
    bool operator==(const Vector2& v) const;
    bool operator!=(const Vector2& v) const;
    float operator|(const Vector2& v) const;

    //向量点乘
    Vector2 operator+(const Vector2& v) const;
    Vector2 operator-(const Vector2& v) const;
    Vector2 operator-() const; //相反向量

    //向量与标量乘
    Vector2 operator*(float p) const;
    Vector2 operator/(float p) const;
    Vector2& operator*=(float p);
    Vector2& operator/=(float p);

    Vector2& operator+=(const Vector2& v);
    Vector2& operator-=(const Vector2& v);

    //标准化向量
    void normalize();
    //置为0向量
    void zero();


    //向量模长
    inline float Length(){ return sqrtf(*this | *this); }

    //向量距离
    static float sDistance(const Vector2& a, const Vector2& b);
    static Vector2 sLeap(const Vector2& a, const Vector2& b, float p);
public:
    float x, y;
};

//标量左乘
Vector2 operator*(float p, const Vector2& v);
