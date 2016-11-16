#include "stdafx.h"
#include "Projectile.h"


Projectile::Projectile(std::string aSFX) : ZeldaishObject("Projectile", "bullet.png")
{
	gImageArea->w = 20;
	gImageArea->h = 60;
	gSFX = ZeldaishFunctions::loadSFX(aSFX);
}


Projectile::~Projectile()
{
}

void Projectile::Display(SDL_Renderer* aRenderer)
{
	if (gFired)
	{
		if (gClip == NULL)
		{
			gTexture = ZeldaishFunctions::loadTexture(*aRenderer, gImagePath);
			SDL_RenderCopy(aRenderer, gTexture, NULL, gImageArea);
			SDL_DestroyTexture(gTexture);
		}
		else
		{
			gTexture = ZeldaishFunctions::loadTexture(*aRenderer, gImagePath);
			SDL_RenderCopy(aRenderer, gTexture, gClip, gImageArea);
			SDL_DestroyTexture(gTexture);
		}
	}
}

void Projectile::Update()
{
	if (getX() < 0 || getX() > 800 || getY() < 0 || getY() > 600)
	{
		gFired = false;
	}

	if (gFired)
	{
		FireProjectile(gCurrentDirection);
	}
}

bool Projectile::isFired()
{
	return gFired;
}

void Projectile::setFired(bool aState)
{
	if (aState == true)
	{
		Mix_PlayChannel(-1, gSFX, 0);
	}
	gFired = aState;
}

void Projectile::FireProjectile(Directions aDirection)
{
	switch (aDirection)
	{
	case DIRECTION_UP:
		gCurrentDirection = DIRECTION_UP;
		SetPosition(getX(), getY() - 10);
		break;
	case DIRECTION_DOWN:
		gCurrentDirection = DIRECTION_DOWN;
		SetPosition(getX(), getY() + 10);
		break;
	case DIRECTION_LEFT:
		gCurrentDirection = DIRECTION_LEFT;
		SetPosition(getX() - 10, getY());
		break;
	case DIRECTION_RIGHT:
		gCurrentDirection = DIRECTION_RIGHT;
		SetPosition(getX() + 10, getY());
		break;
	}
	std::this_thread::sleep_for(std::chrono::microseconds(50));
}