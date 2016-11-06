#pragma once
#include "StateManager.h"
#include "Button.h"

class ZeldaishEngine
{
public:
	ZeldaishEngine();
	~ZeldaishEngine();

	void init();
	void setup();
	void close();
	void load();

	void handleEvent();
	void update();
	void display();
	void run();

	bool isExiting();
private:
	bool exiting;

	std::thread* gDisplayThread;
	std::thread* gEventThread;

	SDL_Event* e;
	ZeldaishFunctions* gFunctions;
	StateManager* gStateManager;

	//The window we'll be rendering to
	SDL_Window* gWindow;

	//The surface contained by the window
	SDL_Surface* gScreenSurface;

	//The image we will load and show on the screen
	SDL_Surface* SplashScreen;
};

