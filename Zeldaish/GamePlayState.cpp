#include "stdafx.h"
#include "GamePlayState.h"


GamePlayState::GamePlayState()
{
	gName = "GamePlay";
}


GamePlayState::~GamePlayState()
{
}

void GamePlayState::Display(SDL_Renderer* aRenderer) 
{
	gPlayer->Display(aRenderer);
}

void GamePlayState::Update() 
{

}

void GamePlayState::Load(SDL_Renderer* aRenderer)
{
}

States GamePlayState::HandleEvent(SDL_Renderer* aRenderer)
{
	States result = STATE_MAINMENU;
	bool selected = false;

	do {
		while (SDL_PollEvent(e) != 0)
		{
			if (e->type == SDL_QUIT)
			{
				result = STATE_EXIT;
				selected = true;
			}
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	} while (!selected);

	return result;
}