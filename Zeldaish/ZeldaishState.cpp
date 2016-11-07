#include "stdafx.h"
#include "ZeldaishState.h"


ZeldaishState::ZeldaishState()
{
	e = new SDL_Event();
	gBackground = NULL;
}

ZeldaishState::ZeldaishState(States aID)
{
	gId = aID;
}


ZeldaishState::~ZeldaishState()
{
}

std::string ZeldaishState::getName()
{
	return gName;
}

States ZeldaishState::getID()
{
	return gId;
}