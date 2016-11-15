#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
	gId = STATE_DEAD;
	gName = "Dead State";
	btnMenu = new Button("btnBack", "btn_back.png", 0, 500, 150, 100);
}


DeadState::~DeadState()
{
}

void DeadState::Setup()
{
	gMusic = ZeldaishFunctions::loadMusic("All of Us.mp3");
	Mix_PlayMusic(gMusic, -1);
}

void DeadState::Display(SDL_Renderer* aRenderer)
{
	gBackground = ZeldaishFunctions::loadTexture(*aRenderer, "gameOver.png");
	SDL_RenderCopy(aRenderer, gBackground, NULL, NULL);
	//Clear memory
	SDL_DestroyTexture(gBackground);
	btnMenu->Display(aRenderer);
}

States DeadState::HandleEvent(SDL_Renderer* aRenderer)
{
	States result = STATE_MAINMENU;
	bool selected = false;


	Setup();
	do {
		while (SDL_PollEvent(e) != 0)
		{
			if (e->type == SDL_QUIT)
			{
				result = STATE_EXIT;
				selected = true;
			}
			else
			{
				if (ZeldaishFunctions::leftMouseButtonClicked(*e) && ZeldaishFunctions::isOver(*btnMenu->getRectangle()))
				{
					result = STATE_MAINMENU;
					selected = true;
				}
			}
			std::this_thread::sleep_for(std::chrono::microseconds(20));
		}
	} while (!selected);

	return result;
}