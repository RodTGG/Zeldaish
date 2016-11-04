#include "stdafx.h"
#include "ZeldaishState.h"


ZeldaishState::ZeldaishState()
{
	zFunctions = new ZeldaishFunctions();
}

ZeldaishState::ZeldaishState(States aID)
{
	id = aID;
}


ZeldaishState::~ZeldaishState()
{
}

States ZeldaishState::getID()
{
	return id;
}