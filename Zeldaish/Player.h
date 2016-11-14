#pragma once
#include "Character.h"
class Player :
	public Character
{
public:
	Player(std::string aName, std::string aImgName);
	~Player();

	void Display(SDL_Renderer* aRenderer) override;
private:
	int gScore;
	int gSteps;
	int gLives;
	int gXP;

	SDL_Rect gClips[16];
};

