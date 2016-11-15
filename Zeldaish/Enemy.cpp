#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(std::string aName, std::string aImgName) : Character(aName, aImgName)
{
	gEnemy = true;
	gSpeed += gLevel;
}

Enemy::Enemy(std::string aName, std::string aImgName, int aLevel) : Character(aName, aImgName)
{
	gLevel = aLevel;
	gEnemy = true;
	gSpeed += gLevel;
}


Enemy::~Enemy()
{
}

void Enemy::Update(Directions aDirection ,Character* aCharacter) 
{
	gCurrentDirection = aDirection;

	if (aDirection == DIRECTION_PLAYER)
	{
		gCurrentDirection = ZeldaishFunctions::MoveTowards(*this, *aCharacter);
	}

	Move(gCurrentDirection);
}

void Enemy::Move(Directions aDirection) 
{
	switch (aDirection)
	{
	case DIRECTION_UP:
		gCurrentDirection = DIRECTION_UP;
		SetPosition(getX(), getY() - gSpeed);
		break;
	case DIRECTION_DOWN:
		gCurrentDirection = DIRECTION_DOWN;
		SetPosition(getX(), getY() + gSpeed);
		break;
	case DIRECTION_LEFT:
		gCurrentDirection = DIRECTION_LEFT;
		SetPosition(getX() - gSpeed, getY());
		break;
	case DIRECTION_RIGHT:
		gCurrentDirection = DIRECTION_RIGHT;
		SetPosition(getX() + gSpeed, getY());
		break;
	}
}