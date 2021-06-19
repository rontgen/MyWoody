/**
* Author:gwang
* Date: 2021-06-19
* Description: provide common function for Canvas
*/

#pragma once
#include <SDL.h>
#include "MathToolkit.h"
#include "Vector2.h"
#include "Color.h"
#include "Vector3.h"

struct vertex
{
    Vector2 p;
    Color c;
};


class Canvas
{
public:
    Canvas(int pw, int ph);
    ~Canvas();
    void drawPixel(const Color& c, int x, int y);
    void drawLine(const Color& c, int sx, int sy, int ex, int ey);
    void drawPrimitive(const vertex& v1, const vertex& v2, const vertex& v3);
    
    static Vector3 getBarycentricCoord(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& p);
public:
    UINT32* pixelData;
    //width
    int w;
    //height
    int h;
    SDL_Rect rect;
};
