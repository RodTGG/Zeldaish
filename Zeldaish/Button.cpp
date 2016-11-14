#include "stdafx.h"
#include "Button.h"


Button::Button(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH) : ZeldaishObject(aName, aImgName, aX, aY, aW, aH)
{
}

void Button::Display(SDL_Renderer* aRenderer)
{
	gTexture = ZeldaishFunctions::loadTexture(*aRenderer, gImagePath);
	SDL_RenderCopy(aRenderer, gTexture, NULL, gImageArea);
	SDL_DestroyTexture(gTexture);
}

Button::~Button()
{
}
