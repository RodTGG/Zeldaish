#include "stdafx.h"
#include "ZeldaishFunctions.h"


ZeldaishFunctions::ZeldaishFunctions()
{
}


ZeldaishFunctions::~ZeldaishFunctions()
{
}

bool ZeldaishFunctions::isOver(SDL_Rect& aArea) 
{
	int x, y;
	bool result = false;

	SDL_GetMouseState(&x, &y);

	if ((x > aArea.x) && (x < aArea.x + aArea.w) && (y > aArea.y) && (y < aArea.y + aArea.h))
	{
		result = true;
	}

	return result;
}

bool ZeldaishFunctions::leftMouseButtonClicked(SDL_Event& aEvent)
{
	bool result = false;

	if (aEvent.type == SDL_MOUSEBUTTONDOWN && aEvent.button.button == SDL_BUTTON_LEFT)
	{
		result = true;
	}

	return result;
}

SDL_Texture* ZeldaishFunctions::loadTexture(SDL_Renderer& aRenderer,std::string aPath) 
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

	return result;
}