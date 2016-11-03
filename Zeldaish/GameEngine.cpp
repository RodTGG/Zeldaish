#include "stdafx.h"
#include "GameEngine.h"
#include "Button.h"


GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}

void GameEngine::display() 
{

}

void GameEngine::handleInput() 
{
	bool quit = false;
	SDL_Event e;

	while (!quit) 
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

void GameEngine::update() 
{
	SDL_UpdateWindowSurface(gWindow);
}

void GameEngine::load() 
{

	//Load splash image
	gHelloWorld = IMG_Load("Resources/Splash.png");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Splash", IMG_GetError());
		Error::Display("Error loading resource\n");
	}
}

void GameEngine::setup()
{
	init();
	load();

	SDL_BlitScaled(gHelloWorld, NULL, gScreenSurface, NULL);

	Button* myButton = new Button("Button Play" ,"Resources/btn_play.png", 20, 20, 150, 100);
	myButton->Display(gScreenSurface);

	
	handleInput();

	close();
}

void GameEngine::init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Error::Display("SDL could not initialized");
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			Error::Display("Window could not be created");
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	IMG_Init(IMG_INIT_PNG);
}

void GameEngine::close() 
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL and Image
	IMG_Quit();
	SDL_Quit();
}