#pragma once
#include "ZeldaishObject.h"
#include "ItemContainer.h"

class Character :
	public ZeldaishObject
{
public:
	Character(std::string aName, std::string aImgName);
	Character(std::string aName, std::string aImgName, int aX,int aY,int aW,int aH);
	~Character();

	int getSpeed();
	ItemContainer* getInventory();
private:
protected:
	int gHp;
	bool gAlive;
	int gLevel;
	int gSpeed;

	ItemContainer* gInventory;
};

