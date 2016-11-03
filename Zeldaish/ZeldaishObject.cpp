#include "stdafx.h"
#include "ZeldaishObject.h"


ZeldaishObject::ZeldaishObject(std::string aName, std::string aImgName, int aX, int aY, int aW, int aH)
{
	std::string imagePath =  "Resources/" + aImgName;

	image = new SDL_Surface();
	imageArea = new SDL_Rect();

	image = IMG_Load(imagePath.c_str());
	imageArea->x = aX;
	imageArea->y = aY;
	imageArea->w = aW;
	imageArea->h = aH;
}


ZeldaishObject::~ZeldaishObject()
{
}

int ZeldaishObject::getX() 
{
	return imageArea->x;
}

int ZeldaishObject::getY()
{
	return imageArea->y;
}

int ZeldaishObject::getW()
{
	return imageArea->w;
}

int ZeldaishObject::getH()
{
	return imageArea->h;
}

void ZeldaishObject::setX(int aLocation)
{
	imageArea->x = aLocation;
}

void ZeldaishObject::setY(int aLocation)
{
	imageArea->y = aLocation;
}

void ZeldaishObject::setW(int aSize)
{
	imageArea->w = aSize;
}

void ZeldaishObject::setH(int aSize)
{
	imageArea->h = aSize;
}