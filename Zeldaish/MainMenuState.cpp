#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	id = States::STATE_MAINMENU;
	myButton = new Button("Button Play", "btn_play.png", 20, 20, 150, 100);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Display(SDL_Surface* aSurface)
{
	myButton->Display(aSurface);
}

int MainMenuState::HandleEvent(SDL_Event* aEvent)
{
	//SDL_Event e;

	////Handle events on queue
	//SDL_PollEvent(&e);
	if (aEvent->button.button == SDL_BUTTON_LEFT)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (zFunctions->isOver(x, y, myButton->getRectangle()))
		{
			std::cout << "hello world";
		}
	}
	return 0;
}
