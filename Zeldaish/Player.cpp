#include "stdafx.h"
#include "Player.h"


Player::Player(std::string aName, std::string aImgName) : Character(aName, aImgName)
{
	gScore = 0;
	gSteps = 0;
	gLives = 3;
	gXP = 0;
}


Player::~Player()
{
}
