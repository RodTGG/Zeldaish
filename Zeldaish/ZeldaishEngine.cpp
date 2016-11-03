#include "stdafx.h"
#include "ZeldaishEngine.h"
#include "Button.h"


ZeldaishEngine::ZeldaishEngine()
{
	myButton = new Button("Button Play", "btn_play.png", 20, 20, 150, 100);
	zeldaFunctions = new ZeldaishFunctions();
	gWindow = NULL;
	gScreenSurface = NULL;
	SplashScreen = NULL;
}


ZeldaishEngine::~ZeldaishEngine()
{
}

void ZeldaishEngine::display()
{
	// Clear Screen
	SDL_FillRect(gScreenSurface, NULL, 0x000000);
}

void ZeldaishEngine::handleInput()
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
			else if (e.type == SDL_MOUSEBUTTONDOWN) 
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if (e.button.button == SDL_BUTTON_LEFT && zeldaFunctions->isOver(x,y,myButton->getRectangle())) 
				{
					quit = true;
				}
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

	myButton->Display(gScreenSurface);

	update();
	handleInput();
	close();
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