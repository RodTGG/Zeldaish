#include "stdafx.h"
#include "Player.h"


Player::Player(std::string aName, std::string aImgName) : Character(aName, aImgName)
{
	gScore = 0;
	gSteps = 0;
	gLives = 3;
	gXP = 0;

	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 50;
	gImageArea->h = 60;

	gClips[0].x = 22;
	gClips[0].y = 97;
	gClips[0].w = 357;
	gClips[0].h = 456;
}


Player::~Player()
{
}


void Player::Display(SDL_Renderer* aRenderer)
{
	gTexture = ZeldaishFunctions::loadTexture(*aRenderer,gImagePath);
	//SDL_RenderCopy(aRenderer, gTexture, NULL, gImageArea);
	if (gClips != NULL) 
	{
		SDL_RenderCopy(aRenderer, gTexture, &gClips[0], gImageArea);
	}

	SDL_DestroyTexture(gTexture);
}