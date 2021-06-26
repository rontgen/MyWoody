#include <iostream>
#include <string>
#include <SDL.h>
#include<SDL_image.h>

#include "MyCanvas.h"

using std::cout;
using std::endl;
using std::string;


const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 640;

//SDL_Texture* loadTexture(string path);
SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gTexture = nullptr;
SDL_Texture* gRenderTarget = nullptr;

bool init();
void closeWnd();

int main(int argc, char *argv[]) //main函数必须要有参数
{
    

    //gWindow = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN /*| SDL_WINDOW_BORDERLESS*/);
    if (!init())
    {
        cout << "init error" << endl;
    }
    else
    {
        gRenderTarget = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
        MyCanvas* pCan = new MyCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);

        vertex triangle[3];
        triangle[0].p = Vector2(512, 100);
        triangle[1].p = Vector2(128, 480);
        triangle[2].p = Vector2(896, 480);
        triangle[0].c = Color(1.0f, 0.0f, 0.0f);
        triangle[1].c = Color(0.0f, 1.0f, 0.0f);
        triangle[2].c = Color(0.0f, 0.0f, 1.0f);

        UINT8 uQuit = 1;
        while (uQuit)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    uQuit = 0;
                }
            }

            pCan->drawPrimitive(triangle[0], triangle[1], triangle[2]);

            SDL_RenderClear(gRenderer);
            void* mPixels;
            int pitch = 0;
            SDL_LockTexture(gRenderTarget, nullptr, &mPixels, &pitch);
            memcpy(mPixels, pCan->pixelData, pCan->w * 4 * pCan->h);
            SDL_UnlockTexture(gRenderTarget);

            SDL_RenderCopy(gRenderer, gRenderTarget, nullptr, &pCan->rect);

            SDL_RenderPresent(gRenderer);
        }
    }

    cout << "Window Create Success" << endl;
    closeWnd();
    return 0;
}

bool init()
{
    bool bSuccess = true;
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    { 
        cout << "SDL could not initialize SDL_ERROR:"<< SDL_GetError() << endl;
        bSuccess = false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (!gWindow)
        {
            cout << "window create failed" << endl;
            bSuccess = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!gRenderer)
            {
                cout << "Renderer error and errorCode:" << SDL_GetError() << endl;
                bSuccess = false;
            } 
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0x29, 0x6F, 0x58, 0xFF);
                int imgFlag = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlag) & imgFlag))
                {
                    cout << "SDL_img init error and errorCode:" << SDL_GetError() << endl;
                    bSuccess = false;
                }
            }
        }
    }
    return bSuccess;
}

void closeWnd()
{
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SDL_Quit();
}
