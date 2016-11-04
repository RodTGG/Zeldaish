#include "stdafx.h"
#include "ZeldaishEngine.h"
#include "Button.h"


ZeldaishEngine::ZeldaishEngine()
{
	zeldaFunctions = new ZeldaishFunctions();
	sManager = new StateManager();
	gWindow = NULL;
	gScreenSurface = NULL;
	SplashScreen = NULL;
	exiting = false;
}


ZeldaishEngine::~ZeldaishEngine()
{
}

void ZeldaishEngine::display()
{
	// Clear Screen
	SDL_FillRect(gScreenSurface, NULL, 0x000000);

	sManager->getCurrentSate()->Display(gScreenSurface);
}

void ZeldaishEngine::handleEvent()
{
	SDL_Event* e = new SDL_Event();

	while (!exiting)
	{
		//Handle events on queue
		while (SDL_PollEvent(e) != 0)
		{
			//User requests quit
			if (e->type == SDL_QUIT)
			{
				exiting = true;
				close();
			}
			else
			{
				sManager->getCurrentSate()->HandleEvent(e);
			}
		}
	}
}

void ZeldaishEngine::update()
{
	SDL_UpdateWindowSurface(gWindow);
}

void ZeldaishEngine::load()
{
	SplashScreen = IMG_Load("Resources/Splash.png");
	if (SplashScreen == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "Splash", IMG_GetError());
		Error::Display("Error loading resource\n");
	}
	SDL_BlitScaled(SplashScreen, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);

	SDL_Delay(2000);
	SDL_FreeSurface(SplashScreen);
}

void ZeldaishEngine::setup()
{
	init();
	load();
	display();
	update();
}

void ZeldaishEngine::init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		Error::Display("SDL could not initialized");
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Zeldaish", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			Error::Display("Window could not be created");
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				Error::Display("Could not initialize SDL IMG");
			}
		}
	}
}

void ZeldaishEngine::close()
{
	SplashScreen = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL and Image
	IMG_Quit();
	SDL_Quit();
}

bool ZeldaishEngine::isExiting() 
{
	return exiting;
}