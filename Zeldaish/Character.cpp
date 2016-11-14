#include "stdafx.h"
#include "Character.h"


Character::Character(std::string aName, std::string aImgName) : ZeldaishObject(aName, aImgName)
{
	gHp = 100;
	gAlive = true;
	gSpeed = 2;
	gInventory = new ItemContainer();
	gLevel = 1;
}

Character::Character(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : ZeldaishObject(aName, aImgName, aX, aY, aW, aH)
{
	gHp = 100;
	gAlive = true;
	gSpeed = 2;
	gInventory = new ItemContainer();
	gLevel = 1;
}

Character::~Character()
{
}

int Character::getSpeed() 
{
	return gSpeed;
}

ItemContainer* Character::getInventory() 
{
	return gInventory;
}