#include "stdafx.h"
#include "ZeldaishFunctions.h"

bool ZeldaishFunctions::isOver(const SDL_Rect& aArea)
{
	int x, y;
	bool result = false;

	SDL_GetMouseState(&x, &y);

	if ((x > aArea.x) && (x < aArea.x + aArea.w) && (y > aArea.y) && (y < aArea.y + aArea.h))
	{
		result = true;
		std::cout << "Mouse is over" << std::endl;
	}

	return result;
}

bool ZeldaishFunctions::leftMouseButtonClicked(const SDL_Event& aEvent)
{
	bool result = false;

	if (aEvent.type == SDL_MOUSEBUTTONDOWN && aEvent.button.button == SDL_BUTTON_LEFT)
	{
		result = true;
		std::cout << "Mouse clicked" << std::endl;
	}

	return result;
}

bool ZeldaishFunctions::buttonDown(const SDL_Event& aEvent, SDL_Keycode aCode)
{
	bool result = false;

	if (aEvent.type == SDL_KEYDOWN && aEvent.key.keysym.sym == aCode)
	{
		std::cout << "Key Down" << std::endl;
		result = true;
	}
	else if (aEvent.type == SDL_KEYUP && aEvent.key.keysym.sym == aCode)
	{
		std::cout << "Key Up" << std::endl;
		result = false;
	}

	return result;
}

SDL_Texture* ZeldaishFunctions::loadTexture(SDL_Renderer& aRenderer, const std::string aPath)
{
	std::string fPath = "Resources/" + aPath;
	SDL_Texture* result = NULL;
	SDL_Surface* fSurface = IMG_Load(fPath.c_str());

	if (fSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", fPath.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		result = SDL_CreateTextureFromSurface(&aRenderer, fSurface);
		if (result == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", fPath.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(fSurface);
	}

	fSurface = nullptr;

	return result;
}

Mix_Music* ZeldaishFunctions::loadMusic(std::string aPath)
{
	std::string fPath = "Resources/Music/" + aPath;

	std::cout << "Attempting to load music " + aPath<< std::endl;
	Mix_Music* result = Mix_LoadMUS(fPath.c_str());
	if (result == NULL)
	{
		std::cout << "Unable to load music " + aPath << std::endl;
		std::cout << Mix_GetError() << std::endl;
	}
	else
	{
		std::cout << "Successfully loaded music "  + aPath<< std::endl;
	}

	return result;

}

bool ZeldaishFunctions::CollidedWith(ZeldaishObject& aSource, ZeldaishObject& aObject) 
{
	bool result = true;

	int aLeft = aSource.getX();
	int aRight = aSource.getX() + aSource.getW();
	int aTop = aSource.getY();
	int aBottom = aSource.getY() + aSource.getH();

	int bLeft = aObject.getX();
	int bRight = aObject.getX() + aObject.getW();
	int bTop = aObject.getY();
	int bBottom = aObject.getY() + aObject.getH();

	if (aLeft >= bRight) 
	{
		result = false;
	}
	if (aRight <= bLeft)
	{
		result = false;
	}
	if (aBottom <= bTop)
	{
		result = false;
	}
	if (aTop >= bBottom)
	{
		result = false;
	}

	if (result == true) 
	{
		std::cout << aSource.getName() + " collided with " + aObject.getName() << std::endl;
	}

	return result;
}

Directions ZeldaishFunctions::MoveTowards(ZeldaishObject& aSource, ZeldaishObject& aObject)
{
	Directions result;

	if (aSource.getX() > aObject.getX()) 
	{
		result = DIRECTION_LEFT;
	}
	if (aSource.getX() < aObject.getX())
	{
		result = DIRECTION_RIGHT;
	}
	if (aSource.getY() > aObject.getY())
	{
		result = DIRECTION_UP;
	}
	if (aSource.getY() < aObject.getY())
	{
		result = DIRECTION_DOWN;
	}

	return result;
}