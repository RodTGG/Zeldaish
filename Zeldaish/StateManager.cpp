#include "stdafx.h"
#include "StateManager.h"
#include "MainMenuState.h"


StateManager::StateManager()
{
	currentSate = new MainMenuState();
}

StateManager::~StateManager()
{
}

void StateManager::setNextState(States aState) 
{
	switch (aState)
	{
	case States::STATE_MAINMENU:
		nextState = new MainMenuState();
		break;
	case States::STATE_ABOUT:
		break;
	case States::STATE_HELP:
		break;
	case States::STATE_GAMEPLAY:
		break;
	case States::STATE_EXIT:
		break;
	default:
		nextState = new MainMenuState();
		break;
	}
}

void StateManager::changeState() 
{
	currentSate = nextState;
}

ZeldaishState* StateManager::getCurrentSate()
{
	return currentSate;
}