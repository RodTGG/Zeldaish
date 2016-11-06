#include "stdafx.h"
#include "ZeldaishObject.h"


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


ZeldaishObject::~ZeldaishObject()
{
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

void ZeldaishObject::setX(int aLocation)
{
	gImageArea->x = aLocation;
}

void ZeldaishObject::setY(int aLocation)
{
	gImageArea->y = aLocation;
}

void ZeldaishObject::setW(int aSize)
{
	gImageArea->w = aSize;
}

void ZeldaishObject::setH(int aSize)
{
	gImageArea->h = aSize;
}