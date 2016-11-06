#include "stdafx.h"
#include "ExitState.h"


ExitState::ExitState()
{
	gId = States::STATE_EXIT;
}


ExitState::~ExitState()
{
}

void ExitState::Display(SDL_Surface* aSurface)
{
	SDL_Surface exitSurface = *IMG_Load("Resources/exit.png");
	SDL_BlitSurface(&exitSurface, NULL, aSurface, NULL);
}

States ExitState::HandleEvent()
{
	States result;
	
	result = States::STATE_EXIT;
	SDL_Delay(2000);

	exit(0);
}