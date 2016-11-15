#pragma once
#include "ZeldaishObject.h"
#include "ItemContainer.h"

class Character :
	public ZeldaishObject
{
public:
	Character(std::string aName, std::string aImgName);
	Character(std::string aName, std::string aImgName, bool aEnemy);
	Character(std::string aName, std::string aImgName, int aX,int aY,int aW,int aH);
	~Character();

	virtual void Move(Directions aDirection) = 0;
	virtual void Update();
	virtual void Update(Directions aDirection, Character* aCharacter) = 0;

	void Display(SDL_Renderer* aRender) override;
	int getSpeed();

	bool isAlive();
	bool isEnemy();

	Directions getDirection();
	ItemContainer* getInventory();
private:
protected:
	int gHp;
	bool gAlive;
	int gLevel;
	int gSpeed;
	bool gEnemy;
	Directions gCurrentDirection = DIRECTION_LEFT;

	ItemContainer* gInventory;
};

