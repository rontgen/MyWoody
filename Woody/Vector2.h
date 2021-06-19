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

	//�������
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-() const; //�෴����

	//�����������
	Vector2 operator*(float p) const;
	Vector2 operator/(float p) const;
	Vector2& operator+=(float p);
	Vector2& operator-=(float p);
	Vector2& operator*=(float p);
	Vector2& operator/=(float p);
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);

	//��Ϊ0����
	void zero();
	//��׼������
	void normalize();

	//����ģ��
	inline float Length(){ return sqrtf(*this | *this); }

	//��������
	static float sDistance(const Vector2& a, const Vector2& b);
	static Vector2 sLeap(const Vector2& a, const Vector2& b, float p);
public:
	float x, y;
};

//�������
Vector2 operator*(float p, const Vector2& v);