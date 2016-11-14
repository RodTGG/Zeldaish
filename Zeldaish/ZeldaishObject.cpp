#include "stdafx.h"
#include "ZeldaishObject.h"

ZeldaishObject::ZeldaishObject(std::string aName, std::string aImgName)
{
	gImagePath = aImgName;
	gImageArea = new SDL_Rect();
	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 0;
	gImageArea->h = 0;
}

ZeldaishObject::ZeldaishObject(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH)
{
	gImagePath =  aImgName;
	gImageArea = new SDL_Rect();
	gImageArea->x = aX;
	gImageArea->y = aY;
	gImageArea->w = aW;
	gImageArea->h = aH;
	gTexture = NULL;
}

void ZeldaishObject::Display(SDL_Renderer* aRenderer) 
{
	SDL_RenderCopy(aRenderer, gTexture, NULL, gImageArea);
}

ZeldaishObject::~ZeldaishObject()
{
}

std::string ZeldaishObject::getName() 
{
	return gName;
}

SDL_Rect ZeldaishObject::getRectangle() 
{
	return *gImageArea;
}

int ZeldaishObject::getX() 
{
	return gImageArea->x;
}

int ZeldaishObject::getY()
{
	return gImageArea->y;
}

int ZeldaishObject::getW()
{
	return gImageArea->w;
}

int ZeldaishObject::getH()
{
	return gImageArea->h;
}

SDL_Texture* ZeldaishObject::getTexture() 
{
	return gTexture;
}

void ZeldaishObject::SetPosition(int aX, int aY) 
{
	gImageArea->x = aX;
	gImageArea->y = aY;
}