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
	// Cheks if image path is null
	if (image == NULL) 
	{
		Error::Display( name + " ,Unable to load SDL Surface");
	}
	else 
	{
		SDL_BlitScaled(image, NULL, aSurface, imageArea);
	}
}

Button::~Button()
{
	delete image;
	delete imageArea;
}
