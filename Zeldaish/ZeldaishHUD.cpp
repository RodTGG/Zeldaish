#include "stdafx.h"
#include "ZeldaishHUD.h"


ZeldaishHUD::ZeldaishHUD() : ZeldaishObject("HUD", "HUD.png")
{
	gImageArea->x = 0;
	gImageArea->y = 530;
	gImageArea->w = 800;
	gImageArea->h = 70;

	// Sets up hearts
	for (unsigned int i = 0; i < 3; i++)
	{
		gHearts[i] = new ZeldaishObject("Heart" + i, "heart.png");
		gHearts[i]->getRectangle()->w = 50;
		gHearts[i]->getRectangle()->h = 50;
	}
}


ZeldaishHUD::~ZeldaishHUD()
{
}

void ZeldaishHUD::Update(Player* aPlayer)
{
	// Updates UI based on player lives
	switch (aPlayer->getLives())
	{
	case 0:
		gHearts[0]->setImagePath("emptyheart.png");
		gHearts[1]->setImagePath("emptyheart.png");
		gHearts[2]->setImagePath("emptyheart.png");
		break;
	case 1:
		gHearts[0]->setImagePath("heart.png");
		gHearts[1]->setImagePath("emptyheart.png");
		gHearts[2]->setImagePath("emptyheart.png");
		break;
	case 2:
		gHearts[0]->setImagePath("heart.png");
		gHearts[1]->setImagePath("heart.png");
		gHearts[2]->setImagePath("emptyheart.png");
		break;
	case 3:
		gHearts[0]->setImagePath("heart.png");
		gHearts[1]->setImagePath("heart.png");
		gHearts[2]->setImagePath("heart.png");
		break;
	}
}

void ZeldaishHUD::Display(SDL_Renderer* aRender, Player* aPlayer)
{
	// Heart offset
	int fHOffset = 600;
	// Item offset
	int fIOffset = 11;

	// Main Texture
	gTexture = ZeldaishFunctions::loadTexture(*aRender, gImagePath);
	SDL_RenderCopy(aRender, gTexture, gClip, gImageArea);
	SDL_DestroyTexture(gTexture);

	// First four items in player inventory
	for (unsigned int i = 0; i < aPlayer->getInventory()->ItemList().size(); i++)
	{
		if (i < 4)
		{
			if (aPlayer->getInventory()->ItemList()[i] != NULL)
			{
				aPlayer->getInventory()->ItemList()[i]->SetPosition(fIOffset, 550);
				aPlayer->getInventory()->ItemList()[i]->Display(aRender);
				fIOffset += 60;
			}
		}
	}

	// Hearts
	for (unsigned int i = 0; i < 3; i++)
	{
		gHearts[i]->SetPosition(fHOffset, 545);
		gHearts[i]->Display(aRender);
		fHOffset += 55;
	}
}