/**
* Author:gwang
* Date: 2021-07-19
* Description: provide common function for Matrix
*/

#pragma once

#include <vector>
#include "Def.h"
#include "Vector4.h"

using std::vector;

class Matrix
{
public:
    Matrix() = default;
    Matrix(float);
    Matrix(const Matrix&);
    Matrix(vector<vector<float>> vec);

    Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix operator*(const Matrix& m) const;
    Matrix operator*(const float m) const;
    Vector4 operator*(Vector4 v) const;

    void show() const;
    Matrix eye(int);

    Matrix inv(Matrix);
    float det();
    Matrix transpose();
private:
    float m[4][4];
};
