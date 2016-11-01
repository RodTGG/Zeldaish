#include "stdafx.h"

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;

	window = SDL_CreateWindow("sdl test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	while (true) 
	{
	}

	return 0;
}