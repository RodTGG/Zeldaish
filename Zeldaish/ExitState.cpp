#include "stdafx.h"
#include "ExitState.h"


ExitState::ExitState()
{
	gId = States::STATE_EXIT;
}


ExitState::~ExitState()
{
}

void ExitState::Display(SDL_Renderer* aRenderer)
{
	gBackground = ZeldaishFunctions::loadTexture(*aRenderer, "exit.png");
	SDL_RenderCopy(aRenderer, gBackground, NULL, NULL);

	SDL_DestroyTexture(gBackground);
}

States ExitState::HandleEvent()
{
	States result;
	
	result = States::STATE_EXIT;
	SDL_Delay(2000);

	exit(0);
}