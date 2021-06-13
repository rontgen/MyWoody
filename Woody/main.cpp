#include <iostream>
#include "SDL.h"

using namespace std;

int main(int argc, char *argv[]) //main��������Ҫ�в���
{
	SDL_Window *pWindow = NULL;
	SDL_Init(SDL_INIT_VIDEO);

	pWindow = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, SDL_WINDOW_SHOWN /*| SDL_WINDOW_BORDERLESS*/);
	if (!pWindow)
	{
		cout << "window create failed" << endl;
		SDL_Quit();
		return -1;
	}

	cout << "Window Create Success" << endl;
	SDL_DestroyWindow(pWindow);

	SDL_Quit();
	return 0;
}