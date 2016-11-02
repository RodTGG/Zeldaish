#pragma once
class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void init();
	void setup();
	void close();
	void load();

	void handleInput();
	void update();
	void display();
private:
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;
};

