#include "stdafx.h"
#include "MainMenuState.h"


MainMenuState::MainMenuState()
{
	gId = States::STATE_MAINMENU;
	btnPlay = new Button("Button Play", "btn_play.png", 20, 20, 150, 100);
	btnAbout = new Button("Button About", "btn_about.png", 20, 140, 150, 100);
	btnExit = new Button("Button Exit", "btn_exit.png", 20, 260, 150, 100);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::Display(SDL_Surface* aSurface)
{
	btnPlay->Display(aSurface);
	btnAbout->Display(aSurface);
	btnExit->Display(aSurface);
}

States MainMenuState::HandleEvent(SDL_Event* aEvent)
{
	States result;
	int x, y;
	SDL_GetMouseState(&x, &y);

	if(gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnPlay->getRectangle()))
	{
		result = States::STATE_GAMEPLAY;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnAbout->getRectangle()))
	{
		result = States::STATE_ABOUT;
	}
	else if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnExit->getRectangle()))
	{
		result = States::STATE_EXIT;
	}
	else
	{
		result = States::STATE_MAINMENU;
	}

	return result;
}
