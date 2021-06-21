/**
* Author:gwang
* Date: 2021-06-19
* Description: provide common function for MyCanvas
*/

#pragma once
#include <SDL.h>
#include "MathToolkit.h"
#include "Vector2.h"
#include "Color.h"
#include "Vector3.h"


struct vertex;

class MyCanvas
{
public:
    MyCanvas(int pw, int ph)
        :w(pw)
        , h(ph)
    {
        pixelData = new UINT32[w*h];
        rect.x = 0;
        rect.y = 0;
        rect.w = w;
        rect.h = h;
    }

    ~MyCanvas();
    void drawPrimitive(const vertex& v1, const vertex& v2, const vertex& v3);

    void drawPixel(const Color& c, int x, int y);
    void drawLine(const Color& c, int sx, int sy, int ex, int ey);

    
    static Vector3 getBarycentricCoord(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& p);
public:
    UINT32* pixelData;
    //width
    int w;
    //height
    int h;
    SDL_Rect rect;
};

struct vertex
{
    Vector2 p;
    Color c;
};
