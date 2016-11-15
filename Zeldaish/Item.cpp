#include "stdafx.h"
#include "Item.h"

Item::Item(std::string aName, std::string aImgName) : ZeldaishObject(aName, aImgName)
{
	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 40;
	gImageArea->h = 40;
}

Item::Item(std::string aName, std::string aImgName, SDL_Rect* aRect) : ZeldaishObject(aName, aImgName)
{
	gClip = aRect;
	gImageArea->x = 0;
	gImageArea->y = 0;
	gImageArea->w = 40;
	gImageArea->h = 40;
}


Item::~Item()
{
}
