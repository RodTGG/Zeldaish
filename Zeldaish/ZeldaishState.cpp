#include "stdafx.h"
#include "ZeldaishState.h"


ZeldaishState::ZeldaishState()
{
	e = new SDL_Event();
	gFunctions = new ZeldaishFunctions();
}

ZeldaishState::ZeldaishState(States aID)
{
	gId = aID;
}


ZeldaishState::~ZeldaishState()
{
}

States ZeldaishState::getID()
{
	return gId;
}