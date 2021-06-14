#pragma once
#include "MathToolkit.h"

class Vector2
{
public:
	Vector2();
	Vector2(const Vector2& v);
	Vector2(float px, float py);

	Vector2& operator=(const Vector2& v);
	bool operator==(const Vector2& v) const;
	bool operator!=(const Vector2& v) const;
	float operator|(const Vector2& v) const;

	//�������
	Vector2 operator+(const Vector2& v) const;
	Vector2 operator-(const Vector2& v) const;
	Vector2 operator-();

	//�����������


public:
	float x, y;
private:
};