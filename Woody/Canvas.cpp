#include "Canvas.h"

Canvas::Canvas(int pw, int ph)
    :w(pw)
    ,h(ph)
{
    pixelData = new UINT32[w*h];
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;
}

Canvas::~Canvas()
{
    if (pixelData)
    {
        delete[] pixelData;
        pixelData = nullptr;
    }
}

void Canvas::drawPixel(const Color& c, int x, int y)
{
    if (x>=0 && x<w && y>=0 && y<h)
    {
        pixelData[x + y * w] = c.toUint32();
    }
}

void Canvas::drawLine(const Color& c, int sx, int sy, int ex, int ey)
{
    //startPos=endPos
    if (sx == ex && sy == ey)
    {
        drawPixel(c, sx, sy);
    }
    else if (sx == ex)
    {
        //draw veritcal line
        auto inc = (sy < ey) ? 1 : -1;
        for (int y=sy;y!=ey; y+=inc)
        {
            drawPixel(c, sx, y);
        }
        drawPixel(c, ex, ey);
    }
    else if (sy == ey)
    {
        //draw horizontal line
        auto inc = (sx < ex) ? 1 : -1;
        for (int x=sx; x!=ex; x+=inc)
        {
            drawPixel(c, sx, x);
        }
        drawPixel(c, ex, sy);
    }
    else
    {
        int dx = abs(ex - sx);
        int dy = abs(ey - sy);
        if (dx>=dy)
        {
            //-1<=slope<=1
            int acc = 0;
            int incX = (sx > ex) ? -1 : 1;
            int incY = (sy > ey) ? -1 : 1;
            for (int x=sx,y=sy; x!=ex && y!=ey; x+=incX )
            {
                drawPixel(c, x, y);
                acc += dy;
                if (acc >= dx)
                {
                    acc -= dx;
                    y += incY;
                }
            }
            drawPixel(c, ex, ey);
        } 
        else
        {
            //slope>1 || slope<-1
            int acc = 0;
            int incX = (sx > ex) ? -1 : 1;
            int incY = (sy > ey) ? -1 : 1;
            for (int x=sx,y=sy; x!=ex && y!=ey; y+=incY)
            {
                drawPixel(c, x, y);
                acc += dx;
                if (acc >= dy)
                {
                    acc -= dy;
                    x += incX;
                }
            }
            drawPixel(c, ex, ey);
        }
    }
}

void Canvas::drawPrimitive(const vertex& v1, const vertex& v2, const vertex& v3)
{
    for (int i=0;i<h;++i)
    {
        for (int j=0;j<w; ++j)
        {
            Vector3 baryCoord = getBarycentricCoord(v1.p, v2.p, v3.p, Vector2(j,i));
            if (baryCoord.x>=0 && baryCoord.x<=1 &&baryCoord.y>=0 && baryCoord.y<=1 && baryCoord.z>=0 && baryCoord.z<=1)
            {
                drawPixel(v1.c *baryCoord.x + v2.c*baryCoord.y + v3.c*baryCoord.z, j, i);
            }
        }
    }
}
/*   i  j   k
 *  v1.x    v1.y    v1.z
 *  v2.x    v2.y    v2.z
 *  v3.x    v3.y    v3.z
 */
Vector3 Canvas::getBarycentricCoord(const Vector2& v1, const Vector2& v2, const Vector2& v3, const Vector2& p)
{
    float u = ((v2.y - v3.y)*p.x + (v3.x - v2.x)*p.y + v2.x*v3.y - v3.x*v2.y) / ((v2.y - v3.y)*v1.x + (v3.x - v2.x)*v1.y + v2.x*v3.y - v3.x*v2.y);
    float v = ((v1.y - v3.y)*p.x + (v3.x - v1.x)*p.y + v1.x*v3.y - v3.x*v1.y) / ((v1.y - v3.y)*v2.x + (v3.x - v1.x)*v2.y + v1.x*v3.y - v3.x*v1.y);
    float w = 1 - u - v;
    return Vector3(u, v, w);
}
