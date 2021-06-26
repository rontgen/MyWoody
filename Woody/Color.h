/**
* Author:gwang
* Date: 2021-06-14
* Description: provide common function for Color
*/

#pragma once
#include <SDL.h>
#include "Def.h"

class Color
{
public:
    UINT8 ur, ug, ub, ua;
    float fr, fg, fb, fa;
public:
    Color();
    Color(float r, float g, float b, float a=1.f);
    Color(const Color& c);
    Color& operator=(const Color& c);
    explicit Color(UINT32 c);

    Color operator*(const Color& c) const;
    Color operator*(float a) const;
    Color operator+(const Color& c) const;

    UINT32 toUint32() const;
private:
    void initUint8(float, float, float, float);
    void initFloat(UINT8, UINT8, UINT8, UINT8);
};
