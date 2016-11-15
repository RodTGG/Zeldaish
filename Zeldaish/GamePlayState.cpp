#include "stdafx.h"
#include "GamePlayState.h"


GamePlayState::GamePlayState()
{
	gName = "GamePlay";
	gPlayer = new Player("My Player", "Player.png");
	gHud = new ZeldaishHUD();
	gPlayer->setPlay(true);
}


GamePlayState::~GamePlayState()
{
}

void GamePlayState::Display(SDL_Renderer* aRenderer)
{
	gBackground = ZeldaishFunctions::loadTexture(*aRenderer, "ground.png");
	SDL_RenderCopy(aRenderer, gBackground, NULL, NULL);
	gPlayer->Display(aRenderer);
	gHud->Display(aRenderer, gPlayer);
	//Clear memory
	SDL_DestroyTexture(gBackground);
}

void GamePlayState::Update()
{
	gHud->Update(gPlayer);
}

States GamePlayState::HandleInput()
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
				gPlayer->setPlay(false);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_w))
			{
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() - gPlayer->getSpeed());
				gPlayer->SetAnimation(2);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_a))
			{
				gPlayer->SetPosition(gPlayer->getX() - gPlayer->getSpeed(), gPlayer->getY());
				gPlayer->SetAnimation(3);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_s))
			{
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() + gPlayer->getSpeed());
				gPlayer->SetAnimation(1);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_d))
			{
				gPlayer->SetPosition(gPlayer->getX() + gPlayer->getSpeed(), gPlayer->getY());
				gPlayer->SetAnimation(4);
			}
			else
			{
				gPlayer->SetAnimation(0);
			}
		}
	} while (!selected);

	return result;
}

States GamePlayState::HandleEvent(SDL_Renderer* aRenderer)
{
	States result = STATE_MAINMENU;

	std::thread animthread(&Player::PlayAnimation, gPlayer);
	result = HandleInput();
	animthread.join();

	return result;
}