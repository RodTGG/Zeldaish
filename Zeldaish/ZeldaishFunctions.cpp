#include "stdafx.h"
#include "ZeldaishFunctions.h"


ZeldaishFunctions::ZeldaishFunctions()
{
}


ZeldaishFunctions::~ZeldaishFunctions()
{
}

bool ZeldaishFunctions::isOver(int& x, int& y, SDL_Rect& aArea) 
{
	bool result = false;

	if ((x > aArea.x) && (x < aArea.x + aArea.w) && (y > aArea.y) && (y < aArea.y + aArea.h))
	{
		result = true;
	}

	return result;
}

bool ZeldaishFunctions::leftMouseButtonClicked(SDL_Event* aEvent)
{
	bool result = false;

	if (aEvent->type == SDL_MOUSEBUTTONDOWN && aEvent->button.button == SDL_BUTTON_LEFT)
	{
		result = true;
	}

	return result;
}