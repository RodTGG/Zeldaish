#include "stdafx.h"
#include "GamePlayState.h"


GamePlayState::GamePlayState()
{
	gName = "GamePlay";
	gPlayer = new Player("My Player", "Player.png");
	gHud = new ZeldaishHUD();
	gPlayer->setPlay(true);

	gPlayer->getMapNode()->AddMapNode(new MapNode("Stage 2", "brick.png"));
}


GamePlayState::~GamePlayState()
{
}

void GamePlayState::Setup()
{
	gMusic = ZeldaishFunctions::loadMusic("A Night Of Dizzy Spells.mp3");
	Mix_PlayMusic(gMusic, -1);
}

void GamePlayState::Display(SDL_Renderer* aRenderer)
{
	gPlayer->Display(aRenderer);
	gHud->Display(aRenderer, gPlayer);
}

void GamePlayState::Update()
{
	gHud->Update(gPlayer);

	if (gPlayer->getX() > 800) 
	{
		gPlayer->setMaptNode(gPlayer->getMapNode()->gNeighbor[0]);
		gPlayer->SetPosition(0, gPlayer->getY());
	}
}

States GamePlayState::HandleInput()
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