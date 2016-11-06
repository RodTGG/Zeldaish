#include "stdafx.h"
#include "ZeldaishEngine.h"
#include "Button.h"


ZeldaishEngine::ZeldaishEngine()
{
	e = new SDL_Event();
	gFunctions = new ZeldaishFunctions();
	gStateManager = new StateManager();
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
	std::cout << "Threaad display started";
	do
	{
		// Clear Screen
		SDL_FillRect(gScreenSurface, NULL, 0x000000);

		gStateManager->getCurrentSate()->Display(gScreenSurface);

		// Update window
		SDL_UpdateWindowSurface(gWindow);
		std::this_thread::sleep_for(std::chrono::seconds(1));

	} while (!exiting);
}

void ZeldaishEngine::handleEvent()
{
	States result = STATE_NULL;


	result = gStateManager->getCurrentSate()->HandleEvent();
	gStateManager->setNextState(result);

	if (exiting)
	{
		close();
	}
}

void ZeldaishEngine::update()
{
	gStateManager->changeState();
}

void ZeldaishEngine::load()
{
	// load image texture
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

void ZeldaishEngine::run()
{
	gDisplayThread = new std::thread(&ZeldaishEngine::display, this);
	//gEventThread = new std::thread(&ZeldaishEngine::checkEvent, this);
	//std::thread update();
	//std::thread input();

	do
	{
		//display();
		handleEvent();
		update();
	} while (!isExiting());
}

void ZeldaishEngine::setup()
{
	init();
	load();
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
	gDisplayThread->join();
	gEventThread->join();

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