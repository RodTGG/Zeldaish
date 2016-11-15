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

void GamePlayState::Setup()
{
	gMusic = ZeldaishFunctions::loadMusic("A Night Of Dizzy Spells.mp3");
	Mix_PlayMusic(gMusic, -1);

	std::cout << "Setting up Map" << std::endl;
	// adjacency list
	gPlayer->getMapNode()->AddMapNode("right", new MapNode("Stage 2", "brick.png"));
	gPlayer->getMapNode()->AddMapNode("left", new MapNode("Stage 3", "weird.png"));
	gPlayer->getMapNode()->gNeighbor["right"]->AddMapNode("left", gPlayer->getMapNode());
	gPlayer->getMapNode()->gNeighbor["right"]->AddMapNode("top", new MapNode("Stage 3", "stone.png"));

	// Characters
	gPlayer->SetPosition(400, 510);
	gPlayer->getMapNode()->gCharacters->AddCharacter(new Enemy("mage", "mage.png"));
	gPlayer->getMapNode()->gCharacters->CharacterList()[0]->SetPosition(400, 50);
	gPlayer->getMapNode()->gCharacters->AddCharacter(new Enemy("mage1", "mage.png"));
	gPlayer->getMapNode()->gCharacters->CharacterList()[1]->SetPosition(300, 50);
	gPlayer->getMapNode()->gCharacters->AddCharacter(new Enemy("mage2", "mage.png"));
	gPlayer->getMapNode()->gCharacters->CharacterList()[2]->SetPosition(600, 50);
	gPlayer->getMapNode()->gNeighbor["left"]->gCharacters->AddCharacter((new Enemy("chief", "chief.png", 5)));
	gPlayer->getMapNode()->gNeighbor["right"]->gCharacters->AddCharacter((new Enemy("dova", "dovakin.png", 1)));


	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->AddCharacter((new Enemy("dova1", "dovakin.png", 1)));
	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->AddCharacter((new Enemy("mage4", "mage.png", 1)));
	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->AddCharacter((new Enemy("chief2", "chief.png", 1)));

	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->CharacterList()[0]->SetPosition(300, 50);
	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->CharacterList()[1]->SetPosition(400, 50);
	gPlayer->getMapNode()->gNeighbor["right"]->gNeighbor["top"]->gCharacters->CharacterList()[2]->SetPosition(500, 50);
}

void GamePlayState::Display(SDL_Renderer* aRenderer)
{
	gPlayer->Display(aRenderer);
	gHud->Display(aRenderer, gPlayer);
}

void GamePlayState::UpdateEnemies()
{
	// iterate enemies
	for (unsigned int i = 0; i < gPlayer->getMapNode()->gCharacters->CharacterList().size(); i++) 
	{
		// Direct enemies towards player
		if (gPlayer->getMapNode()->gCharacters->CharacterList()[i]->isEnemy()) 
		{
			gPlayer->getMapNode()->gCharacters->CharacterList()[i]->Update(DIRECTION_PLAYER, gPlayer);

			// Sleep thread for enemy movement speed
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}

void GamePlayState::CheckCollision()
{
	// Check collision with characters
	for (unsigned int i = 0; i < gPlayer->getMapNode()->gCharacters->CharacterList().size(); i++)
	{
		// checks collision
		if (ZeldaishFunctions::CollidedWith(*gPlayer, *gPlayer->getMapNode()->gCharacters->CharacterList()[i]) && gPlayer->getMapNode()->gCharacters->CharacterList()[i]->isAlive())
		{
			// checks direction of collision for bounce off
			switch (gPlayer->getDirection())
			{
			case DIRECTION_UP:
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() + 70);
				break;
			case DIRECTION_DOWN:
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() - 70);
				break;
			case DIRECTION_LEFT:
				gPlayer->SetPosition(gPlayer->getX() + 70, gPlayer->getY());
				break;
			case DIRECTION_RIGHT:
				gPlayer->SetPosition(gPlayer->getX() - 70, gPlayer->getY());
				break;
			}

			// Checks if enemy
			if (gPlayer->getMapNode()->gCharacters->CharacterList()[i]->isEnemy()) 
			{
				gPlayer->setLives(gPlayer->getLives() - 1);
			}
		}
	}

	// Check collision with items
	for (unsigned int i = 0; i < gPlayer->getMapNode()->gItems->ItemList().size(); i++)
	{
		// checks collision
		if (ZeldaishFunctions::CollidedWith(*gPlayer, *gPlayer->getMapNode()->gItems->ItemList()[i]))
		{
			// checks direction of collision for bounce off
			switch (gPlayer->getDirection())
			{
			case DIRECTION_UP:
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() + 10);
				break;
			case DIRECTION_DOWN:
				gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() - 10);
				break;
			case DIRECTION_LEFT:
				gPlayer->SetPosition(gPlayer->getX() + 10, gPlayer->getY());
				break;
			case DIRECTION_RIGHT:
				gPlayer->SetPosition(gPlayer->getX() - 10, gPlayer->getY());
				break;
			}
		}
	}

	// Right side collision
	if (gPlayer->getX() + gPlayer->getW() > 800 && gPlayer->getMapNode()->HasNeighbor("right"))
	{
		gPlayer->setMaptNode(gPlayer->getMapNode()->gNeighbor["right"]);
		gPlayer->SetPosition(0, gPlayer->getY());
	}
	else if (gPlayer->getX() + gPlayer->getW() > 800 && !gPlayer->getMapNode()->HasNeighbor("right"))
	{
		gPlayer->SetPosition(gPlayer->getX() - gPlayer->getW(), gPlayer->getY());
	}

	// Left side Collision
	if (gPlayer->getX() < 0 && gPlayer->getMapNode()->HasNeighbor("left"))
	{
		gPlayer->setMaptNode(gPlayer->getMapNode()->gNeighbor["left"]);
		gPlayer->SetPosition(800 - gPlayer->getW(), gPlayer->getY());
	}
	else if (gPlayer->getX() < 0 && !gPlayer->getMapNode()->HasNeighbor("left"))
	{
		gPlayer->SetPosition(gPlayer->getX() + gPlayer->getW(), gPlayer->getY());
	}

	// Top side collision
	if (gPlayer->getY() < 0 && gPlayer->getMapNode()->HasNeighbor("top"))
	{
		gPlayer->setMaptNode(gPlayer->getMapNode()->gNeighbor["top"]);
		gPlayer->SetPosition(gPlayer->getX(), 530 - gPlayer->getH());
	}
	else if (gPlayer->getY() < 0 && !gPlayer->getMapNode()->HasNeighbor("top"))
	{
		gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() + gPlayer->getH());
	}

	// Botoom side collision HUD included
	if (gPlayer->getY() + gPlayer->getH() > 530 && gPlayer->getMapNode()->HasNeighbor("bottom"))
	{
		gPlayer->setMaptNode(gPlayer->getMapNode()->gNeighbor["bottom"]);
		gPlayer->SetPosition(gPlayer->getX(), 0);
	}
	else if (gPlayer->getY() + gPlayer->getH() > 530 && !gPlayer->getMapNode()->HasNeighbor("bottom"))
	{
		gPlayer->SetPosition(gPlayer->getX(), gPlayer->getY() - gPlayer->getH());
	}
}

void GamePlayState::Update()
{
	gHud->Update(gPlayer);
	UpdateEnemies();
	CheckCollision();

	if (gPlayer->getLives() <= 0) 
	{
		gPlayer->setAlive(false);
	}
}

States GamePlayState::HandleInput()
{
	States result = STATE_MAINMENU;
	bool selected = false;

	Setup();

	do {
		if (!gPlayer->isAlive()) 
		{
			result = STATE_DEAD;
			selected = true;
			gPlayer->setPlay(false);
		}

		while (SDL_PollEvent(e) != 0)
		{
			if (e->type == SDL_QUIT)
			{
				result = STATE_EXIT;
				selected = true;
				gPlayer->setPlay(false);
			}
			if (ZeldaishFunctions::buttonDown(*e, SDLK_w))
			{
				gPlayer->Move(DIRECTION_UP);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_a))
			{
				gPlayer->Move(DIRECTION_LEFT);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_s))
			{
				gPlayer->Move(DIRECTION_DOWN);
			}
			else if (ZeldaishFunctions::buttonDown(*e, SDLK_d))
			{
				gPlayer->Move(DIRECTION_RIGHT);
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