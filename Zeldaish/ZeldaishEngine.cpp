#include "stdafx.h"
#include "ZeldaishEngine.h"
#include "Button.h"


ZeldaishEngine::ZeldaishEngine()
{
	gStateManager = new StateManager();
	gWindow = NULL;
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
		std::this_thread::sleep_for(std::chrono::nanoseconds(50));

	} while (!exiting);
}

void ZeldaishEngine::handleEvent()
{
	States result = STATE_NULL;

	std::cout << "Handling event for " + gStateManager->getCurrentSate()->getName() << std::endl;
	result = gStateManager->getCurrentSate()->HandleEvent(gRenderer);
	gStateManager->setNextState(result);
	std::cout << "Setting next state: " + gStateManager->getNextState()->getName() << std::endl;

	if (result == STATE_EXIT)
	{
		exiting = true;
		close();
	}

	std::cout << "Updating" << std::endl;
	gStateManager->changeState();
}

void ZeldaishEngine::update()
{
	do
	{
		gStateManager->getCurrentSate()->Update();
		//Sleep thread
		std::this_thread::sleep_for(std::chrono::nanoseconds(10));
	} while (!exiting);
}

void ZeldaishEngine::load()
{
	std::cout << "Displaying Splashscreen" << std::endl;
	// load image texture
	SplashScreen = ZeldaishFunctions::loadTexture(*gRenderer, "Splash.png");
	SDL_RenderCopy(gRenderer, SplashScreen, NULL, NULL);
	SDL_RenderPresent(gRenderer);

	//Clear memory
	SDL_DestroyTexture(SplashScreen);
	SDL_Delay(1000);
}

void ZeldaishEngine::run()
{
	std::cout << "Initializing display thread" << std::endl;
	gDisplayThread = new std::thread(&ZeldaishEngine::display, this);
	gUpdateThread = new std::thread(&ZeldaishEngine::update, this);

	std::cout << "Starting game loop" << std::endl;
	do
	{
		handleEvent();
		std::this_thread::sleep_for(std::chrono::nanoseconds(10));
	} while (!isExiting());
}

void ZeldaishEngine::setup()
{
	std::cout << "Calling initialization function" << std::endl;
	init();
	std::cout << "Setting render logical size" << std::endl;
	SDL_RenderSetLogicalSize(gRenderer, 800, 600);
	std::cout << "Calling Load" << std::endl;
	load();
	std::cout << "Loaded engine" << std::endl;
}

void ZeldaishEngine::init()
{
	std::cout << "Initializing Engine" << std::endl;
	std::cout << "Initializing SDL" << std::endl;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0)
	{
		Error::Display("SDL could not initialized");
	}
	//Initialize IMG
	std::cout << "Initializing IMG" << std::endl;
	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		Error::Display("Could not initialize SDL IMG");
	}
	//Initialize MIX
	std::cout << "Initializing Mix" << std::endl;
	if (Mix_Init(MIX_INIT_MP3) < 0)
	{
		Error::Display("Error with mixer");
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	//Initialize Audio Channel
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		Error::Display("Error with mixer");
	}

	std::cout << "Creating Window" << std::endl;
	//to set fullscreen use SDL_WINDOW_FULLSCREEN flag
	gWindow = SDL_CreateWindow("Zeldaish", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		Error::Display("Window could not be created");
	}
	//Initialize Renderer
	std::cout << "Creating renderer" << std::endl;
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		Error::Display("unable to initialize renderer");
	}
}

void ZeldaishEngine::close()
{
	std::cout << "Started Closing" << std::endl;
	//Close Threads
	std::cout << "Joining Threads" << std::endl;
	gDisplayThread->join();
	std::cout << "display thread joined" << std::endl;
	gUpdateThread->join();
	std::cout << "update thread joined" << std::endl;

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);

	//Quit SDL and Image
	std::cout << "Closing Mix" << std::endl;
	Mix_CloseAudio();
	std::cout << "Closing IMG" << std::endl;
	IMG_Quit();
	std::cout << "Closing SDL" << std::endl;
	SDL_Quit();
	std::cout << "Bye!" << std::endl;
}

bool ZeldaishEngine::isExiting()
{
	return exiting;
}