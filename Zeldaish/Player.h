#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(std::string aName, std::string aImgName);
	~Player();
private:
	int gScore;
	int gSteps;
	int gLives;
	int gXP;
};

