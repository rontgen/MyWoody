#include "Color.h"


void Color::initUint8(float r, float g, float b , float a) 
{
    ur = static_cast<UINT8>(r * 255);
    ug = static_cast<UINT8>(g * 255);
    ub = static_cast<UINT8>(b * 255);
    ua = static_cast<UINT8>(a * 255);
}

void Color::initFloat(UINT8 r, UINT8 g, UINT8 b, UINT8 a)
{
    static float oneOver255 = (float)(1.f / 255.f);
    fr = r * oneOver255;
    fg = g * oneOver255;
    fb = b * oneOver255;
    fa = a * oneOver255;
}

Color::Color()
    : fr(0.f)
    , fg(0.f)
    , fb(0.f)
    , fa(1.f)
{
    ur = static_cast<UINT8>(fr * 255);
    ug = static_cast<UINT8>(fg * 255);
    ub = static_cast<UINT8>(fb * 255);
    ua = static_cast<UINT8>(fa * 255);
}

Color::Color(float r, float g, float b, float a)
    :fr(r)
    ,fg(g)
    ,fb(b)
    ,fa(a)
{
    ur = static_cast<UINT8>(r * 255);
    ug = static_cast<UINT8>(g * 255);
    ub = static_cast<UINT8>(b * 255);
    ua = static_cast<UINT8>(a * 255);
}

Color::Color(const Color& c)
    :ur(c.ur)
    ,ug(c.ug)
    ,ub(c.ub)
    ,ua(c.ua)
    ,fr(c.fr)
    ,fg(c.fg)
    ,fb(c.fb)
    ,fa(c.fa)
{
}

Color& Color::operator=(const Color& c)
{
    ur = c.ur;
    ub = c.ub;
    ug = c.ug;
    ua = c.ua;
    fr = c.fr;
    fg = c.fg;
    fb = c.fb;
    fa = c.fa;
    return *this;
}


Color::Color(UINT32 c)
{
    ur = c >> 24 & 0xFF;
    ug = c >> 16 & 0xFF;
    ub = c >> 8 & 0xFF;
    ua = c & 0xFF;

    float oneOver255 = (float)(1.f / 255.f);
    fr = ur * oneOver255;
    fg = ug * oneOver255;
    fb = ub * oneOver255;
    fa = ua * oneOver255;
}

Color Color::operator*(const Color& c) const
{
    return Color(fr*c.fr, fg*c.fg, fb*c.fb);
}

Color Color::operator*(float a) const
{
    return Color(fr*a, fg*a, fb*a);
}

Color Color::operator+(const Color& c) const
{
    return Color(fr + c.fr, fg + c.fg, fb + c.fb);
}

UINT32 Color::toUint32() const
{
    return ur << 24 | ug << 16 | ub << 8 | ua;
}
