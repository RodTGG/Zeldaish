#include "stdafx.h"
#include "Button.h"


Button::Button(std::string aName,std::string aPath, int aX, int aY, int aW, int aH)
{
	name = aName;
	image = IMG_Load(aPath.c_str());
	imageArea->x = aX;
	imageArea->y = aY;
	imageArea->w = aW;
	imageArea->h = aH;
}

void Button::Display(SDL_Surface* aSurface) 
{
	if (image == NULL) 
	{
		Error::Display( name + " ,Unable to load SDL Surface");
	}
	SDL_BlitScaled(image, NULL, aSurface, imageArea);
}

Button::~Button()
{
}
