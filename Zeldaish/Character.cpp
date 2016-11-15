#include "stdafx.h"
#include "Character.h"


Character::Character(std::string aName, std::string aImgName) : ZeldaishObject(aName, aImgName)
{
	gHp = 100;
	gAlive = true;
	gSpeed = 2;
	gInventory = new ItemContainer();
	gLevel = 1;
	gEnemy = false;

	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 50;
	gImageArea->h = 60;
}

Character::Character(std::string aName, std::string aImgName, bool aEnemy) : ZeldaishObject(aName, aImgName)
{
	gHp = 100;
	gAlive = true;
	gSpeed = 2;
	gInventory = new ItemContainer();
	gLevel = 1;
	gEnemy = aEnemy;

	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 50;
	gImageArea->h = 60;
}

Character::Character(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : ZeldaishObject(aName, aImgName, aX, aY, aW, aH)
{
	gHp = 100;
	gAlive = true;
	gSpeed = 2;
	gInventory = new ItemContainer();
	gLevel = 1;
	gEnemy = false;

	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 50;
	gImageArea->h = 60;
}

Character::~Character()
{
}


void Character::Display(SDL_Renderer* aRender) 
{
	if (gAlive) 
	{
		if (gClip == NULL)
		{
			gTexture = ZeldaishFunctions::loadTexture(*aRender, gImagePath);
			SDL_RenderCopy(aRender, gTexture, NULL, gImageArea);
			SDL_DestroyTexture(gTexture);
		}
		else
		{
			gTexture = ZeldaishFunctions::loadTexture(*aRender, gImagePath);
			SDL_RenderCopy(aRender, gTexture, gClip, gImageArea);
			SDL_DestroyTexture(gTexture);
		}
	}
}

int Character::getSpeed() 
{
	return gSpeed;
}

ItemContainer* Character::getInventory() 
{
	return gInventory;
}

bool Character::isAlive() 
{
	return gAlive;
}

Directions Character::getDirection() 
{
	return gCurrentDirection;
}

bool Character::isEnemy() 
{
	return gEnemy;
}

void Character::Update() 
{
	Move(gCurrentDirection);
}

void Character::setAlive(bool aState) 
{
	gAlive = aState;
}