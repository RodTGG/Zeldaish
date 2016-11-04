#include "stdafx.h"
#include "Button.h"


Button::Button(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : ZeldaishObject(aName, aImgName, aX, aY, aW, aH)
{
}

void Button::Display(SDL_Surface* aSurface)
{
	SDL_BlitScaled(gImage, NULL, aSurface, gImageArea);
}

Button::~Button()
{
}
