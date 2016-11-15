#include "stdafx.h"
#include "ZeldaishHUD.h"


ZeldaishHUD::ZeldaishHUD() : ZeldaishObject("HUD", "HUD.png")
{
	gImageArea->x = 0;
	gImageArea->y = 530;
	gImageArea->w = 800;
	gImageArea->h = 70;

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
	switch (aPlayer->getLives())
	{
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
	int fOffset = 600;

	gTexture = ZeldaishFunctions::loadTexture(*aRender, gImagePath);
	SDL_RenderCopy(aRender, gTexture, gClip, gImageArea);
	SDL_DestroyTexture(gTexture);

	aPlayer->getInventory()->ItemList()[0]->SetPosition(11, 550);
	aPlayer->getInventory()->ItemList()[0]->Display(aRender);

	for (unsigned int i = 0; i < 3; i++)
	{
		gHearts[i]->SetPosition(fOffset, 545);
		gHearts[i]->Display(aRender);
		fOffset += 55;
	}
}