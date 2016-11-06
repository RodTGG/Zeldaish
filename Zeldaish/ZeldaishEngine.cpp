#include "stdafx.h"
#include "ZeldaishEngine.h"
#include "Button.h"


ZeldaishEngine::ZeldaishEngine()
{
	gStateManager = new StateManager();
	gWindow = NULL;
	//gScreenSurface = NULL;
	SplashScreen = NULL;
	exiting = false;
	gRenderer = NULL;
}


ZeldaishEngine::~ZeldaishEngine()
{
}

void ZeldaishEngine::display()
{
	std::cout << std::this_thread::get_id;
	std::cout << ", Thread display started" << std::endl;

	do
	{
		//Clear Screen
		SDL_RenderClear(gRenderer);

		//Display
		gStateManager->getCurrentSate()->Display(gRenderer);

		//Update screen
		SDL_RenderPresent(gRenderer);

		//Sleep thread
		std::this_thread::sleep_for(std::chrono::microseconds(50));

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
	SplashScreen = ZeldaishFunctions::loadTexture(*gRenderer,"Splash.png");
	SDL_RenderCopy(gRenderer, SplashScreen,NULL,NULL);
	SDL_RenderPresent(gRenderer);

	//Clear memory
	SDL_DestroyTexture(SplashScreen);

	SDL_Delay(1000);
	SDL_RenderPresent(gRenderer);
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
	SDL_RenderSetLogicalSize(gRenderer, 800, 600);
	load();
}

void ZeldaishEngine::init()
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0)
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

			if (IMG_Init(IMG_INIT_PNG) < 0)
			{
				Error::Display("Could not initialize SDL IMG");
			}
			else 
			{
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
				if (gRenderer == NULL)
				{
					Error::Display("unable to initialize renderer");
				}
				else 
				{
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
					{
						printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
						Error::Display("Error with mixer");
					}
				}
			}
		}
	}
}

void ZeldaishEngine::close()
{
	//Close Threads
	gDisplayThread->join();
	gEventThread->join();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	//Quit SDL and Image
	IMG_Quit();
	SDL_Quit();
}

bool ZeldaishEngine::isExiting()
{
	return exiting;
}