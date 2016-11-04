#include "stdafx.h"
#include "AboutState.h"


AboutState::AboutState()
{
	gId = States::STATE_ABOUT;
	btnBack = new Button("Button Play", "btn_play.png", 50, 50, 150, 100);
}


AboutState::~AboutState()
{
}

void AboutState::Display(SDL_Surface* aSurface)
{
	btnBack->Display(aSurface);
}

States AboutState::HandleEvent(SDL_Event* aEvent) 
{
	States result;
	int x, y;
	SDL_GetMouseState(&x, &y);

	if (gFunctions->leftMouseButtonClicked(aEvent) && gFunctions->isOver(x, y, btnBack->getRectangle()))
	{
		result = States::STATE_MAINMENU;
	}
	else 
	{
		result = States::STATE_ABOUT;
	}

	return result;
}
